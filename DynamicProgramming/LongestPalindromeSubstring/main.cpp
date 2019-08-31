#include <iostream>
#include <algorithm>

#define MAX_N 1024

using namespace std;

bool dp[MAX_N][MAX_N];
string str;

int main()
{
    cin >> str;

    int ans = 1;

    for (int i = 0; i < str.size(); i++)
    {
        dp[i][i] = true;
        if (i != 0 && str[i - 1] == str[i])
        {
            dp[i - 1][i] = true;
            ans = 2;
        }
    }


    for (int len = 2; len < str.size(); len++)
    {
        for (int i = 0; i + len < str.size(); i++)
        {
            if (str[i] == str[i + len] && dp[i + 1][i + len - 1])
            {
                dp[i][i + len] = true;
                ans = max(ans, len + 1);
            }
        }
    }

    cout << ans;

    return 0;
}
