#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> let,dig;
        for(auto& i:logs) {
            if(isalpha(i[i.find(' ')+1])) 
                let.push_back(i);
            else 
                dig.push_back(i);
        }
        sort(let.begin(),let.end(),[](const string& s1, const string& s2) {
            size_t p1=s1.find(' ')+1, p2=s2.find(' ')+1;
            int res=s1.substr(p1).compare(s2.substr(p2));
            if(res<0) 
                return true;
            else if(res>0) 
                return false;
            return s1.substr(0,p1-1).compare(s2.substr(0,p2-1)) < 0;
        });
        int pos=-1;
        for(auto& i:let) 
            logs[++pos]=i;
        for(auto& i:dig) 
            logs[++pos]=i;
        return logs;
    }
};
int main()
{
    // https://leetcode.com/problems/reorder-data-in-log-files
    return 0;
}