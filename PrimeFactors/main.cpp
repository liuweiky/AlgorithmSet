/**
质因子分解
*/

#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

#define MAX_N 128

using namespace std;

struct factor
{
    int prime, num;
};


int primes[MAX_N], prime_num = 0;
bool is_prime[MAX_N];

vector<factor> facs;

void gen_factors(int n)
{
    int nsqrt = sqrt(n);

    for (int i = 0; primes[i] <= nsqrt; i++)
    {
        int p = primes[i];
        if (n % p == 0)
        {
            factor f = factor();
            f.num = 0;
            f.prime = p;

            do
            {
                f.num++;
                n /= p;
            } while (n % p == 0);

            facs.push_back(f);
        }
    }

    // 若 n 还未被除到 1，说明有且仅有一个大于 nsqrt 的质因子
    if (n != 1)
    {
        factor f = factor();
        f.num = 1;
        f.prime = n;
        facs.push_back(f);
    }
}

// 埃氏筛法
void Eratosthenes()
{
    for (int i = 2; i < MAX_N; i++)
    {
        if (is_prime[i])
        {
            primes[prime_num++] = i;
            // 筛去所有 i 的倍数
            for (int j = i + i; j < MAX_N; j += i)
                is_prime[j] = false;
        }
    }
}


int main()
{
    fill_n(is_prime, MAX_N, true);
    Eratosthenes();
    int n;
    scanf("%d", &n);
    gen_factors(n);

    printf("\n");

    for (int i = 0; i < facs.size(); i++)
    {
        for (int j = 0; j < facs[i].num; j++)
            printf("%d ", facs[i].prime);
        printf("\n");
    }

    return 0;
}
