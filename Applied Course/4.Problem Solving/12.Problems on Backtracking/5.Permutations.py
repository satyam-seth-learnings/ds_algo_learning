# https://leetcode.com/problems/permutations
class Solution:
    def __init__(self):
        self.result=[]
    def permutations(self,nums,l,r):
        if l==r-1:
            self.result.append(nums[:])
        else:
            for i in range(l,r):
                nums[l],nums[i]=nums[i],nums[l]
                self.permutations(nums,l+1,r)
                nums[l],nums[i]=nums[i],nums[l]
    
    def permute(self, nums: List[int]) -> List[List[int]]:
        n=len(nums)
        self.permutations(nums,0,n)
        return self.result