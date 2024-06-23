#include "pat.h"

int pat_b_1001(int n)
{
    int cnt = 0;

    while (n != 1)
    {
        ++cnt;
        if (n % 2)
            n = (3 * n + 1) / 2;
        else
            n /= 2;
    }

    return cnt;
}

int pat_b_1011(long long A, long long B, long long C)
{
    if (A + B > C)
        return 1;
    return 0;
}

int pat_b_1016(int A, int DA, int B, int DB)
{
    int PA = 0;
    int PB = 0;
    while (A)
    {
        if (A % 10 == DA)
            PA = PA * 10 + DA;
        A /= 10;
    }
    while (B)
    {
        if (B % 10 == DB)
            PB = PB * 10 + DB;
        B /= 10;
    }
    return PA + PB;
}

void pat_b_1026(int C1, int C2)
{
    int duration = C2 - C1;
    int h = 0, m = 0, s = 0;
    const int BASE = 60;
    const int CLK_TCK = 100;

    s = duration % (BASE * CLK_TCK);
    duration /= (BASE * CLK_TCK);
    m = duration % BASE;
    duration /= BASE;
    h = duration % BASE;

    printf("%02d:%02d:%02d\n", h, m, (s + (CLK_TCK / 2))/ CLK_TCK);
}

int pat_b_1046(int a, int b, int c, int d)
{
    int total = a + c;
    if (b == total && d != total)
        return 2;
    if (b != total && d == total)
        return 1;
    return 0;
}
