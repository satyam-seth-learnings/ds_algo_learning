#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0,valley=prices[0],peak=prices[0],max_profit=0;
        while(i<prices.size()-1)
        {
            while(i<prices.size()-1 && prices[i]>=prices[i+1])
                i++;
            int valley=prices[i];
            while(i<prices.size()-1 && prices[i]<=prices[i+1])
                i++;
            int peak=prices[i];
            max_profit+=peak-valley;
        }
        return max_profit;
    }
};
// Logic-2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=0;
        for(int i=1;i<prices.size();i++)
            if(prices[i]>prices[i-1])
                max_profit+=prices[i]-prices[i-1];
        return max_profit;
    }
};
int main()
{
    // https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
    return 0;
}