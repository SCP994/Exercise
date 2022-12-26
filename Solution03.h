#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <numeric>

namespace s03
{
	class Solution
	{
	public:
		std::vector<std::vector<int> > updateMatrix(std::vector<std::vector<int> >& mat);	// leetcode 542 10/18/22

		void bfs_542_1(int x, int y, std::vector<std::vector<int> >& mat, std::vector<std::vector<int> >& vis, std::vector<std::vector<int> >& result);

		void bfs_542_2(std::vector<std::vector<int> >& mat, std::vector<std::vector<int> >& vis, std::vector<std::vector<int> >& result);

		std::vector<std::vector<int> > updateMatrix_(std::vector<std::vector<int> >& mat);	// 多源 BFS

		std::vector<std::vector<int>> highestPeak(std::vector<std::vector<int>>& isWater);	// leetcode 1765 10/19/22 多源 BFS

		int minKnightMoves(int x, int y);	// leetcode 1197 10/20/22 BFS

		int minKnightMoves_(int x, int y);	// 双向 BFS

		int extend_1197(std::unordered_map<int, int>& m1, std::unordered_map<int, int>& m2, std::deque<std::pair<int, int> >& q);

		int shortestPathBinaryMatrix(std::vector<std::vector<int>>& grid); // leetcode 1091 10/21/22 双向 BFS，朴素 BFS 可能更快

		int extend_1091(std::unordered_map<int, int>& m_oppo, std::unordered_map<int, int>& m, std::deque<std::pair<int, int> >& q, int n, std::vector<std::vector<int> >& grid);

		int nearestExit(std::vector<std::vector<char>>& maze, std::vector<int>& entrance); // leetcode 1926 10/22/22 BFS

		int shortestPath(std::vector<std::vector<int>>& grid, int k); // leetcode 1293 10/23/22 BFS 最短路

		int openLock(std::vector<std::string>& deadends, std::string target); // leetcode 752 10/24/22

		int openLock_(std::vector<std::string>& deadends, std::string target); // A* 算法

		int f(std::string state, std::string& target);

		int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList); // leetcode 127 10/25/22 （双向）BFS

		int minimumOperations(std::vector<int>& nums, int start, int goal); // leetcode 2059 10/26/22 双向 BFS

		int extend_2059(std::unordered_map<int, int>& m_q, std::unordered_map<int, int>& m, std::deque<int>& q, std::vector<int>& nums);

		int slidingPuzzle(std::vector<std::vector<int>>& board); // leetcode 773 10/27/22 A* 算法

		bool check(std::string& str);

		int f_773(std::string& state); // 估价函数

		int shortestPathLength(std::vector<std::vector<int>>& graph); // leetcode 847 10/29/22 BFS ***

		int cutOffTree(std::vector<std::vector<int>>& forest); // leetcode 675 11/1-2/22 A* 算法

		void maxHeapify(std::vector<std::vector<int> >& v, int heapSize, int i);

		int f_675(int x1, int y1, int x2, int y2);

		int minCost(std::vector<std::vector<int>>& grid); // leetcode 1368 11/3/22 双端队列 BFS

		int minimumObstacles(std::vector<std::vector<int>>& grid); // leetcode 2290 11/4/22 双端队列 BFS *

		bool hasPath(std::vector<std::vector<int>>& maze, std::vector<int>& start, std::vector<int>& destination); // leetcode 490 11/5/22 DFS BFS

		bool exist(std::vector<std::vector<char>>& board, std::string word); // leetcode 79 11/6/22 回溯 ***

		bool dfs_79(int i, int j, int idx, int m, int n, int len, std::vector<std::vector<char> >& board, std::string& word);

		int getMaximumGold(std::vector<std::vector<int>>& grid); // leetcode 1219 11/7/22 回溯 DFS

		int dfs_1219(std::vector<std::vector<int> >& grid, int m, int n, int x, int y);

		bool makesquare(std::vector<int>& matchsticks); // leetcode 473 11/8/22 DFS 回溯

		bool dfs_473(std::vector<int>& matchsticks, int len, int idx, int count, int sum, int avg);

		bool makesquare_(std::vector<int>& matchsticks); // 排序 回溯

		bool dfs_473_(int idx, int avg, int len, std::vector<int>& matchsticks, std::vector<int>& edges);

		bool makesquare__(std::vector<int>& matchsticks); // 状态压缩 DP ***

		bool canPartitionKSubsets(std::vector<int>& nums, int k); // leetcode 698 11/10/22  状态压缩 DP ***，与 leetcode 473 类似

		int count_dfs_1723 = 0;
		int minimumTimeRequired(std::vector<int>& jobs, int k); // leetcode 1723 11/11-12/22 DFS 剪枝 *** 不会

		int dfs_1723(std::vector<int>& jobs, std::vector<int>& edges, int len, int k, int idx, int ret);

		int ret_2305;
		int distributeCookies(std::vector<int>& cookies, int k); // leetcode 2305 11/13/22 DFS 剪枝 与 leetcode 1723 类似

		void dfs_2305(std::vector<int>& cookies, std::vector<int>& edges, int idx, int len, int k);

		int longestIncreasingPath(std::vector<std::vector<int>>& matrix); // leetcode 329 11/14/22 记忆化搜索 ***

		int dfs_329(int x, int y);

		int countPaths(std::vector<std::vector<int>>& grid);  // leetcode 2328 11/15/22 记忆化搜索，与 leetcode 329 类似

		unsigned long long dfs_2328(int x, int y);

		bool canWin(std::string currentState);  // leetcode 294 11/20/22 DFS 没有记忆化的方法 效率较低 ***

		bool dfs_294(std::string& currentState);

		std::unordered_map<long long, bool> memo_294;
		bool canWin_(std::string currentState);  // 状态压缩，记忆化搜索 ***

		void dfs_294_(long long mask);

		bool canWin__(std::string currentState);  // 11/23/22 Sprague-Grundy 定理 ***

		int win__(int i);

		int countRoutes(std::vector<int>& locations, int start, int finish, int fuel);  // leetcode 1575 11/26/22 记忆化搜索 不会 ***

		void dfs_1575(int idx, int finish, int fuel, std::vector<int>& locations, std::vector<std::vector<int> >& fuels);

		int ways(std::vector<std::string>& pizza, int k);  // leetcode 1444 12/23/22 二维前缀和 记忆化搜索
		std::vector<std::vector<std::vector<int> > > mem;
		std::vector<std::vector<int> > p;

		int dfs_1444(int x, int y, int k);

	private:
		const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
		int m, n, len;
		std::vector<int> dis = { 0, 1, 0, -1, 0 }, sg;
		std::vector<std::vector<int> > memo, matrix;
	};

}

