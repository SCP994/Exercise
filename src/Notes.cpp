#include "Notes.h"

using namespace std;

namespace notes
{
	pair<int, int> minMax(vector<int>& nums)
	{
		size_t len = nums.size();
		int mi, ma, i = 1;
		if (len == 0)
			throw;
		if (len == 1)
			return { nums[0], nums[0] };
		if (len == 2)
			return { min(nums[0], nums[1]), max(nums[0], nums[1]) };

		if (len % 2 == 1)
			mi = ma = nums[0];
		else
		{
			mi = min(nums[0], nums[1]);
			ma = max(nums[0], nums[1]);
			i = 2;
		}
		for (; i < len - 1; ++i)	// only 3n / 2 times comparison not 2n
			if (nums[i] < nums[i + 1])
			{
				if (nums[i] < mi) mi = nums[i];
				if (nums[i + 1] > ma) ma = nums[i + 1];
			}
			else
			{
				if (nums[i + 1] < mi) mi = nums[i + 1];
				if (nums[i] > ma) ma = nums[i];
			}
		return { mi, ma };
	}

	void check()
	{
		int i = 0b00000001000000100000010000001000;	// 如果是大端存储，数据低位保存到地址高位；小端存储，数据低位保存到地址低位
		int j = 0b00001000000001000000001000000001;
		int a = *(char*)&i;	// 取 int 四个字节中存储在地址低位的数字
		int b = *(char*)&j;
		cout << a << endl;	// 大端存储，值为 00000001；小端存储，值为 00001000
		cout << b << endl;	// 与 a 的输出正好相反
	}

	void check_()
	{
		union UN
		{
			int i;
			char c;
		} un;
		un.i = 0x11223344;
		un.c = 0x55;
		printf("%x\n", un.i); // 小端：11223355，大端：55223344
	}

	float testTime()
	{
		auto t_start = chrono::high_resolution_clock::now();
		// 要测试的代码
		auto t_end = chrono::high_resolution_clock::now();
		float t_total = chrono::duration<float, std::milli>(t_end - t_start).count();
		std::cout << "1 detection and track total take: " << t_total << " ms." << std::endl;
		return t_total;
	}

	void malloc_free()
	{
		char* ptr = (char*)malloc(8);
		if (!ptr)
			throw bad_alloc();
		for (int i = 0; i < 7; ++i)
			ptr[i] = 'a' + i;
		ptr[7] = '\0';
		cout << ptr << endl;	// abcdefg
		free(ptr);
	}

	void fun(void* (*f)(void*))
	{
		(*f)(NULL);
	}

	void void_pointer(void* p)
	{
		int t = *(int*)p;  // 将 p 转换为 int 指针，这样才知道要取四个字节
	}

	struct ListNode* ReverseList(struct ListNode* pHead)
	{
		if (pHead == nullptr || pHead->next == nullptr) return pHead;

		struct ListNode* temp = pHead->next, * ret = nullptr;
		while (temp)
		{
			temp = pHead->next;
			pHead->next = ret;
			ret = pHead;
			pHead = temp;
		}
		return ret;
	}

	void pre_order(TreeNode* node)
	{
		stack<TreeNode*> s;
		s.emplace(node);
		while (!s.empty())
		{
			TreeNode* p = s.top();
			s.pop();
			cout << p->value << endl;
			if (p->right) s.emplace(p->right);
			if (p->left) s.emplace(p->left);
		}
	}

	void in_order(TreeNode* node)
	{
		stack<TreeNode*> s;
		while (node)
		{
			s.emplace(node);
			node = node->left;
		}
		while (!s.empty())
		{
			TreeNode* p = s.top();
			s.pop();
			cout << p->value << endl;
			p = p->right;
			while (p)
			{
				s.emplace(p);
				p = p->left;
			}
		}
	}

	void post_order(TreeNode* node)
	{
		stack<TreeNode*> s;
		TreeNode* temp = nullptr;  // 辅助结点，判断右子树是否已经被访问过
		while (node)
		{
			s.emplace(node);
			node = node->left;
		}
		while (!s.empty())
		{
			TreeNode* p = s.top();
			if (!p->right || temp == p->right)  // 不存在右子树或者右子树被访问过，则打印当前结点并弹出
			{
				cout << p->value << endl;
				temp = p;
				s.pop();
			}
			else
			{
				p = p->right;
				while (p)
				{
					s.emplace(p);
					p = p->left;
				}
			}
		}
	}

	void BFS_tree(TreeNode* node)
	{
		deque<TreeNode*> q;
		q.emplace_back(node);
		while (!q.empty())
		{
			TreeNode* p = q.front();
			q.pop_front();
			cout << p->value << endl;
			if (p->left) q.emplace_back(p->left);
			if (p->right) q.emplace_back(p->right);
		}
	}

	void DFS_tree(TreeNode* node)
	{
		stack<TreeNode*> s;
		s.emplace(node);
		while (!s.empty())
		{
			TreeNode* p = s.top();
			s.pop();
			cout << p->value << endl;
			if (p->right) s.emplace(p->right);
			if (p->left) s.emplace(p->left);
		}
	}

	void testSort()
	{
		int arr[] = { 1, 8, 3, 4, 7, 6, 5, 2 };
		int n = sizeof(arr) / sizeof(int);

		for (int i = 0; i < n; ++i)
		{
			if (i)
				printf(" ");
			printf("%d", arr[i]);
		}
		printf("\n");

		for (int k = 2; k <= n; k *= 2)
			for (int j = k / 2; j > 0; j /= 2)
				for (int i = 0; i < n; ++i)
				{
					int l = i ^ j;
					if (l > i)
					{
						if ((i & k) == 0 && arr[i] > arr[l] || (i & k) != 0 && arr[i] < arr[l])
							swap(arr[i], arr[l]);
					}
				}

		for (int i = 0; i < n; ++i)
		{
			if (i)
				printf(" ");
			printf("%d", arr[i]);
		}
		printf("\n");
	}

	void testSort_1()
	{
		std::vector<int> vec(20);
		// 使用iota填充从0开始的连续整数
		std::iota(vec.begin(), vec.end(), 0);
		// 使用默认随机数生成器打乱顺序
		std::shuffle(vec.begin(), vec.end(), std::mt19937{std::random_device{}()});
		// 输出排序前的结果
		for (int num : vec) {
			std::cout << num << " ";
		}
		std::cout << "                      " <<std::endl;
		std::cout << "                      " <<std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		// 使用并行算法进行排序
		// std::sort(std::execution::par, vec.begin(), vec.end());

		// 输出排序后的结果
		for (int num : vec) {
			std::cout << num << " ";
		}
		std::cout << std::endl;
	}

	void sleep()
	{
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}

	void testTime_1()
	{
		auto startTime = std::chrono::high_resolution_clock::now();

		sleep();
		sleep();

		auto stopTime = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);

		std::cout << "Duration: " << duration.count() / 1e6 << "s" << std::endl;
	}
}

void testPPL()
{
	// concurrency::parallel_for(0, 20, [](int x)
	// {
	// 	printf("%d ", x);
	// });
}
