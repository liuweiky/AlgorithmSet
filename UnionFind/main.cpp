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
    if (father[a] != father[b])
        father[father[a]] = father[b];
}

int main()
{
    for (int i = 0; i < MAX_N; i++)
        father[i] = i;

    return 0;
}
