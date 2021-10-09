# https://leetcode.com/problems/single-number-ii/
# Logic-1
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return (3*sum(set(nums))-(sum(nums)))//2
# Logic-2
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        # hashmap={}
        # for v in nums:
        #     if v in hashmap:
        #         hashmap[v]+=1
        #     else:
        #         hashmap[v]=1
        hashmap=Counter(nums)
        for k in hashmap.keys():
            if hashmap[k]==1:
                return k
# Logic-3
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int one=0,two=0;
        for(auto num:nums)
        {
            two|=one&num;
            one^=num;
            int non_three=~(one & two);
            one&=non_three;
            two&=non_three;
        }
        return one;
    }
};