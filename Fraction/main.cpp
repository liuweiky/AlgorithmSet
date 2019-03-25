/**
Fraction class

N = 5

Test cases:

5
6/1 9/1
2/5 5/1
8/3 50/2
-7/3 -19/9
-5/2 5/3

*/

#include <cstdio>
#include <algorithm>

using namespace std;

int N;

struct frac
{
    long long up, down;
};

long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

frac reduction(frac f)
{
    if (f.down < 0)
    {
        f.up = - f.up;
        f.down = - f.down;
    }
    if (f.up == 0)
    {
        f.down = 1;
        return f;
    }
    if (f.down == 0)
    {
        f.up = 1;
        return f;
    }

    long long g = gcd(abs(f.up), f.down);
    f.up /= g;
    f.down /= g;
    return f;
}

void print_frac(frac f)
{
    f = reduction(f);
    if (f.down == 1)
    {
        printf("%lld", f.up);
        return;
    }
    if (f.down == 0)
    {
        printf("Inf");
        return;
    }
    if (f.up == 0)
    {
        printf("0");
        return;
    }

    if (abs(f.up) > f.down)
    {
        printf("%lld ", f.up / f.down);
        printf("%lld/%lld", abs(f.up) % f.down, f.down);
        return;
    }
    printf("%lld/%lld", f.up, f.down);
}

frac add(frac lhs, frac rhs)
{
    frac f;
    f.up = lhs.up * rhs.down + lhs.down * rhs.up;
    f.down = lhs.down * rhs.down;
    return reduction(f);
}

frac sub(frac lhs, frac rhs)
{
    rhs.up = -rhs.up;
    return add(lhs, rhs);
}

frac mul(frac lhs, frac rhs)
{
    frac f;
    f.up = lhs.up * rhs.up;
    f.down = lhs.down * rhs.down;
    return reduction(f);
}

frac div(frac lhs, frac rhs)
{
    swap(rhs.up, rhs.down);
    return mul(lhs, rhs);
}

int main()
{
    scanf("%d", &N);

    while (N--)
    {
        putchar('\n');
        frac f1, f2;
        scanf("%lld/%lld %lld/%lld", &f1.up, &f1.down, &f2.up, &f2.down);
        print_frac(add(f1, f2));
        putchar('\n');
        print_frac(sub(f1, f2));
        putchar('\n');
        print_frac(mul(f1, f2));
        putchar('\n');
        print_frac(div(f1, f2));
        putchar('\n');
    }


    return 0;
}
