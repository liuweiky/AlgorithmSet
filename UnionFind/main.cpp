#include <cstdio>
#include <algorithm>

#define MAX_N 1024

using namespace std;

int father[MAX_N];

int GetFather(int a)
{
    int b = a;
    while (father[a] > 0)
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
    int fa = GetFather(a);
    int fb = GetFather(b);
    if (fa != fb)
    {
        father[fb] += father[fa];
        father[fa] = fb;
    }
}

int main()
{
    fill_n(father, MAX_N, -1);

    Union(1, 2);
    Union(3, 4);
    Union(5, 6);
    // Union(1, 3);
    Union(3, 5);
    for (int i = 1; i <= 6; i++)
        printf("%d's father: %d\n", i, GetFather(i));

    return 0;
}
