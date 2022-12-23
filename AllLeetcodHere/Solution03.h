#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <numeric>
using namespace std;

typedef unsigned long long ull;

typedef long long ll;

class Solution
{
public:
	vector<vector<int> > updateMatrix(vector<vector<int> >& mat);	// leetcode 542 10/18/22

	void bfs_542_1(int x, int y, vector<vector<int> >& mat, vector<vector<int> >& vis, vector<vector<int> >& result);

	void bfs_542_2(vector<vector<int> >& mat, vector<vector<int> >& vis, vector<vector<int> >& result);

	vector<vector<int> > updateMatrix_(vector<vector<int> >& mat);	// 多源 BFS

	vector<vector<int>> highestPeak(vector<vector<int>>& isWater);	// leetcode 1765 10/19/22 多源 BFS

	int minKnightMoves(int x, int y);	// leetcode 1197 10/20/22 BFS

	int minKnightMoves_(int x, int y);	// 双向 BFS

	int extend_1197(unordered_map<int, int>& m1, unordered_map<int, int>& m2, deque<pair<int, int> >& q);

	int shortestPathBinaryMatrix(vector<vector<int>>& grid); // leetcode 1091 10/21/22 双向 BFS，朴素 BFS 可能更快

	int extend_1091(unordered_map<int, int>& m_oppo, unordered_map<int, int>& m, deque<pair<int, int> >& q, int n, vector<vector<int> >& grid);

	int nearestExit(vector<vector<char>>& maze, vector<int>& entrance); // leetcode 1926 10/22/22 BFS

	int shortestPath(vector<vector<int>>& grid, int k); // leetcode 1293 10/23/22 BFS 最短路

	int openLock(vector<string>& deadends, string target); // leetcode 752 10/24/22

	int openLock_(vector<string>& deadends, string target); // A* 算法

	int f(string state, string& target);

	int ladderLength(string beginWord, string endWord, vector<string>& wordList); // leetcode 127 10/25/22 （双向）BFS

	int minimumOperations(vector<int>& nums, int start, int goal); // leetcode 2059 10/26/22 双向 BFS

	int extend_2059(unordered_map<int, int>& m_q, unordered_map<int, int>& m, deque<int>& q, vector<int>& nums);

	int slidingPuzzle(vector<vector<int>>& board); // leetcode 773 10/27/22 A* 算法

	bool check(string& str);

	int f_773(string& state); // 估价函数

	int shortestPathLength(vector<vector<int>>& graph); // leetcode 847 10/29/22 BFS ***

	int cutOffTree(vector<vector<int>>& forest); // leetcode 675 11/1-2/22 A* 算法

	void maxHeapify(vector<vector<int> >& v, int heapSize, int i);

	int f_675(int x1, int y1, int x2, int y2);

	int minCost(vector<vector<int>>& grid); // leetcode 1368 11/3/22 双端队列 BFS

	int minimumObstacles(vector<vector<int>>& grid); // leetcode 2290 11/4/22 双端队列 BFS *

	bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination); // leetcode 490 11/5/22 DFS BFS

	bool exist(vector<vector<char>>& board, string word); // leetcode 79 11/6/22 回溯 ***

	bool dfs_79(int i, int j, int idx, int m, int n, int len, vector<vector<char> >& board, string& word);

	int getMaximumGold(vector<vector<int>>& grid); // leetcode 1219 11/7/22 回溯 DFS

	int dfs_1219(vector<vector<int> >& grid, int m, int n, int x, int y);

	bool makesquare(vector<int>& matchsticks); // leetcode 473 11/8/22 DFS 回溯

	bool dfs_473(vector<int>& matchsticks, int len, int idx, int count, int sum, int avg);

	bool makesquare_(vector<int>& matchsticks); // 排序 回溯

	bool dfs_473_(int idx, int avg, int len, vector<int>& matchsticks, vector<int>& edges);

	bool makesquare__(vector<int>& matchsticks); // 状态压缩 DP ***

	bool canPartitionKSubsets(vector<int>& nums, int k); // leetcode 698 11/10/22  状态压缩 DP ***，与 leetcode 473 类似

	int count_dfs_1723 = 0;
	int minimumTimeRequired(vector<int>& jobs, int k); // leetcode 1723 11/11-12/22 DFS 剪枝 *** 不会

	int dfs_1723(vector<int>& jobs, vector<int>& edges, int len, int k, int idx, int ret);

	int ret_2305;
	int distributeCookies(vector<int>& cookies, int k); // leetcode 2305 11/13/22 DFS 剪枝 与 leetcode 1723 类似

	void dfs_2305(vector<int>& cookies, vector<int>& edges, int idx, int len, int k);

	int longestIncreasingPath(vector<vector<int>>& matrix); // leetcode 329 11/14/22 记忆化搜索 ***

	int dfs_329(int x, int y);

	int countPaths(vector<vector<int>>& grid);  // leetcode 2328 11/15/22 记忆化搜索，与 leetcode 329 类似

	ull dfs_2328(int x, int y);

	bool canWin(string currentState);  // leetcode 294 11/20/22 DFS 没有记忆化的方法 效率较低 ***

	bool dfs_294(string& currentState);

	unordered_map<ll, bool> memo_294;
	bool canWin_(string currentState);  // 状态压缩，记忆化搜索 ***

	void dfs_294_(ll mask);

	bool canWin__(string currentState);  // 11/23/22 Sprague-Grundy 定理 ***

	int win__(int i);

	int countRoutes(vector<int>& locations, int start, int finish, int fuel);  // leetcode 1575 11/26/22 记忆化搜索 不会 ***

	void dfs_1575(int idx, int finish, int fuel, vector<int>& locations, vector<vector<int> >& fuels);

	int ways(vector<string>& pizza, int k);  // leetcode 1444 12/23/22 二维前缀和 记忆化搜索
	vector<vector<vector<int> > > mem;
	vector<vector<int> > p;

	int dfs_1444(int x, int y, int k);

private:
	const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
	int m, n, len;
	vector<int> dis = { 0, 1, 0, -1, 0 }, sg;
	vector<vector<int> > memo, matrix;
};

