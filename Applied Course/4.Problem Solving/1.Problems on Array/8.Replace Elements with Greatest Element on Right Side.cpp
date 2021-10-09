#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        int max_ele=arr[n-1];
        arr[n-1]=-1;
        for(int i=n-2;i>=0;i--)
        {
            int temp=arr[i];
            arr[i]=max_ele;
            if(temp>max_ele)
                max_ele=temp;
        }
        return arr;
    }
};
int main()
{
    // https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
    return 0;
}