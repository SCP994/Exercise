#include "main.h"

using namespace std;

void test()
{
	vector<vector<int> > cuboids = { { 50, 45, 20 }, { 95, 37, 53 }, { 45, 23, 12 } };
	s04::Solution solution;
	int ret;

	ret = solution.maxHeight(cuboids);
	cout << ret << endl;
}

int main(void)
{
	test();

}
