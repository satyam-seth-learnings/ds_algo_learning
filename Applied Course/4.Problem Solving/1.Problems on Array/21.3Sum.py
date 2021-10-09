# https://leetcode.com/problems/3sum/
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        n=len(nums)
        result=[]
        for i in range(n-1):
            l=i+1
            r=n-1
            while l<r:
                curr_sum=nums[i]+nums[l]+nums[r]
                if curr_sum==0:
                    result.append([nums[i],nums[l],nums[r]])
                    l+=1
                    r-=1
                elif curr_sum<0:
                    l+=1
                else:
                    r-=1
        return set([tuple(x) for x in result])