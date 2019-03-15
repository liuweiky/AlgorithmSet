/**
Binary Indexed Tree

N = 5
Array = [1, 2, 3, 4, 5]

5
1 2 3 4 5

*/

#include <cstdio>
#include <algorithm>

#define MAX_N 32

using namespace std;

int arr[MAX_N];
int C[MAX_N];
int N;

int low_bit(int x)
{
    return x & (-x);
}

void update(int idx, int num)
{
    arr[idx] += num;

    for (int i = idx; i <= N; i += low_bit(i))
        C[i] += num;
}

int get_sum(int idx)
{
    int sum = 0;

    for (int i = idx; i > 0; i -= low_bit(i))
        sum += C[i];
    return sum;
}

int main()
{
    fill_n(arr, MAX_N, 0);
    fill_n(C, MAX_N, 0);
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        int x;
        scanf("%d", &x);
        update(i, x);
    }

    printf("%d", get_sum(5));

    return 0;
}
