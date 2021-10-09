# https://leetcode.com/problems/create-target-array-in-the-given-order/
class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        length=len(nums)
        target=[]
        for i in range(length):
            # if my index value grater than the length of the insert at the end
            if index[i]>=length:
                target.append(nums[i])
            else:
                target.insert(index[i],nums[i])
        return target