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
	vector<vector<int> > vs = { {110, 2321, 3278, 8282, 227, 2736, 1545, 0, 8538, 899},{395, 8253, 8986, 9589, 6700, 5707, 0, 0, 350, 1667},{244, 6561, 4748, 4069, 1267, 4109, 0, 3209, 1101, 7797},{6718, 7970, 0, 7873, 5902, 4079, 4619, 262, 0, 5337} };
	cout << s.cutOffTree(vs) << endl;
}

int main(void)
{

	test();
}

