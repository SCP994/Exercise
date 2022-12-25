#pragma once
#include <vector>
//#include <algorithm>

class Solution04
{
public:
    Solution04();

    int cherryPickup(std::vector<std::vector<int>>& grid);  // leetcode 741 12/24/22 DP

    int cherryPickup_(std::vector<std::vector<int>>& grid);  // leetcode 1463 12/25/22 DP

private:
    int m, n, inf;

};

