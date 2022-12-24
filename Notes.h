#pragma once
#include <vector>
#include <iostream>
#include <chrono>
#include <stack>
#include <deque>

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

struct ListNode* ReverseList(struct ListNode* pHead);  // 翻转单链表

template <typename T>
class CLRValue  // 判断左右值
{
public:
	void printX(T& lValue);

	void printX(T&& rValue);

	void testRValue(T&& nValue);

	void test();

};

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

