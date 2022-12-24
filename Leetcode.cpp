// Leetcode.cpp : Defines the entry point for the application.
//

#include "Leetcode.h"

void test()
{
	std::vector<std::vector<int> > grid = { { 0, 1, -1 }, { 1, 0, -1 }, { 1, 1, 1 } };
	Solution04 s04;
	std::cout << s04.cherryPickup(grid) << std::endl;
}

int main(void)
{
	test();

}

