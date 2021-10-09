#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(int x,int y)
    {
        if(x%y==0)
            return y;
        else
            return helper(y,x%y);
    }
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if(targetCapacity<0 || targetCapacity>jug1Capacity+jug2Capacity)   
            return false;
        int minPossible=helper(jug1Capacity,jug2Capacity);
        if(targetCapacity%minPossible==0)
            return true;
        else
            return false;
    }
};
int main()
{
    // https://leetcode.com/problems/water-and-jug-problem/ 
    return 0;
}