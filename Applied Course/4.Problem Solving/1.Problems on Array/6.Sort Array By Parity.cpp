#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> ans;
        for(auto ele:A)
            if(ele%2==0)
                ans.push_back(ele);
        for(auto ele:A)
            if(ele%2!=0)
                ans.push_back(ele);
        return ans;
    }
};
// Logic-2
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i=0,j=A.size()-1;
        while(i<j)
        {
            if(A[i]%2!=0)
            {
                swap(A[i],A[j]);
                j--;
            }
            else
                i++;
        }
        return A;
    }
};
// Logic-3
int main()
{
    // https://leetcode.com/problems/sort-array-by-parity/  
    return 0;
}