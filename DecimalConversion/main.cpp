/**
Decimal Conversion

base: 16
number in base: ABC123

ABC123 16

*/

#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX_LEN 128

using namespace std;

char numin[MAX_LEN];
int numout[MAX_LEN];

int lenin, lenout;
int basein;

int deci;

int to_decimal(int base)
{
    lenin = strlen(numin);
    reverse(numin, numin + lenin);

    int res = 0, p = 1;

    for (int i = 0; i < lenin; i++)
    {
        int t = numin[i] >= 'A' ? numin[i] - 'A' + 10 : numin[i] - '0';
        res += p * t;
        p *= base;
    }
    return res;
}

void to_base()
{
    lenout = 0;

    int d = deci;

    do {
        numout[lenout++] = d % basein;
        d /= basein;
    } while (d);
}

int main()
{
    scanf("%s", numin);
    scanf("%d", &basein);

    deci = to_decimal(basein);

    printf("%d", deci);

    to_base();

    putchar('\n');

    for (int i = lenout - 1; i >= 0; i--)
        printf("%c", numout[i] >= 10 ? numout[i] - 10 + 'A' : numout[i] + '0');
    return 0;
}
