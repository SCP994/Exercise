#pragma once
#include <vector>
#include <iostream>
#include <chrono>

std::pair<int, int> minMax(std::vector<int>& nums);   // min and max in 3n / 2 times' comparison

void check();	// 判断系统大小端存储

void check_();

float testTime();	// 测试代码运行时间

void malloc_free();

void fun(void* (*f)(void*));  // 传入函数指针

void void_pointer(void* p);  // void 指针

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* ReverseList(struct ListNode* pHead);  // 翻转单链表

template <typename T>
class CLRValue
{
public:
	void printX(T& lValue);

	void printX(T&& rValue);

	void testRValue(T&& nValue);

	void test();

};

