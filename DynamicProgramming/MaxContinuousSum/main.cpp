/**

IN:
6
-2 11 -4 13 -5 -2


OUT:
20

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
    for (int i = 1; i <= N; i++)
        scanf("%d", &nums[i]);

    int ans = dp[1] = nums[1];

    for (int i = 2; i <= N; i++)
    {
        dp[i] = max(nums[i], nums[i] + dp[i - 1]);
        ans = max(ans, dp[i]);
    }

    printf("%d", ans);

    return 0;
}
