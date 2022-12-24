#include <iostream>
#include "Solution04.h"
using namespace std;

void test()
{
	vector<vector<int> > grid = { { 0, 1, -1 }, { 1, 0, -1 }, { 1, 1, 1 } };
	Solution solution;
	cout << solution.cherryPickup(grid) << endl;
}

int main(void)
{
	test();

}

