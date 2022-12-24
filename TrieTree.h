#pragma once
#include <vector>
#include <string>
#include <cstring>  // memset

class TrieTree	// 字典树（前缀树）
{
public:
	TrieTree();

	void insert(std::string& str, int id);

	int findWord(std::string& str, int left, int right) const;	// leetcode 336

	std::vector<int> query(std::string& str) const;	// leetcode 336

private:
	struct TrieNode	// 字典树节点
	{
		int ch[26];
		int flag;
		TrieNode();
	};
	std::vector<TrieNode> tree;
};
