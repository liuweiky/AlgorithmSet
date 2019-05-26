/**
Warshall Matrix

N = 6
M = 7
Graph = [
1, 2
1, 4
2, 3
3, 1
4, 5
5, 6
6, 5
]

6
7
1 2
1 4
2 3
3 1
4 5
5 6
6 5

*/

#include <cstdio>
#include <algorithm>

#define MAX_N 1024

using namespace std;

int N, M;
bool graph[MAX_N][MAX_N];
bool warshall[MAX_N][MAX_N];

int main()
{
    fill_n(&graph[0][0], MAX_N * MAX_N, 0);
    fill_n(&warshall[0][0], MAX_N * MAX_N, 0);
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        graph[s][t] = 1;
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (i == j || graph[i][j])
                warshall[i][j] = 1;

    // wik && wkj => wij

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            if (warshall[i][k])
                for (int j = 1; j <= N; j++)
                    warshall[i][j] = warshall[i][j] | warshall[k][j];

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            printf("%d ", warshall[i][j]);
        putchar('\n');
    }
    return 0;
}
