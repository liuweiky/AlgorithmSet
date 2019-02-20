#include <cstdio>

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    printf("%d", gcd(221, 299));
    return 0;
}
