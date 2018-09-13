#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

/**
example input:
5 7
1 2 2
1 3 3
1 5 2
2 5 1
5 3 1
3 4 5
4 1 1
*/


#define MAX_N 512

using namespace std;

struct Node
{
    int vertex;
    int cost;
    Node(){}
    Node(int v, int c): vertex(v), cost(c) {}
};

vector<Node*> graph[MAX_N];
int dis[MAX_N];
int inq[MAX_N];
vector<int> path[MAX_N];

int N, M;

void SPFA(int v)
{
    queue<int> q;
    dis[v] = 0;
    inq[v] = 1;
    q.push(v);
    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        inq[s] = 0;
        for (int i = 0; i < graph[s].size(); i++)
        {
            int t = graph[s][i]->vertex;
            int c = graph[s][i]->cost;
            if (dis[t] > dis[s] + c)
            {
                dis[t] = dis[s] + c;
                path[t].clear();
                path[t].push_back(s);
                if (inq[t] != 1)
                {
                    inq[t] = 1;
                    q.push(t);
                }
            } else if (dis[t] == dis[s] + c)
            {
                path[t].push_back(s);
                // 无需入队
                // 只有当 d[t] 改变时，从 t 出发的 d[k] 才有可能改变 ——《算法笔记》
            }
        }
    }
}

int main()
{
    fill_n(dis, MAX_N, INT_MAX);
    fill_n(inq, MAX_N, 0);
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        int s, t, c;
        scanf("%d %d %d", &s, &t, &c);
        graph[s].push_back(new Node(t, c));
    }

    SPFA(1);

    for (int i = 1; i <= N; i++)
    {
        printf("%d: %d\n", i, dis[i]);
    }

    for (int i = 1; i <= N; i++)
    {
        printf("%d: ", i);
        for (int j = 0; j < path[i].size(); j++)
        {
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }

    return 0;
}
