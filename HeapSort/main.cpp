/**
Heap Sort

5
3 4 2 5 1
*/

#include <cstdio>
#include <algorithm>

#define MAX_N 1024

using namespace std;

int heap[MAX_N];
int N;

void down_adjust(int low, int high)
{
    int i = low, j = i * 2;
    while (j <= high)
    {
        if (j + 1 <= high && heap[j + 1] > heap[j])
            j = j + 1;
        if (heap[i] < heap[j])
        {
            swap(heap[i], heap[j]);
            i = j;
            j = i * 2;
        }
        else
            break;
    }
}

void create_heap()
{
    for (int i = N / 2; i >= 1; i--)
        down_adjust(i, N);
}

void heap_sort()
{
    create_heap();
    for (int i = N; i >= 1; i--)
    {
        swap(heap[1], heap[i]);
        down_adjust(1, i - 1);
    }
}

int main()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        scanf("%d", &heap[i]);

    heap_sort();

    for (int i = 1; i <= N; i++)
        printf("%d ", heap[i]);

    return 0;
}
