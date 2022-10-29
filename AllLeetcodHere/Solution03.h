#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

typedef unsigned long long ull;

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

	int slidingPuzzle(vector<vector<int>>& board); // leetcode 773 10/27/22 A * 算法

	bool check(string& str);

	int f_773(string& state); // 估价函数

	int shortestPathLength(vector<vector<int>>& graph); // leetcode 847 10/29/22 BFS ***

private:
	const int inf = 0x3f3f3f3f;
};

