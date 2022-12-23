#include <iostream>
#include "Solution03.h"
#include <array>
#include <vector>
#include <string>
//#include "Notes.h"

struct ListNode {
	int val;
	struct ListNode* next;
};

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

template <typename T>
void printV(vector<T>& v)
{
	for (auto& i : v)
		cout << i << " ";
	cout << endl;
}

template <typename T>
void printVV(vector<vector<T> >& t)
{
	for (auto& i : t)
	{
		for (auto& j : i)
			cout << j << " ";
		cout << endl;
	}
}

void* test(void*)
{
	vector<string> pizza;
	pizza.push_back("A..");
	pizza.push_back("AA.");
	pizza.push_back("...");
	cout << Solution().ways(pizza, 3) << endl;
	return NULL;
}

void t(void* (*f)(void*))
{
	(*f)(NULL);
}

typedef void (*FUNC1)(void* (*)(void*));

void fun(char* str, int n)
{
	int len = strlen(str);
	n = n % len;
	if (n == 0) return;

	char* temp = (char*)malloc(sizeof(char) * n);
	for (int i = 0; i < n; ++i)
		temp[i] = str[len - n + i];
	for (int i = len - 1; i >= n; --i)
		str[i] = str[i - n];
	for (int i = 0; i < n; ++i)
		str[i] = temp[i];
	free(temp);
}

int main(void)
{
	FUNC1 p = t;
	p(test);



}

