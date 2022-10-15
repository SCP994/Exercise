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

void Notes::check()
{
	int i = 0b00000001000000100000010000001000;	// 如果是大端存储，数据低位保存到地址高位；小端存储，数据低位保存到地址低位
	int j = 0b00001000000001000000001000000001;
	int a = *(char*)&i;	// 取 int 四个字节中存储在地址低位的数字
	int b = *(char*)&j;
	cout << a << endl;	// 大端存储，值为 00000001；小端存储，值为 00001000
	cout << b << endl;	// 与 a 的输出正好相反
}

float Notes::testTime()
{
	auto t_start = chrono::high_resolution_clock::now();
	// 要测试的代码
	auto t_end = chrono::high_resolution_clock::now();
	float t_total = chrono::duration<float, std::milli>(t_end - t_start).count();
	std::cout << "1 detection and track total take: " << t_total << " ms." << std::endl;
	return t_total;
}

void Notes::malloc_free()
{
	char* ptr = (char*)malloc(8);
	if (!ptr)
		throw bad_alloc();
	for (int i = 0; i < 7; ++i)
		ptr[i] = 'a' + i;
	ptr[7] = '\0';
	cout << ptr << endl;	// abcdefg
	free(ptr);
}
