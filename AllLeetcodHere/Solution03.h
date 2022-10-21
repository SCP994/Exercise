#pragma once
#include <vector>
#include <deque>
#include <unordered_map>
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

private:
	const int inf = 0x3f3f3f3f;
};
