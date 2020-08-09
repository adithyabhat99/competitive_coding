// https://leetcode.com/problems/implement-trie-prefix-tree/submissions/
#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
private:
    vector<TrieNode *> links;
    int R;
    bool isEnd;

public:
    TrieNode()
    {
        R = 26;
        links.assign(R, NULL);
        isEnd = false;
    }
    bool containsKey(char c)
    {
        return links[c - 'a'] != NULL;
    }
    TrieNode *get(char c)
    {
        return links[c - 'a'];
    }
    void put(char c, TrieNode *node)
    {
        links[c - 'a'] = node;
    }
    void setEnd()
    {
        isEnd = true;
    }
    bool getEnd()
    {
        return isEnd;
    }
};
class Trie
{
public:
    /** Initialize your data structure here. */
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new TrieNode());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    TrieNode *searchPrefix(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return NULL;
            }
        }
        return node;
    }
    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *node = searchPrefix(word);
        return node != NULL && node->getEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        return searchPrefix(prefix) != NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */