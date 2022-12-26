#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <stack>
#include <deque>
#include <queue>
#include <numeric>
#include <string>

namespace s01
{
	class MyLinkedList {	// leetcode 707
	public:
		MyLinkedList();

		~MyLinkedList();

		int get(int index);

		void addAtHead(int val);

		void addAtTail(int val);

		void addAtIndex(int index, int val);

		void deleteAtIndex(int index);

		void print();

	private:
		struct Node
		{
			Node() : val(0), next(nullptr) {}
			Node(int v) : val(v), next(nullptr) {}
			int val;
			Node* next;
		};
		Node* m_head;
		int m_len;
	};

	class UnionFind	// 并查集
	{
	public:
		UnionFind() {}

		UnionFind(int n);

		void Union(int a, int b);

		int Find(int a);

	private:
		std::vector<int> parent;
	};

	class UnionFind_leetcode399	// 并查集、维护权值
	{
	public:
		UnionFind_leetcode399() {}

		UnionFind_leetcode399(int n);

		void Union(int a, int b, std::unordered_map<int, std::unordered_map<int, double> >& ans);

		int Find(int a, std::unordered_map<int, std::unordered_map<int, double> >& ans);

	private:
		std::vector<int> parent;
	};

	class NumArray {	// leetcode 303 9/23/22 前缀和 动态规划
	public:
		NumArray(std::vector<int>& nums);

		int sumRange(int left, int right);

	private:
		std::vector<int> sums;
	};

	class NumMatrix // leetcode 304 9/24/22 2D prefix sum
	{
	public:
		NumMatrix(std::vector<std::vector<int> >& matrix);

		int sumRegion(int row1, int col1, int row2, int col2);

	private:
		std::vector<std::vector<int> > sums;
	};

	class Solution {
	public:
		const int inf = 0x3f3f;

		std::string addStrings(std::string num1, std::string num2);	// leetcode 415 9/22/22

		std::string multiply(std::string num1, std::string num2);		// leetcode 43 9/22/22
		//std::string multiply(std::string num1, std::string num2);
		//void mul(std::string A, int b, int i, std::vector<int>& res);

		std::vector<int> sortArray(std::vector<int>& nums);	// leetcode 912 9/21/22
		void maxHeap(std::vector<int>& nums, int i, int len);

		int maximumRemovals(std::string s, std::string p, std::vector<int>& removable);	// leetcode 1898 9/20/22
		bool sub_1898(int k, std::vector<int>& removable, std::string s, std::string p);

		//std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations, std::vector<double>& values, std::vector<std::vector<std::string>>& queries);	// leetcode 399 9/16-17/22
		std::unordered_map<std::string, std::string> p;
		std::unordered_map<std::string, double> w;
		std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations, std::vector<double>& values, std::vector<std::vector<std::string>>& queries);
		std::string find(std::string x);	// 并查集

		//int numIslands(std::vector<std::vector<char>>& grid);	// leetcode 200 9/14/22 三个思路 bfs dfs 并查集
		void bfs(std::vector<std::vector<char> >& grid, std::deque<std::pair<int, int> >& coordinates, int m, int n);
		// dfs 与 bfs 类似
		int numIslands(std::vector<std::vector<char>>& grid);	// UnionFind *

		//vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2);	// leetcode 496 9/13/22
		std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2);	// 单调栈解法

		int chalkReplacer(std::vector<int>& chalk, int k);	// leetcode 1894 9/12/22
		//int chalkReplacer(std::vector<int>& chalk, int k);

		int minSpeedOnTime(std::vector<int>& dist, double hour);	// leetcode 1870 9/10/22
		bool judgeSpeed(std::vector<int>& dist, double hour, int speed);

		int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k);	// leetcode 743 9/9/22 9/18/22

		bool containsCycle(std::vector<std::vector<char>>& grid);	// leetcode 1559 9/8/22 ***

		//int cherryPickup(std::vector<std::vector<int>>& grid);	// leetcode 741 没写出来

		std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color);	// leetcode 733 9/5/22
		//const int dx[4] = { 1, 0, 0, -1 };
		//const int dy[4] = { 0, 1, -1, 0 };
		//std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color);

		int minPathSum(std::vector<std::vector<int>>& grid);	// leetcode 64	// 进阶版，允许各个方向的移动 *

		std::vector<std::vector<int>> generate(int numRows);	// leetcode 118
		//std::vector<std::vector<int>> generate(int numRows);	// 参考答案

		std::vector<int> searchRange(std::vector<int>& nums, int target);	// leetcode 34 *

		int minCostClimbingStairs(std::vector<int>& cost);	// leetcode 746

		int climbStairs(int n);	// leetcode 70

		void printVector(std::vector<std::vector<int> >& nums);  // 打印二维数组

	};

}

