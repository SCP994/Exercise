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

void test()
{
	Solution s;
	vector<string> vs = { "hot","dot","dog","lot","log","cog" };
	cout << s.ladderLength("hit", "cog", vs) << endl;
}

int main(void)
{

	test();
}

