#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#define MAX_N 1024000

using namespace std;

int numbers[MAX_N];

int part(int lp, int rp)
{
    int p = rand() % (rp - lp + 1) + lp;
    swap(numbers[lp], numbers[p]);

    int low = lp, high = rp, temp = numbers[lp];

    while (low < high)
    {
        while (low < high && numbers[high] > temp)
            high--;
        numbers[low] = numbers[high];
        while (low < high && numbers[low] <= temp)
            low++;
        numbers[high] = numbers[low];
    }

    numbers[low] = temp;

    return low;
}

void QuickSort(int lp, int rp)
{
    if (lp >= rp)
        return;
    int p = part(lp, rp);
    QuickSort(lp, p - 1);
    QuickSort(p + 1, rp);
}

int main()
{
    srand(time(NULL));

    int N = MAX_N;

    for (int i = 0; i < N; i++)
        numbers[i] = rand();


    for (int i = 0; i < N; i++)
        printf("%d ", numbers[i]);

    //printf("Starting quick sort...\n");

    QuickSort(0, N - 1);

    for (int i = 0; i < N; i++)
    {
        if (i < N - 1 && numbers[i] > numbers[i + 1])
            printf("\n\n************Error!************\n\n");

        printf("%d ", numbers[i]);
    }
    return 0;
}
