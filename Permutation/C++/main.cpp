#include <cstdio>

#define MAX_N 101

using namespace std;

int P[MAX_N], hash_table[MAX_N] = {false};

void GeneratePermutation(int cur, int target);

int main()
{
    GeneratePermutation(1, 3);
    return 0;
}

void GeneratePermutation(int cur, int target)
{
    if (cur == target + 1)
    {
        for (int i = 1; i <= target; i++)
            printf("%d ", P[i]);
        printf("\n");
        return;
    }

    for (int i = 1; i <= target; i++)
    {
        if (!hash_table[i])
        {
            hash_table[i] = true;
            P[cur] = i;
            GeneratePermutation(cur + 1, target);
            hash_table[i] = false;
        }
    }
}
