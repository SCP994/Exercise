#include "TrieTree.h"

TrieTree::TrieTree()
{
    tree.emplace_back();
}

void TrieTree::insert(string& s, int id)
{
    int len = s.size(), add = 0;
    for (int i = 0; i < len; ++i)
    {
        int t = s[i] - 'a';
        if (!tree[add].ch[t])
        {
            tree.emplace_back();
            tree[add].ch[t] = tree.size() - 1;
        }
        add = tree[add].ch[t];
    }
    tree[add].flag = id;
}

int TrieTree::findWord(string& s, int left, int right) const
{
    int add = 0;
    for (int i = right; i >= left; --i) // 查找是否存在倒序的子串
    {
        int t = s[i] - 'a';
        if (!tree[add].ch[t])
            return -1;
        add = tree[add].ch[t];
    }
    return tree[add].flag;
}

vector<int> TrieTree::query(string& str) const
{
    int len = str.size(), add = 0;
    vector<int> result(len + 1, -1);
    for (int i = 0; i < len; ++i)
    {
        int t = str[i] - 'a';
        result[i] = tree[add].flag;
        if (!tree[add].ch[t])
            return result;
        add = tree[add].ch[t];
    }
    result[len] = tree[add].flag;
    return result;
}

TrieTree::TrieNode::TrieNode()
    : flag(-1)
{
    memset(ch, 0, sizeof(ch));
}
