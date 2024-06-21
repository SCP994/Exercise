#include "pat.h"

NS_PAT_B_BEGIN

int pat_1001(int n)
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

NS_PAT_B_END
