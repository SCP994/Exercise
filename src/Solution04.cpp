#include "Solution04.h"

using namespace std;

namespace s04
{
	Solution::Solution()
		: m(0), n(0), inf(0x3f3f3f3f) {}

	int Solution::cherryPickup(vector<vector<int> >& grid)
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

	int Solution::cherryPickup_(vector<vector<int>>& grid)
	{
		m = grid.size();
		n = grid[0].size();
		vector<vector<vector<int> > > dp(m, vector<vector<int> >(n, vector<int>(n, -inf)));  // 每个机器人最多走 m 步
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

	int Solution::lengthOfLIS(vector<int>& nums)
	{
		int n = nums.size();
		vector<int> dp(n);

		for (int i = 0; i < n; ++i)
		{
			int t = 1;
			for (int j = 0; j < i; ++j)
				if (nums[j] < nums[i]) t = max(t, dp[j] + 1);
			dp[i] = t;
		}

		int ret = 0;
		for (int i = 0; i < n; ++i)
			ret = max(ret, dp[i]);
		return ret;
	}

	int Solution::lengthOfLIS_(vector<int>& nums)
	{
		int n = nums.size(), size = 1;
		vector<int> d(n + 1);  // 长度为 i 最长上升子序列末尾元素的最小值，是单增数组
		d[1] = nums[0];

		for (int i = 0; i < n; ++i)
			if (nums[i] > d[size])
				d[++size] = nums[i];
			else
			{
				int s = 1, e = size;
				while (s <= e)
				{
					int m = (s + e) / 2;
					if (d[m] < nums[i])
						s = m + 1;
					else
						e = m - 1;
				}
				d[e + 1] = nums[i];
			}

		return size;
	}

	MyBITree::MyBITree(int len)
		: BinaryIndexedTree(len) {}

	void MyBITree::update(int index, int value)
	{
		while (index <= length)
		{
			v[index] = max(v[index], value);
			index += lowbit(index);
		}
	}

	int MyBITree::query(int index) const
	{
		int sum = 0;
		while (index > 0)
		{
			sum = max(sum, v[index]);
			index -= lowbit(index);
		}
		return sum;
	}

	int Solution::lengthOfLIS__(vector<int>& nums)
	{
		set<int> s(nums.begin(), nums.end());
		int idx = 1;
		unordered_map<int, int> m;
		for (int v : s) m[v] = idx++;  // 去重并排序，给每个数字进行编号
		MyBITree tree(m.size());  // 树状数组保存以某个值为结尾的最长上升子序列长度
		int ret = 1;
		for (int v : nums)
		{
			int x = m[v];
			int t = tree.query(x - 1) + 1;
			ret = max(ret, t);
			tree.update(x, t);
		}
		return ret;
	}

	int Solution::eraseOverlapIntervals(vector<vector<int>>& intervals)  // O(nlogn)
	{
		int n = intervals.size(), ret = 0;
		sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) { return a[1] < b[1]; });  // 一定要按右边界排序
		int t = intervals[0][1];
		for (int i = 1; i < n; ++i)
			if (intervals[i][0] >= t)
				t = intervals[i][1];
			else
				++ret;
		return ret;
	}

	int Solution::eraseOverlapIntervals_(std::vector<std::vector<int>>& intervals)  // O(n^2) 超时
	{
		int n = intervals.size();
		sort(intervals.begin(), intervals.end());
		vector<int> dp(n, 1);  // 以区间 i 为最后的一个区间，可以选出的区间数量的最大值
		for (int i = 1; i < n; ++i)
			for (int j = 0; j < i; ++j)
				if (intervals[j][1] <= intervals[i][0])
					dp[i] = max(dp[i], dp[j] + 1);
		return n - *max_element(dp.begin(), dp.end());
	}

	int Solution::minDeletionSize(vector<string>& strs)
	{
		m = strs.size();
		n = strs[0].size();
		int sign = 0;
		vector<vector<bool> > dp(n + 1, vector<bool>(n));  // 记录长度为 1 到 n 时，以各个位置的字符作为最后一个字符能否构成长度为 1 - n 的单增字符串

		for (int i = 0; i < n; ++i)
			dp[1][i] = true;

		for (int i = 2; i <= n; ++i)
		{
			for (int j = i - 1; j < n; ++j)
				if (dp[i - 1][j - 1])
					for (int k = j; k < n; ++k)
						if (judge_960(strs, j - 1, k))
						{
							dp[i][k] = true;
							sign = 1;
						}
			if (sign == 0)
				return n - i + 1;
			sign = 0;
		}
		return 0;
	}

	bool Solution::judge_960(std::vector<std::string>& strs, int x, int y)
	{
		for (string& str : strs)
			if (str[x] > str[y]) return false;
		return true;
	}

	int Solution::minDeletionSize_(std::vector<std::string>& strs)
	{
		int n = strs[0].size(), ret = 1;  // ret 最小为 1
		vector<int> dp(n, 1);

		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
				if (judge_960(strs, j, i))
					dp[i] = max(dp[i], dp[j] + 1);
			ret = max(ret, dp[i]);
		}
		return n - ret;
	}

	int Solution::maxEnvelopes(vector<vector<int>>& envelopes)
	{
		int n = envelopes.size();
		sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b)
			{
				return a[0] < b[0] || a[0] == b[0] && a[1] > b[1];
			});

		vector<int> dp{ envelopes[0][1] };
		for (int i = 1; i < n; ++i)
		{
			int x = envelopes[i][1];
			if (dp[dp.size() - 1] < x)
				dp.push_back(x);
			else
			{
				int s = 0, e = dp.size() - 1;
				while (s <= e)
				{
					int m = (s + e) / 2;
					if (dp[m] < x) s = m + 1;
					else e = m - 1;
				}
				dp[s] = x;
			}
		}
		return dp.size();
	}

	int Solution::maxHeight(std::vector<std::vector<int>>& cuboids)
	{
		int n = cuboids.size();
		vector<int> dp(n);
		auto func = [](vector<int>& v1, vector<int>& v2) -> bool
		{
			if (v1[0] <= v2[0] && v1[1] <= v2[1] && v1[2] <= v2[2])
				return true;
			return false;
		};

		for (auto &i : cuboids)
			sort(i.begin(), i.end());
		sort(cuboids.begin(), cuboids.end());

		for (int i = 0; i < n; ++i)
		{
			dp[i] = cuboids[i][2];
			for (int j = i - 1; j >= 0; --j)
				if (func(cuboids[j], cuboids[i]))
					dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
		}

		for (const auto i : cuboids)
		{
			for (const auto j : i)
				cout << j << " ";
			cout << endl;
		}

		return *max_element(dp.begin(), dp.end());
	}

}

