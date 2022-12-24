#pragma once
#include <vector>

class BinaryIndexedTree	// 树状数组（二叉索引树）
{
public:
	BinaryIndexedTree(int len);

	void update(int index, int value);

	int query(int index) const;

	int lowbit(int x) const;

private:
	int length;
	std::vector<int> v;
};
