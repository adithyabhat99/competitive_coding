// https://leetcode.com/problems/word-search-ii/submissions/
#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    vector<TrieNode *> links;
    string word;
    TrieNode() : word(""), links(vector<TrieNode *>(26, NULL)) {}
};
class Solution
{
public:
    Solution()
    {
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        TrieNode *root = new TrieNode();
        root = buildTrie(words, root);
        vector<string> res;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                dfs(board, i, j, root, res);
            }
        }
        return res;
    }
    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *p, vector<string> &res)
    {
        char c = board[i][j];
        if (c == '#' || p->links[c - 'a'] == NULL)
            return;
        p = p->links[c - 'a'];
        if (p->word.length() != 0)
        {
            res.push_back(p->word);
            p->word = "";
        }
        board[i][j] = '#';
        if (i > 0)
            dfs(board, i - 1, j, p, res);
        if (j > 0)
            dfs(board, i, j - 1, p, res);
        if (i < board.size() - 1)
            dfs(board, i + 1, j, p, res);
        if (j < board[0].size() - 1)
            dfs(board, i, j + 1, p, res);
        board[i][j] = c;
    }
    TrieNode *buildTrie(vector<string> &words, TrieNode *root)
    {
        for (int i = 0; i < words.size(); i++)
        {
            TrieNode *node = root;
            for (int j = 0; j < words[i].length(); j++)
            {
                char c = words[i][j];
                int k = c - 'a';
                if (node->links[k] == NULL)
                    node->links[k] = new TrieNode();
                node = node->links[k];
            }
            node->word = words[i];
        }
        return root;
    }
};