#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool no_common_letters(string word1,string word2)
    {
        for(char c:word1)
            if(word2.find(c)!=string::npos)
                return false;
        return true;
    }
    int maxProduct(vector<string>& words) {
        int n=words.size();
        int max_val=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(no_common_letters(words[i],words[j]))
                {
                    int len=words[i].length()*words[j].length();
                    max_val=max(max_val,len);   
                }
            }
        }
        return max_val;
    }
};
int main()
{
    // https://leetcode.com/problems/maximum-product-of-word-lengths/
    return 0;
}