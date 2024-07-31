#include <algorithm>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "BinaryIndexedTree.h"
#include "TrieTree.h"

namespace s02 {
class Solution {
   public:
    std::vector<int> getModifiedArray(
        int length,
        std::vector<std::vector<int>>& updates); // leetcode 370 9/25/22 未提交

    std::vector<int> getModifiedArray_(
        int length,
        std::vector<std::vector<int>>& updates); // 树状数组（BIT）和差分思想

    bool possibleToStamp(std::vector<std::vector<int>>& grid, int stampHeight,
                         int stampWidth); // leetcode 2132 9/26/22 效率极差

    int lengthOfLongestSubstring(
        std::string s); // leetcode 3 9/28/22 滑动窗口（双指针）

    int numSubarrayProductLessThanK(std::vector<int>& nums,
                                    int k); // leetcode 713 9/29/22

    int numSubarrayProductLessThanK_(std::vector<int>& nums, int k);

    int hammingWeight(uint32_t n); // leetcode 191 9/30/22

    int hammingWeight_(uint32_t n);

    int hammingWeight__(uint32_t n);

    std::vector<std::vector<int>> merge(
        std::vector<std::vector<int>>& intervals); // leetcode 56 10/1/22

    std::vector<std::vector<int>> merge_(
        std::vector<std::vector<int>>& intervals);

    std::vector<int> dailyTemperatures(
        std::vector<int>& temperatures); // leetcode 739 10/2/22 单调栈

    std::vector<int> dailyTemperatures_(std::vector<int>& temperatures);

    int sumSubarrayMins(
        std::vector<int>& arr); // leetcode 907 10/3-4/22 单调栈 *

    int maxWidthRamp(std::vector<int>& nums); // leetcode 962 10/4/22

    int maxWidthRamp_(std::vector<int>& nums); // *

    int maxChunksToSorted(std::vector<int>& arr); // leetcode 768 10/5/22 单调栈

    int maxChunksToSorted_(std::vector<int>& arr);

    long long subArrayRanges(
        std::vector<int>&
            nums); // leetcode 2104 10/6/22 单调栈，与 leetcode 907 类似

    int maxSumMinProduct(std::vector<int>& nums); // leetcode 1856 10/7/22
                                                  // 单调栈 + 前缀和 *

    std::vector<int> maxSlidingWindow(std::vector<int>& nums,
                                      int k); // leetcode 239 10/7/22 单调栈

    std::vector<int> maxSlidingWindow_(std::vector<int>& nums,
                                       int k); // 单调队列 *

    int findMaxValueOfEquation(std::vector<std::vector<int>>& points,
                               int k); // leetcode 1499 10/8/22 单调队列

    int findMaxValueOfEquation_(std::vector<std::vector<int>>& points, int k);

    int shortestSubarray(std::vector<int>& nums,
                         int k); // leetcode 862 10/9/22 单调队列

    int constrainedSubsetSum(std::vector<int>& nums,
                             int k); // leetcode 1425 10/11/22 DP 单调队列 ***

    std::string shortestPalindrome(std::string s); // leetcode 214 10/12/22

    std::string shortestPalindrome_(std::string s); // 字符串哈希

    std::vector<std::vector<int>> palindromePairs(
        std::vector<std::string>& words); // leetcode 336 10/13/22

    bool isPalindrome(std::string& str, int left,
                      int right); // 判断是否是回文串

    std::vector<std::vector<int>> palindromePairs_(
        std::vector<std::string>& words); // 字典树

    std::vector<std::pair<int, int>> manacher(std::string& s);

    std::vector<std::vector<int>> palindromePairs__(
        std::vector<std::string>& words); // 字典树 Manacher

    std::string longestDupSubstring(
        std::string s); // leetcode 1044 10/14/22 字符串哈希 二分查找

    int distinctEchoSubstrings(
        std::string text); // leetcode 1316 10/15/22 字符串哈希 *

    bool dfs_291(int i, int j, std::string& p, std::string& s,
                 std::unordered_set<std::string>& vis,
                 std::unordered_map<char, std::string>& d);

    bool wordPatternMatch(std::string pattern,
                          std::string s); // leetcode 291 10/16/22 哈希表 ***

   private:
    const int inf = 0x3f3f3f3f;
};

} // namespace s02
