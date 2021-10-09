#include<bits/stdc++.h>
using namespace std;
class WordDictionary {
public:
    /** Initialize your data structure here. */
    unordered_map<int,unordered_set<string>> lenToWords;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        int len = word.length();
        lenToWords[len].insert(word);
    }
    
    bool search(string word) {
        int len = word.length(); 
        // if no word of such length return
        if(lenToWords.find(len) == lenToWords.end()) return false;
        
        // in case of no '.' characters the word could be directly searched
        if(word.find('.') == string::npos){
            return (lenToWords[len]).count(word) > 0;
        }
        for(auto it = lenToWords[len].begin(); it != lenToWords[len].end(); it++){
            if(isMatch(*it,word)) return true;
        }
        return false;
        
    }
    
    bool isMatch(string s1, string s2){
        for(int i=0; i<s1.length();i++){
            if(s2[i]=='.' or s1[i] == s2[i]) continue;
            else return false; 
        }
        return true;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
int main()
{
    // https://leetcode.com/problems/design-add-and-search-words-data-structure/
    return 0;
}