#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include "BinaryIndexedTree.h"
#include "TrieTree.h"
using namespace std;

typedef unsigned long long ull;

class Solution
{
public:
	vector<int> getModifiedArray(int length, vector<vector<int>>& updates);	// leetcode 370 9/25/22 未提交

	vector<int> getModifiedArray_(int length, vector<vector<int>>& updates);	// 树状数组（BIT）和差分思想

	bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth);	// leetcode 2132 9/26/22 效率极差

	int lengthOfLongestSubstring(string s); // leetcode 3 9/28/22 滑动窗口（双指针）

	int numSubarrayProductLessThanK(vector<int>& nums, int k);	// leetcode 713 9/29/22

	int numSubarrayProductLessThanK_(vector<int>& nums, int k);

	int hammingWeight(uint32_t n);	// leetcode 191 9/30/22

	int hammingWeight_(uint32_t n);

	int hammingWeight__(uint32_t n);

	vector<vector<int> > merge(vector<vector<int> >& intervals);	// leetcode 56 10/1/22

	vector<vector<int> > merge_(vector<vector<int> >& intervals);

	vector<int> dailyTemperatures(vector<int>& temperatures);	// leetcode 739 10/2/22 单调栈

	vector<int> dailyTemperatures_(vector<int>& temperatures);

	int sumSubarrayMins(vector<int>& arr);	// leetcode 907 10/3-4/22 单调栈 *

	int maxWidthRamp(vector<int>& nums);	// leetcode 962 10/4/22

	int maxWidthRamp_(vector<int>& nums);	// *

	int maxChunksToSorted(vector<int>& arr);	// leetcode 768 10/5/22 单调栈

	int maxChunksToSorted_(vector<int>& arr);

	long long subArrayRanges(vector<int>& nums);	// leetcode 2104 10/6/22 单调栈，与 leetcode 907 类似

	int maxSumMinProduct(vector<int>& nums);	// leetcode 1856 10/7/22	单调栈 + 前缀和 *

	vector<int> maxSlidingWindow(vector<int>& nums, int k);	// leetcode 239 10/7/22 单调栈

	vector<int> maxSlidingWindow_(vector<int>& nums, int k);	// 单调队列 *

	int findMaxValueOfEquation(vector<vector<int>>& points, int k);	// leetcode 1499 10/8/22 单调队列

	int findMaxValueOfEquation_(vector<vector<int>>& points, int k);

	int shortestSubarray(vector<int>& nums, int k);	// leetcode 862 10/9/22 单调队列

	int constrainedSubsetSum(vector<int>& nums, int k);	// leetcode 1425 10/11/22 DP 单调队列 ***

	string shortestPalindrome(string s);	// leetcode 214 10/12/22

	string shortestPalindrome_(string s);	// 字符串哈希

	vector<vector<int> > palindromePairs(vector<string>& words);	// leetcode 336 10/13/22

	bool isPalindrome(string& str, int left, int right);	// 判断是否是回文串

	vector<vector<int> > palindromePairs_(vector<string>& words);	// 字典树

	vector<pair<int, int> > manacher(string& s);

	vector<vector<int> > palindromePairs__(vector<string>& words);	// 字典树 Manacher

	string longestDupSubstring(string s);	// leetcode 1044 10/14/22 字符串哈希 二分查找
	
	int distinctEchoSubstrings(string text);	// leetcode 1316 10/15/22 字符串哈希 *

	bool dfs_291(int i, int j, string& p, string& s, unordered_set<string>& vis, unordered_map<char, string>& d);

	bool wordPatternMatch(string pattern, string s);	// leetcode 291 10/16/22 哈希表 ***

private:
	const int inf = 0x3f3f3f3f;
};
