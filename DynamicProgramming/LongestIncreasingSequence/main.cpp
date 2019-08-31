/**

IN:
8
1 2 3 -9 3 9 0 11

OUT:
6

*/

#include <cstdio>
#include <algorithm>

#define MAX_N 1024

using namespace std;

int N;
int nums[MAX_N];
int dp[MAX_N];

int main()
{
    scanf("%d", &N);

    for (int i = 1; i<= N; i++)
        scanf("%d", &nums[i]);

    int ans = dp[1] = 1;

    for (int i = 2; i<= N; i++)
    {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (nums[i] >= nums[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }

    printf("%d", ans);

    return 0;
}
