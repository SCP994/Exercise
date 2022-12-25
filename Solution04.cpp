#include "Solution04.h"

using namespace std;

Solution04::Solution04()
	: m(0), n(0), inf(0x3f3f3f3f) {}

int Solution04::cherryPickup(vector<vector<int> >& grid)
{
	if (grid[0][0] == -1) return 0;
	n = grid.size();
	vector<vector<vector<int> > > dp(n * 2, vector<vector<int> >(n, vector<int>(n, -inf)));
	dp[0][0][0] = grid[0][0];
	for (int k = 1; k < n * 2 - 1; ++k)  // k 代表走过的步数
		for (int i1 = 0; i1 < n; ++i1)
			for (int i2 = 0; i2 < n; ++i2)
			{
				int j1 = k - i1, j2 = k - i2;
				if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1) continue;
				int t = grid[i1][j1];
				if (i1 != i2) t += grid[i2][j2];
				for (int x1 = i1 - 1; x1 <= i1; ++x1)  // 从四种情况转移而来
					for (int x2 = i2 - 1; x2 <= i2; ++x2)
						if (x1 >= 0 && x2 >= 0)
							dp[k][i1][i2] = max(dp[k][i1][i2], dp[k - 1][x1][x2] + t);
			}
	return max(0, dp[n * 2 - 2][n - 1][n - 1]);
}

int Solution04::cherryPickup_(vector<vector<int>>& grid)
{
	m = grid.size();
	n = grid[0].size();
	vector<vector<vector<int> > > dp(m, vector<vector<int> >(n, vector<int>(n, -inf)));  // 每个机器人做多走 m 步
	dp[0][0][n - 1] = grid[0][0] + grid[0][n - 1];
	if (n == 1) dp[0][0][n - 1] >>= 1;

	for (int steps = 1; steps < m; ++steps)  // 步数即代表着行数
		for (int j1 = 0; j1 <= steps; ++j1)  // 两个机器人的活动范围是一个三角形
		{
			if (j1 >= n) continue;
			int ret = grid[steps][j1];
			grid[steps][j1] = 0;
			for (int j2 = n - 1 - steps; j2 < n; ++j2)
			{
				if (j2 < 0) continue;
				ret += grid[steps][j2];
				for (int j1_up = j1 - 1; j1_up <= j1 + 1; ++j1_up)
					for (int j2_up = j2 - 1; j2_up <= j2 + 1; ++j2_up)
						if (j1_up < 0 || j2_up < 0 || j1_up >= n || j2_up >= n) continue;
						else dp[steps][j1][j2] = max(dp[steps][j1][j2], ret + dp[steps - 1][j1_up][j2_up]);
				ret -= grid[steps][j2];  // 恢复
			}
			grid[steps][j1] = ret;  // 恢复
		}

	int ret = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			ret = max(ret, dp[m - 1][i][j]);
	return ret;
}

