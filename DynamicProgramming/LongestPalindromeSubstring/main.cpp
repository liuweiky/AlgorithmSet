#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX_LEN 1024

using namespace std;

char str[MAX_LEN];
int dp[MAX_LEN][MAX_LEN];
int len;

int main()
{
    gets(str);
    len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        dp[i][i] = 1;
        if (i != 0 && str[i - 1] == str[i])
            dp[i - 1][i] = 2;
    }

    int ans = 1;

    for (int k = 2; k <= len; k++)
    {
        for (int j = 0; j + k < len; j++)
        {
            if (str[j] == str[j + k])
                dp[j][j + k] = dp[j + 1][j + k - 1] + 2;
            else
                dp[j][j + k] = 0;
            ans = max(ans, dp[j][j + k]);
        }
    }

    printf("%d", ans);

    return 0;
}
