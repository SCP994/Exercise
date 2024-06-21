#include <vector>

class BinaryIndexedTree  // 树状数组（二叉索引树）
{
public:
	BinaryIndexedTree(int len);

	virtual void update(int index, int value);

	virtual int query(int index) const;

	int lowbit(int x) const;

protected:
	int length;
	std::vector<int> v;

};

