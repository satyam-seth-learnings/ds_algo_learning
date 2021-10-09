#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    string commonPrefixUtil(string str1,string str2)
    {
        int n1=str1.length();
        int n2=str2.length();
        int i=0,j=0;
        while(i<n1 && j<n2)
        {
            if(str1[i]!=str2[j])
                break;
            i++;
            j++;
        }
        return str1.substr(0,i);
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        string prefix=strs[0];
        for(int i=1;i<strs.size();i++)
            prefix=commonPrefixUtil(prefix,strs[i]);
        return prefix;
    }
};
// Logic-2
class Solution {
public:
    int findMinLenString(vector<string>& strs)
    {
        int minLen=strs[0].length();
        for(int i=0;i<strs.size();i++)
            if(minLen>strs[i].length())
                minLen=strs[i].length();
        return minLen;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        int minLen=findMinLenString(strs);
        string result;
        for(int i=0;i<minLen;i++)
        {
            char current=strs[0][i];
            for(int j=1;j<strs.size();j++)
                if(strs[j][i]!=current)
                    return result;
            result+=current;
        }
        return result;
    }
};
// Logic-3
class Solution {
public:
    int findMinLenString(vector<string>& strs)
    {
        int minLen=strs[0].length();
        for(int i=0;i<strs.size();i++)
            if(minLen>strs[i].length())
                minLen=strs[i].length();
        return minLen;
    }
    bool allCommonPrefix(vector<string>& strs,int low,int high)
    {
        string str1=strs[0];
        for(string word:strs)
            for(int i=low;i<=high;i++)
                if(word[i]!=str1[i])
                    return false;
        return true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        int minLen=findMinLenString(strs);
        string result;
        int low=0,high=minLen-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(allCommonPrefix(strs,low,mid))
            {
                result+=strs[0].substr(low,mid-low+1);
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return result;
    }
};
// Logic-4
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        int n=strs.size();
        sort(strs.begin(),strs.end());
        int end=min(strs[0].length(),strs[n-1].length());
        int i=0;
        while(i<end && strs[0][i]==strs[n-1][i])
            i++;
        return strs[0].substr(0,i);
    }
};
int main()
{
    // https://leetcode.com/problems/longest-common-prefix/
    return 0;
}