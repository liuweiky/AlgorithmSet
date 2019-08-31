#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX_N 1024

using namespace std;

char s1[MAX_N], s2[MAX_N];
int dp[MAX_N][MAX_N];

int main()
{
    fill_n(&dp[0][0], MAX_N * MAX_N, 0);

    s1[0] = s2[0] = ' ';
    scanf("%s %s", s1 + 1, s2 + 1);

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    len1--;
    len2--;

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (s1[i] == s2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    printf("%d", dp[len1][len2]);

    return 0;
}
