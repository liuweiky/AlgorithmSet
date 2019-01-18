/*
5 8
1 2 4
1 3 5
1 4 6
2 4 1
3 2 2
3 5 7
4 3 3
5 1 1
*/

#include <cstdio>
#include <climits>
#include <algorithm>

#define MAX_N 1024

using namespace std;

int graph[MAX_N][MAX_N];
int visit[MAX_N];
int path[MAX_N];
int dis[MAX_N];

int N, K;

void dijkstra(int v)
{
    fill_n(visit, MAX_N, 0);
    fill_n(path, MAX_N, -1);
    fill_n(dis, MAX_N, INT_MAX);

    int u = v;
    visit[u] = 1;
    dis[u] = 0;

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (visit[j] == 0 && graph[u][j] > 0 && dis[j] > dis[u] + graph[u][j])
            {
                path[j] = u;
                dis[j] = dis[u] + graph[u][j];
            }
        }

        int min_dis = INT_MAX;

        for (int i = 1; i <= N; i++)
        {
            if (visit[i] == 0 && dis[i] < min_dis)
            {
                u = i;
                min_dis = dis[i];
            }
        }
        visit[u] = 1;
    }
}

int main()
{
    fill_n(&graph[0][0], MAX_N * MAX_N, -1);
    scanf("%d %d", &N, &K);

    for (int i = 0; i < K; i++)
    {
        int s, t, d;
        scanf("%d %d %d", &s, &t, &d);
        graph[s][t] = d;
    }

    dijkstra(2);

    for (int i = 1; i <= N; i++)
        printf("%d:%d\n", i, dis[i]);

    return 0;
}
