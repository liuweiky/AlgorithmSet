#include <cstdio>
#include <algorithm>

#define MAX_N 1001

using namespace std;

int primes[MAX_N], prime_num = 0;
bool is_prime[MAX_N];

void Eratosthenes();

int main()
{
    fill_n(is_prime, MAX_N, true);
    Eratosthenes();
    for (int i = 0; i < prime_num; i++)
        printf("%d ", primes[i]);
    return 0;
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
