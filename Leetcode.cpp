// Leetcode.cpp : Defines the entry point for the application.
//

#include "Leetcode.h"

using namespace std;

void test()
{
	vector<vector<int> > envelopes = { {15,8},{2,20},{2,14},{4,17},{8,19},{8,9},{5,7},{11,19},{8,11},{13,11},{2,13},{11,19},{8,11},{13,11},{2,13},{11,19},{16,1},{18,13},{14,17},{18,19} };
	s04::Solution s;
	cout << s.maxEnvelopes(envelopes) << endl;
}

int main(void)
{
	test();

}

