#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX_N 1024

using namespace std;

char str1[MAX_N];
char str2[MAX_N];

int dp[MAX_N][MAX_N];

int main()
{
    gets(str1);
    gets(str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int ans = dp[0][0] = str1[0] == str2[0] ? 1 : 0;

    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            if (i == 0 && j == 0)
                continue;
            if (str1[i] == str2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            ans = max(ans, dp[i][j]);
        }
    }
    printf("%d", ans);
    return 0;
}
