#include <iostream>
#include <vector>
using namespace std;

class MyLinkedList {	// leetcode 707
public:
	MyLinkedList()
		: m_head(new Node()), m_len(0) {}

	~MyLinkedList()
	{
		while (m_head)
		{
			Node* temp = m_head;
			m_head = m_head->next;
			delete temp;
		}
	}

	int get(int index) {
		if (index >= m_len)
			return -1;

		Node* temp = m_head->next;
		for (int i = 0; i < index; ++i)
		{
			temp = temp->next;
		}
		return temp->val;
	}

	void addAtHead(int val) {
		Node* temp = new Node(val);
		temp->next = m_head->next;
		m_head->next = temp;
		++m_len;
	}

	void addAtTail(int val) {
		Node* temp = m_head;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = new Node(val);
		++m_len;
	}

	void addAtIndex(int index, int val) {
		if (index > m_len)	// 注意不是>=，因为允许在末尾添加元素
			return;
		Node* temp = m_head;
		for (int i = 0; i < index; ++i)
		{
			temp = temp->next;
		}
		Node* ins = new Node(val);
		ins->next = temp->next;
		temp->next = ins;
		++m_len;
	}

	void deleteAtIndex(int index) {
		if (index >= m_len)
			return;

		Node* temp = m_head;
		for (int i = 0; i < index; ++i)
		{
			temp = temp->next;
		}
		Node* del = temp->next;
		temp->next = temp->next->next;
		delete del;
		--m_len;
	}

	void print()
	{
		Node* temp = m_head->next;
		cout << "len: " << m_len << ", all: ";
		while (temp)
		{
			cout << temp->val << ", ";
			temp = temp->next;
		}
		cout << endl;
	}

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

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {	// leetcode 64	// 进阶版，允许各个方向的移动 *
		int m = grid.size(), n = grid[0].size();
		vector<vector<int> > dis(m, vector<int>(n, 0));	// m 行 n 列的值全为 0 的二维向量

		dis[0][0] = grid[0][0];
		for (int i = 1; i < n; ++i)
		{
			dis[0][i] = dis[0][i - 1] + grid[0][i];
		}
		for (int i = 1; i < m; ++i)
		{
			dis[i][0] = dis[i - 1][0] + grid[i][0];
		}

		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				dis[i][j] = min(dis[i - 1][j], dis[i][j - 1]) + grid[i][j];
			}
		}

		return dis[m - 1][n - 1];
	}
	int min(int a, int b)
	{
		return a < b ? a : b;
	}

	vector<vector<int>> generate(int numRows) {	// leetcode 118
		vector<vector<int> > result(numRows);	// 向量这里的numRows可以为变量
		for (int i = 0; i < numRows; ++i)
		{
			vector<int> temp(i + 1);
			result[i] = temp;
		}
		result[0][0] = 1;

		for (int i = 1; i < numRows; ++i)
		{
			result[i][0] = 1;
			result[i][i] = 1;
			for (int j = 1; j < i; ++j)
			{
				result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
			}
		}
		return result;
	}
	//vector<vector<int>> generate(int numRows) {	// 参考答案
	//	vector<vector<int>> ans;
	//	for (int i = 0; i < numRows; ++i) {
	//		vector<int> t(i + 1, 1);	// 了解这种初始化方法
	//		for (int j = 1; j < i; ++j) t[j] = ans[i - 1][j] + ans[i - 1][j - 1];
	//		ans.push_back(t);	// push_back更快
	//	}
	//	return ans;
	//}

	vector<int> searchRange(vector<int>& nums, int target) {	// leetcode 34 *
		int len = nums.size();

		vector<int> result(2);
		result[0] = -1;
		result[1] = -1;
		int start = 0, end = 0;
		int p = 0, q = len - 1;

		while (p <= q)
		{
			if (nums[(p + q) / 2] < target)	// 应该使用找到最左下标的方法
				p = (p + q) / 2 + 1;
			else if (nums[(p + q) / 2] > target)
				q = (p + q) / 2 - 1;
			else
			{
				result[0] = (p + q) / 2;
				result[1] = (p + q) / 2;

				end = result[1] + 1;
				while (end <= q)
				{
					if (nums[(end + q) / 2] > target)
						q = (end + q) / 2 - 1;
					else if (nums[(end + q) / 2] == target)
					{
						result[1] = (end + q) / 2;
						end = result[1] + 1;
					}
				}
				start = result[0] - 1;
				while (p <= start)
				{
					if (nums[(start + p) / 2] < target)
						p = (start + p) / 2 + 1;
					else if (nums[(start + p) / 2] == target)
					{
						result[0] = (start + p) / 2;
						start = result[0] - 1;
					}
				}
				break;
			}
		}
		return result;
	}

	int minCostClimbingStairs(vector<int>& cost) {	// leetcode 746
		int len = cost.size();
		int* dp = new int[len + 1];
		dp[0] = 0;
		dp[1] = 0;
		for (int i = 2; i < len + 1; ++i)
		{
			if (dp[i - 1] + cost[i - 1] < dp[i - 2] + cost[i - 2])	// 状态转移方程
				dp[i] = dp[i - 1] + cost[i - 1];
			else
				dp[i] = dp[i - 2] + cost[i - 2];
		}
		return dp[len];
	}

	int climbStairs(int n) {	// leetcode 70
		if (n <= 2)
			return n;

		int p = 1, q = 1, r = 2;
		for (int i = 2; i < n; ++i)
		{
			p = q;
			q = r;
			r = p + q;
		}
		return r;
	}
};

/* notes
	vector<int> a(2, 8); // 这样生成含有两个元素且值为8的向量


*/

void test1()
{

}

int main(void)
{
	test1();
}