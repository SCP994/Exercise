// Leetcode.cpp : Defines the entry point for the application.
//

#include "Leetcode.h"

using namespace std;

void test()
{
	vector<vector<int> > grid = { { 3, 1, 1 }, { 2, 5, 1 }, { 1, 5, 5 }, { 2, 1, 1 } };
	s04::Solution solution;
	cout << solution.cherryPickup_(grid) << endl;
}

int main(void)
{
	test();

}

