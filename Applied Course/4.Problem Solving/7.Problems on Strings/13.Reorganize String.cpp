#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    string reorganizeString(string S) {
        int N = S.length();
        int counts[26]={0};
        int maxCount = 0;
        int maxCountIndex = -1;
        for(int i=0;i<N;i++){
            counts[S[i]-'a']+=1;
            if(maxCount < counts[S[i]-'a']) {
                maxCount = counts[S[i]-'a'];
                maxCountIndex = S[i]-'a';
            }
        }
        if (maxCount > (N + 1) / 2) return "";
        char outputStr[N];
        int index = 0;
        //first fill the character with max frequency, to handle cases where frequency is == n/2 +1 e.g vvvlo
        for(int j=0; j<counts[maxCountIndex]; j++){
            if(index >=N) index = 1;

            outputStr[index] = (char)(maxCountIndex +'a');
            index += 2;
        }

        for(int i=0; i< 26;i++){
            if(i== maxCountIndex) continue;

            char ch = (char) ('a'+i);
            for(int j=0; j<counts[i]; j++){
                if(index >=N) index = 1;

                outputStr[index] = ch;
                index += 2;
            }
        }
        string s = "";
        for(int i=0;i<N;i++)
            s+=outputStr[i];
        return s;
    }
};
// Logic-2
class Solution {
public:
    string reorganizeString(string S) {
        if(S.empty())
            return "";
        unordered_map<char,int> m;
        for(char ch:S)
            m[ch]++;
        priority_queue<pair<int,char>> max_heap;
        for(auto ele:m)
            max_heap.push({ele.second,ele.first});
        string result;
        pair<int,char> pre=max_heap.top();
        max_heap.pop();
        result+=pre.second;
        while(!max_heap.empty())
        {
            pair<int,char> current=max_heap.top();
            max_heap.pop();
            result+=current.second;
            pre.first-=1;
            if(pre.first>0)
                max_heap.push(pre);
            pre=current;
        }
        if(result.length()!=S.length())
            return "";
        return result;
    }
};
int main()
{
    // https://leetcode.com/problems/reorganize-string/
    return 0;
}