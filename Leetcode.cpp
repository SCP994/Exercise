// Leetcode.cpp : Defines the entry point for the application.
//

#include "Leetcode.h"

using namespace std;

void test()
{
	vector<string> strs = { "babca","bbazb" };
	s04::Solution s;
	cout << s.minDeletionSize_(strs) << endl;
}

int main(void)
{
	test();

}

