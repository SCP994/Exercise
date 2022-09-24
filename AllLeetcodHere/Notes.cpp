#include "Notes.h"

pair<int, int> Notes::minMax(vector<int>& nums)
{
	int len = nums.size(), mi, ma, i = 1, temp;
	if (len == 0)
		throw;
	if (len == 1)
		return { nums[0], nums[0] };
	if (len == 2)
		return { min(nums[0], nums[1]), max(nums[0], nums[1]) };

	if (len % 2 == 1)
		mi = ma = nums[0];
	else
	{
		mi = min(nums[0], nums[1]);
		ma = max(nums[0], nums[1]);
		i = 2;
	}
	for (; i < len - 1; ++i)	// only 3n / 2 times comparison not 2n
		if (nums[i] < nums[i + 1])
		{
			if (nums[i] < mi) mi = nums[i];
			if (nums[i + 1] > ma) ma = nums[i + 1];
		}
		else
		{
			if (nums[i + 1] < mi) mi = nums[i + 1];
			if (nums[i] > ma) ma = nums[i];
		}
	return { mi, ma };
}

NumMatrix::NumMatrix(vector<vector<int> >& matrix)
{
	int len1 = matrix.size(), len2 = matrix[0].size();
	sums = vector<vector<int> >(len1 + 1, vector<int>(len2 + 1, 0));
	for (int i = 0; i < len1; ++i)
		for (int j = 0; j < len2; ++j)
			sums[i + 1][j + 1] = sums[i + 1][j] + sums[i][j + 1] - sums[i][j] + matrix[i][j];	// careful here
}

int NumMatrix::sumRegion(int rol1, int col1, int rol2, int col2)
{
	return sums[rol2 + 1][col2 + 1] - sums[rol2 + 1][col1] - sums[rol1][col2 + 1] + sums[rol1][col1];
}
