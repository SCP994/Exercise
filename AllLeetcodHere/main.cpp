#include <iostream>
#include "Solution03.h"
//#include "Notes.h"

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
	string currentState = "++++";
	cout << Solution().canWin_(currentState) << endl;
	return NULL;
}

void t(void* (*f)(void*))
{
	(*f)(NULL);
}

typedef void (*FUNC1)(void* (*)(void*));

int main(void)
{
	FUNC1 p = t;
	p(test);
}

