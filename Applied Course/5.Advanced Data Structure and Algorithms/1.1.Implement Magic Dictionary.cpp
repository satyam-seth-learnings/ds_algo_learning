#include<bits/stdc++.h>
using namespace std;
class MagicDictionary {
public:
    unordered_map<int, vector<string>> mp;
    MagicDictionary() {}

    void buildDict(vector<string> dictionary) {
        for(string s :  dictionary) {
            mp[s.length()].push_back(s);
        }
    }

    bool search(string searchWord) {

        if(mp[searchWord.length()].empty()) 
            return false;

        for(string &s:mp[searchWord.length()]) {
            int cnt = 0;
            for(int i = 0; i<s.length(); i++) {
                if(s[i] != searchWord[i]) cnt++;
                if(cnt>1)
                    break;
            }
            if(cnt == 1)
                return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
int main()
{
    // https://leetcode.com/problems/implement-magic-dictionary/
    return 0;
}