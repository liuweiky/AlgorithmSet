/**
Lowest Common Ancestors

N = 8
M(QUERY) = 6
INORDER: 7 2 3 4 6 5 1 8
PREORDER: 5 3 7 2 6 4 8 1

INPUT:
6 8
7 2 3 4 6 5 1 8
5 3 7 2 6 4 8 1
2 4
1 2
4 6
7 5
3 8
1 4

OUTPUT:
3 5 6 5 5 5

*/

#include <cstdio>
#include <vector>

#define MAX_N 1024

using namespace std;

struct node
{
    int data;
    node* lc;
    node* rc;

    node() {lc = rc = NULL;}
};

int preorder[MAX_N];
int inorder[MAX_N];

node* LCA(node* r, int a, int b)
{
    if (r == NULL)
        return NULL;

    if (r->data == a || r->data == b)
        return r;
    node* lc = LCA(r->lc, a, b);
    node* rc = LCA(r->rc, a, b);

    if (lc != NULL && rc != NULL)
        return r;
    else if (lc == NULL)
        return rc;
    else
        return lc;
}

node* create(int pl, int pr, int il, int ir)
{
    if (pl > pr || il > ir)
        return NULL;

    node* r = new node;
    r->data = preorder[pl];

    int k;

    for (int i = il; i <= ir; i++)
        if (inorder[i] == r->data)
        {
            k = i;
            break;
        }

    r->lc = create(pl + 1, pl + k - il, il, k - 1);
    r->rc = create(pl + k - il + 1, pr, k + 1, ir);
    return r;
}

int main()
{
    int N, M;
    scanf("%d %d", &M, &N);

    for (int i = 1; i <= N; i++)
        scanf("%d", &inorder[i]);

    for (int i = 1; i <= N; i++)
        scanf("%d", &preorder[i]);

    node* root = create(1, N, 1, N);

    while (M--)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        node* r = LCA(root, a, b);
        if (r == NULL)
            printf("NULL\n");
        else
            printf("%d\n", r->data);
    }

    return 0;
}
