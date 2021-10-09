#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int c=0;
        int z = flowerbed.size();
      
        for(int i =0;i<z;i++)
        {
            if(flowerbed[i]==0 && (i==0 || flowerbed[i-1]==0) && (i==z-1 || flowerbed[i+1]==0))
            {
                flowerbed[i]=1;
                c++;
            }
        }
        return c>=n;
    }
};
int main()
{
    // https://leetcode.com/problems/can-place-flowers/
    return 0;
}