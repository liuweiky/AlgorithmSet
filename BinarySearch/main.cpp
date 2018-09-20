#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#define MAX_N 1024

using namespace std;

int numbers[MAX_N];

int BinarySearch(int m)
{
    int s, t, mid;
    s = 0;
    t = MAX_N - 1;
    while (s <= t)
    {
        mid = (s + t) / 2;
        if (m < numbers[mid])
            t = mid - 1;
        else if (m > numbers[mid])
            s = mid + 1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    srand((int)time(NULL));
    numbers[0] = 50;
    for (int i = 1; i < MAX_N; i++)
        numbers[i] = rand();
    sort(numbers, numbers + MAX_N);

    for (int i = 0; i < MAX_N; i++)
        cout << numbers[i] << "\t";

    cout << endl << BinarySearch(50);

    return 0;
}
