#include <cstdio>
#include <algorithm>

#define PROBLEM_N 6

using namespace std;

int P[PROBLEM_N + 1];

bool check(int k)   // 检查 k 这个棋子能不能放下
{
    for (int i = 1; i < k; i++) // 遍历前 k - 1 个检查
    {
        if (P[i] == P[k] || // 在同一行，也可以用打表检查
            abs(i - k) == abs(P[i] - P[k])) // 在同一斜行
            return false;
    }
    return true;
}

// n 皇后问题递归回溯法
void gen_j(int j)
{
    if (j == PROBLEM_N + 1)
    {
        for (int i = 1; i <= PROBLEM_N; i++)
            printf("%d ", P[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i <= PROBLEM_N; i++)
    {
        P[j] = i;
        if (check(j))
            gen_j(j + 1);
        else
            continue;
    }
}

int main()
{
    gen_j(1);
    return 0;
}
