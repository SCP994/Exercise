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
using namespace std;

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
	vector<int> parent;
};

class UnionFind_leetcode399	// 并查集、维护权值
{
public:
	UnionFind_leetcode399() {}

	UnionFind_leetcode399(int n);

	void Union(int a, int b, unordered_map<int, unordered_map<int, double> >& ans);

	int Find(int a, unordered_map<int, unordered_map<int, double> >& ans);

private:
	vector<int> parent;
};

class NumArray {	// leetcode 303 9/23/22 前缀和 动态规划
public:
	NumArray(vector<int>& nums);

	int sumRange(int left, int right);

private:
	vector<int> sums;
};

class NumMatrix // leetcode 304 9/24/22 2D prefix sum
{
public:
	NumMatrix(vector<vector<int> >& matrix);

	int sumRegion(int row1, int col1, int row2, int col2);

private:
	vector<vector<int> > sums;
};

class Solution {
public:
	const int inf = 0x3f3f;

	string addStrings(string num1, string num2);	// leetcode 415 9/22/22

	string multiply(string num1, string num2);		// leetcode 43 9/22/22
	//string multiply(string num1, string num2);
	//void mul(string A, int b, int i, vector<int>& res);

	vector<int> sortArray(vector<int>& nums);	// leetcode 912 9/21/22
	void maxHeap(vector<int>& nums, int i, int len);

	int maximumRemovals(string s, string p, vector<int>& removable);	// leetcode 1898 9/20/22
	bool sub_1898(int k, vector<int>& removable, string s, string p);

	//vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries);	// leetcode 399 9/16-17/22
	unordered_map<string, string> p;
	unordered_map<string, double> w;
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries);
	string find(string x);	// 并查集

	//int numIslands(vector<vector<char>>& grid);	// leetcode 200 9/14/22 三个思路 bfs dfs 并查集
	void bfs(vector<vector<char> >& grid, deque<pair<int, int> >& coordinates, int m, int n);
	// dfs 与 bfs 类似
	int numIslands(vector<vector<char>>& grid);	// UnionFind *

	//vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2);	// leetcode 496 9/13/22
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2);	// 单调栈解法

	int chalkReplacer(vector<int>& chalk, int k);	// leetcode 1894 9/12/22
	//int chalkReplacer(vector<int>& chalk, int k);

	int minSpeedOnTime(vector<int>& dist, double hour);	// leetcode 1870 9/10/22
	bool judgeSpeed(vector<int>& dist, double hour, int speed);

	int networkDelayTime(vector<vector<int>>& times, int n, int k);	// leetcode 743 9/9/22 9/18/22

	bool containsCycle(vector<vector<char>>& grid);	// leetcode 1559 9/8/22 ***

	int cherryPickup(vector<vector<int>>& grid);	// leetcode 741 没写出来

	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color);	// leetcode 733 9/5/22
	//const int dx[4] = { 1, 0, 0, -1 };
	//const int dy[4] = { 0, 1, -1, 0 };
	//vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color);

	int minPathSum(vector<vector<int>>& grid);	// leetcode 64	// 进阶版，允许各个方向的移动 *

	vector<vector<int>> generate(int numRows);	// leetcode 118
	//vector<vector<int>> generate(int numRows);	// 参考答案

	vector<int> searchRange(vector<int>& nums, int target);	// leetcode 34 *

	int minCostClimbingStairs(vector<int>& cost);	// leetcode 746

	int climbStairs(int n);	// leetcode 70

	// 调试相关
	void printVector(vector<vector<int> >& nums);
};
