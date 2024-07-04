#include <vector>
#include <iostream>
#include <chrono>
#include <stack>
#include <deque>
#include <utility>
#include <algorithm>
#include <random>
#include <numeric>
#include <thread>
#include <execution>

#include <ppl.h>

namespace notes
{
	std::pair<int, int> minMax(std::vector<int>& nums);   // min and max in 3n / 2 times' comparison

	void check();	// 判断系统大小端存储

	void check_();

	float testTime();	// 测试代码运行时间

	void malloc_free();

	void fun(void* (*f)(void*));  // 传入函数指针

	void void_pointer(void* p);  // void 指针

	typedef struct ListNode
	{
		int val;
		struct ListNode* next;
	} ListNode;

	ListNode* ReverseList(struct ListNode* pHead);  // 翻转单链表

	template <typename T>
	class CLRValue  // 判断左右值
	{
	public:
		void printX(T& lValue);

		void printX(T&& rValue);

		void testRValue(T&& nValue);

		void test();

	};

	template<typename T>
	void CLRValue<T>::printX(T& lValue)
	{
		std::cout << "lValue" << lValue << std::endl;
	}

	template<typename T>
	void CLRValue<T>::printX(T&& rValue)
	{
		std::cout << "rValue" << rValue << std::endl;
	}

	template<typename T>
	void CLRValue<T>::testRValue(T&& nValue)
	{
		printX(nValue);
		printX(std::forward<T>(nValue));
		printX(move(nValue));
	}

	/*
		不管是左值引用、右值引用，std::forward 都会按照原来的类型完美转发
		forward 主要解决引用函数参数为右值时，传进来之后有了变量名就变成了左值
	*/
	template<typename T>
	void CLRValue<T>::test()
	{
		T nValue = 100;
		testRValue(4);  // 左 右 右
		testRValue(nValue);  // 左 左 右
		testRValue(std::forward<T>(nValue));  // 左 右 右
	}

	typedef struct TreeNode
	{
		TreeNode* left, * right;
		int value;
	} TreeNode;

	void pre_order(TreeNode* node);  // 先序遍历

	void in_order(TreeNode* node);  // 中序遍历

	void post_order(TreeNode* node);  // 后序遍历

	void BFS_tree(TreeNode* node);  // 广度优先遍历

	void DFS_tree(TreeNode* node);  // 深度优先遍历

	void testSort();

	void testSort_1();

	void testTime_1();
}

void testPPL();
