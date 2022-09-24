#include <vector>
using namespace std;

class Notes
{
public:
	pair<int, int> minMax(vector<int>& nums);   // min and max in 3n / 2 times' comparison

private:

};

class Solution02
{
public:

private:

};

class NumMatrix // leetcode 304 9/24/22 2D prefix sum
{
public:
    NumMatrix(vector<vector<int> >& matrix);

    int sumRegion(int row1, int col1, int row2, int col2);

private:
    vector<vector<int> > sums;
};
