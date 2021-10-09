#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    int countOnes(int n)
    {
        int count=0;
        while(n>0)
        {
            n&=n-1;
            count+=1;
        }
        return count;
    }
    vector<int> countBits(int num) {
        vector<int> result;
        for(int i=0;i<=num;i++)
            result.push_back(countOnes(i));
        return result;
    }
};
// Logic-2
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num+1,0);
        for(int i=1;i<=num;i++)
            result[i]=result[i/2]+(i%2);
        return result;
    }
};
// Logic-3
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num+1,0);
        for(int i=1;i<=num;i++)
            result[i]=result[i & (i-1)]+1;
        return result;
    }
};
int main()
{
    // https://leetcode.com/problems/counting-bits/
    return 0;
}