#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

#include "BinaryIndexedTree.h"

namespace s04 {
class MyBITree : public BinaryIndexedTree {
   public:
    MyBITree(int len);

    void update(int index, int value);

    int query(int index) const;
};

class Solution {
   public:
    Solution();

    int cherryPickup(
        std::vector<std::vector<int>>& grid); // leetcode 741 12/24/22 DP

    int cherryPickup_(
        std::vector<std::vector<int>>& grid); // leetcode 1463 12/25/22 DP

    int lengthOfLIS(std::vector<int>& nums); // leetcode 300 12/26/22 DP O(n^2)

    int lengthOfLIS_(std::vector<int>& nums); // 贪心 二分查找 O(nlogn)

    int lengthOfLIS__(std::vector<int>& nums); // 树状数组 O(nlogn) ***

    int eraseOverlapIntervals(
        std::vector<std::vector<int>>&
            intervals); // leetcode 435 12/27/22 排序 贪心 ***

    int eraseOverlapIntervals_(std::vector<std::vector<int>>& intervals); // DP

    int minDeletionSize(std::vector<std::string>&
                            strs); // leetcode 960 1/1/23 DP 最长上升子序列模型

    bool judge_960(std::vector<std::string>& strs, int x, int y);

    int minDeletionSize_(std::vector<std::string>& strs);

    int maxEnvelopes(std::vector<std::vector<int>>&
                         envelopes); // leetcode 354 1/29/23 DP
                                     // 最长上升子序列模型 贪心 二分查找

    int maxHeight(
        std::vector<std::vector<int>>&
            cuboids); // leetcode 1691 4/6/23 DP 最长上升子序列 排序 动规

   private:
    int m, n, inf;
};

} // namespace s04
