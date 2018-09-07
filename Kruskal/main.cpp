#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_N 10

using namespace std;

struct Edge
{
    int s, t, cost;
    Edge() {}
    Edge(int a, int b, int c): s(a), t(b), cost(c) {}
};

int M;
vector<Edge*> edges;

int father[MAX_N + 1];

bool cmp(Edge* e1, Edge* e2)
{
    return e1->cost < e2->cost;
}

int GetFather(int a)
{
    int b = a;
    while (a != father[a])
        a = father[a];
    while (b != a)
    {
        int t = father[b];
        father[b] = a;
        b = t;
    }
    return a;
}

void Union(int a, int b)
{
    if (GetFather(a) != GetFather(b))
        father[GetFather(a)] = GetFather(b);
}

int main()
{
    for (int i = 0; i < MAX_N; i++)
        father[i] = i;
    int n;
    printf("Enter the vertex num: ");
    scanf("%d", &n);
    printf("Enter the total edges: ");
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        int s, t, c;
        scanf("%d %d %d", &s, &t, &c);
        edges.push_back(new Edge(s, t, c));
    }
    sort(edges.begin(), edges.end(), cmp);

    int min_cost = 0;
    int cnt = 0;

    for (int i = 0; i < M - 1; i++)
    {
        Edge* e = edges[i];
        int s = e->s;
        int t = e->t;
        if (GetFather(s) != GetFather(t))
        {
            min_cost += e->cost;
            Union(s, t);
            cnt++;
        }
        if (cnt == n-1)
            break;
    }

    printf("min cost: %d\n", min_cost);

    return 0;
}
