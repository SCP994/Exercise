// Leetcode.cpp : Defines the entry point for the application.
//

#include "Leetcode.h"

using namespace std;

void test()
{
	vector<vector<int> > grid = { { 3, 1, 1 }, { 2, 5, 1 }, { 1, 5, 5 }, { 2, 1, 1 } };
	Solution04 s04;
	cout << s04.cherryPickup_(grid) << endl;
}

int main(void)
{
	test();

}

