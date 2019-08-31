#include <cstdio>
#include <algorithm>

#define MAX_N 1024

using namespace std;

int N;
int w[MAX_N];
int c[MAX_N];
int dp[MAX_N];

int total_w;

int main()
{
    scanf("%d %d", &N, &total_w);

    for (int i = 1; i <= N; i++)
        scanf("%d", &w[i]);

    for (int i = 1; i <= N; i++)
        scanf("%d", &c[i]);

    for (int v = 0; v <= total_w; v++)
        dp[v] = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = total_w; j >= w[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
        }
    }

    printf("%d", dp[total_w]);

    return 0;
}
