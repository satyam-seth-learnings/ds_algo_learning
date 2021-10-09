# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
# Logic-1
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        def calculateProfit(prices,start):
            if start>=len(prices):
                return 0
            total_profit=0
            for i in range(start,len(prices)):
                max_profit=0
                for j in range(i+1,len(prices)):
                    if prices[i]<prices[j]:
                        profit=calculateProfit(prices,j+1)+prices[j]-prices[i]
                        if profit>max_profit:
                            max_profit=profit
                if max_profit>total_profit:
                    total_profit=max_profit
            return total_profit
        return calculateProfit(prices,0)
# Logic-2
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        i=0
        valley=prices[0]
        peak=prices[0]
        max_profit=0
        while i<len(prices)-1:
            while i<len(prices)-1 and prices[i]>=prices[i+1]:
                i+=1
            valley=prices[i]
            while i<len(prices)-1 and prices[i]<=prices[i+1]:
                i+=1
            peak=prices[i]
            max_profit+=peak-valley
        return max_profit
# Logic-3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit=0
        for i in range(1,len(prices)):
            if prices[i]>prices[i-1]:
                max_profit+=prices[i]-prices[i-1]
        return max_profit