#pragma once
#include <vector>
#include <set>
#include <unordered_map>
#include "BinaryIndexedTree.h"

namespace s04
{
	class MyBITree : public BinaryIndexedTree
	{
	public:
		MyBITree(int len);

		void update(int index, int value);

		int query(int index) const;

	};

	class Solution
	{
	public:
		Solution();

		int cherryPickup(std::vector<std::vector<int>>& grid);  // leetcode 741 12/24/22 DP

		int cherryPickup_(std::vector<std::vector<int>>& grid);  // leetcode 1463 12/25/22 DP

		int lengthOfLIS(std::vector<int>& nums);  // leetcode 300 12/26/22 DP O(n^2)

		int lengthOfLIS_(std::vector<int>& nums);  // 贪心 二分查找 O(nlogn)

		int lengthOfLIS__(std::vector<int>& nums);  // 树状数组 O(n^2) ***

	private:
		int m, n, inf;

	};

}

