#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum=0,start=0,diff=0;
        for(int i=0;i<gas.size();i++)
        {
            sum=sum+gas[i]-cost[i];
            if(sum<0)
            {
                start=i+1;
                diff+=sum;
                sum=0;
            }
        }
        return sum+diff>=0?start:-1;
    }
};
int main()
{
    // https://leetcode.com/problems/gas-station/
    return 0;
}