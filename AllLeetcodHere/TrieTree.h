#pragma once
#include <vector>
#include <string>
using namespace std;

class TrieTree	// 字典树（前缀树）
{
public:
	TrieTree();

	void insert(string& str, int id);

	int findWord(string& str, int left, int right) const;	// leetcode 336

	vector<int> query(string& str) const;	// leetcode 336

private:
	struct TrieNode	// 字典树节点
	{
		int ch[26];
		int flag;
		TrieNode();
	};
	std::vector<TrieNode> tree;
};
