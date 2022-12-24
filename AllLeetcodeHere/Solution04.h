#pragma once
#include <vector>
using namespace std;

typedef unsigned long long ull;

class Solution
{
public:
    int cherryPickup(vector<vector<int> >& grid);  // leetcode 741 12/24/22 DP

private:
    int m, n;
    int inf = 0x3f3f3f3f;

};

