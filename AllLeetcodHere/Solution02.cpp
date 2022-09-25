#include "Solution02.h"

vector<int> Solution::getModifiedArray(int length, vector<vector<int> >& updates)
{
    vector<int> result(length, 0);
    for (auto it : updates)
    {
        result[it[0]] = it[2];
        if (it[1] + 1 < length) result[it[1]] -= it[2];
    }
    for (int i = 1; i < length; ++i) result[i] += result[i - 1];
    return result;
}
