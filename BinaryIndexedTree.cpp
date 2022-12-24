#include "BinaryIndexedTree.h"

using namespace std;

BinaryIndexedTree::BinaryIndexedTree(int len)
    : length(len), v(len + 1) {}

void BinaryIndexedTree::update(int index, int value)
{
    while (index <= length)
    {
        v[index] += value;
        index += lowbit(index);
    }
}

int BinaryIndexedTree::query(int index) const
{
    int sum = 0;
    while (index > 0)
    {
        sum += v[index];
        index -= lowbit(index);
    }
    return sum;
}

int BinaryIndexedTree::lowbit(int x) const
{
    return x & -x;
}
