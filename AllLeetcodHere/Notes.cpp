#include "Notes.h"

pair<int, int> Notes::minMax(vector<int>& nums)
{
	size_t len = nums.size();
	int mi, ma, i = 1;
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
