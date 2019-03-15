/**
Huffman Coding

N = 5
Array = [1, 2, 3, 4, 5]

5
1 2 3 4 5

*/

#include <cstdio>
#include <queue>
#include <vector>
#include <utility>

#define MAX_N 16

using namespace std;

struct node
{
    int w;
    node* l;
    node* r;
    node () {l = r = NULL; w = 0;}
};

struct cmp
{
    bool operator() (node* n1, node* n2)
    {
        return n1->w > n2->w;
    }
};

priority_queue<node*, vector<node*>, cmp > q;
int N;

void bfs(node* r)
{
    queue<pair<node*, int> > q;
    q.push(pair<node*, int> (r, 1));

    int level = 1;

    while (!q.empty())
    {
        pair<node*, int> p = q.front();
        q.pop();
        if (level != p.second)
        {
            level++;
            printf("\n");
        }
        printf("%d ", p.first->w);
        if (p.first->l != NULL)
            q.push(pair<node*, int> (p.first->l, p.second + 1));
        if (p.first->r != NULL)
            q.push(pair<node*, int> (p.first->r, p.second + 1));
    }
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        node* n = new node;
        scanf("%d", &n->w);
        q.push(n);
    }

    while (q.size() != 1)
    {
        node* a = q.top();
        q.pop();
        node* b = q.top();
        q.pop();
        node* n = new node;
        n->w = a->w + b->w;
        n->l = a;
        n->r = b;
        q.push(n);
    }

    printf("%d\n", q.top()->w);

    bfs(q.top());

    return 0;
}
