/**
Topological Order

N = 5
M = 7
Graph = [
1, 2
1, 3
2, 4
2, 3
4, 3
4, 5
5, 3
]

5 7
1 2
1 3
2 4
2 3
4 3
4 5
5 3

*/

#include <cstdio>
#include <algorithm>
#include <queue>

#define MAX_N 32

using namespace std;

int in_degree[MAX_N];
vector<int> graph[MAX_N];
int N, M;

bool topo_order()
{
    queue<int> q;

    for (int i = 1; i <= N; i++)
        if (in_degree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        printf("%d ", u);
        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];
            in_degree[v]--;

            if (in_degree[v] == 0)
                q.push(v);
        }
    }

    for (int i = 1; i <= N; i++)
        if (in_degree[i] != 0)
            return false;
    return true;
}

int main()
{
    fill_n(in_degree, MAX_N, 0);

    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        in_degree[t]++;
        graph[s].push_back(t);
    }

    if (!topo_order())
        printf("\n\nERROR: Topo order couldn't be achieved!\n");

    return 0;
}
