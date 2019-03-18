#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

#define MAX_N 512

using namespace std;

struct edge
{
    int s, t, d;
    edge(int _s, int _t, int _d): s(_s), t(_t), d(_d) {}
};

struct prio_qnode
{
    int s, d;
    prio_qnode(int _s, int _d): s(_s), d(_d) {}
    bool operator < (const prio_qnode& rhs) const
    {
        return d > rhs.d;
    }
};

vector<edge> edges;
vector<int> graph[MAX_N];
bool vis[MAX_N];
int dis[MAX_N];
vector<int> paths[MAX_N];

int N, M;

void add_edge(int s, int t, int d)
{
    edge e(s, t, d);
    edges.push_back(e);
    graph[s].push_back(edges.size() - 1);
}

void dijkstra(int s)
{
    fill_n(vis, MAX_N, false);
    fill_n(dis, MAX_N, INT_MAX);
    dis[s] = 0;

    priority_queue<prio_qnode> q;

    q.push(prio_qnode(s, 0));

    while (!q.empty())
    {
        prio_qnode n = q.top();
        q.pop();

        int u = n.s;

        if (vis[u])
            continue;
        vis[u] = true;

        for (int i = 0; i < graph[u].size(); i++)
        {
            edge& e = edges[graph[u][i]];
            int v = e.t;
            if (dis[v] > dis[u] + e.d)
            {
                dis[v] = dis[u] + e.d;
                paths[v].clear();
                paths[v].push_back(u);
                q.push(prio_qnode(v, dis[v]));
            }
            else if (dis[v] == dis[u] + e.d)
                paths[v].push_back(u);
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        int s, t, d;
        scanf("%d %d %d", &s, &t, &d);
        add_edge(s, t, d);
    }

    dijkstra(1);

    for (int i = 1; i <= N; i++)
    {
        printf("%d: %d\n", i, dis[i]);
    }

    for (int i = 1; i <= N; i++)
    {
        printf("%d: ", i);
        for (int j = 0; j < paths[i].size(); j++)
        {
            printf("%d ", paths[i][j]);
        }
        printf("\n");
    }

    return 0;
}
