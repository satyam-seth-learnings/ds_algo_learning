#include<bits/stdc++.h>
using namespace std;
const int MAX_ALPHABET = 26; // only lowercase

struct TrieNode {
    bool finished;
    TrieNode* childrens[MAX_ALPHABET]; // point 26 TrieNodes 
    TrieNode() : finished(false) {
        fill(&childrens[0], &childrens[MAX_ALPHABET], nullptr);
    }
};

class Trie {
public:
    TrieNode* root = nullptr;
    
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curNode = this->root;
        for (char ch : word) {
            if (!curNode->childrens[ch - 'a']) {
                curNode->childrens[ch - 'a'] = new TrieNode();
            }
            curNode = curNode->childrens[ch - 'a'];
        }
        curNode->finished = true;
    }
    
    bool search(string word) {
        TrieNode* curNode = this->root;
        for (char ch : word) {
            if(!curNode->childrens[ch - 'a'])
                return false;
            curNode = curNode->childrens[ch - 'a'];
        }
        return curNode->finished;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curNode = this->root;
        for (char ch : prefix) {
            if(!curNode->childrens[ch - 'a'])
                return false;
            curNode = curNode->childrens[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int main()
{
    // https://leetcode.com/problems/implement-trie-prefix-tree
    return 0;
}