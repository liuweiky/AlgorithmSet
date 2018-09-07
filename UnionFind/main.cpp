#include <cstdio>

#define MAX_N 1024

using namespace std;

int father[MAX_N];

int GetFather(int a)
{
    int b = a;
    while (a != father[a])
        a = father[a];
    // Optimization
    while (b != a)
    {
        int t = father[b];
        father[b] = a;
        b = t;
    }
    return a;
}

void Union(int a, int b)
{
    if (GetFather[a] != GetFather[b])
        father[GetFather(a)] = GetFather(b);
}

int main()
{
    for (int i = 0; i < MAX_N; i++)
        father[i] = i;

    Union(1, 2);
    Union(3, 4);
    Union(5, 6);
    // Union(1, 3);
    Union(3, 5);
    for (int i = 1; i <= 6; i++)
        printf("%d's father: %d\n", i, GetFather(i));

    return 0;
}
