# https://leetcode.com/problems/largest-rectangle-in-histogram/
# Logic-1 O(n2)
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        def findLeftIndex(heights,index):
            j=index-1
            while j>=0 and heights[j]>=heights[index]:
                j-=1
            return j
        def findRightIndex(heights,index):
            j=index+1
            while j<len(heights) and heights[j]>=heights[index]:
                j+=1
            return j
        if len(heights)==0:
            return 0
        maxArea=-1
        for i in range(len(heights)):
            leftIndex=findLeftIndex(heights,i)
            rightIndex=findRightIndex(heights,i)
            currentArea=(rightIndex-leftIndex-1)*heights[i]
            if maxArea<currentArea:
                maxArea=currentArea
        return maxArea
# Logic-2 O(n)
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack=[]
        max_area=0
        index=0
        while index<len(heights):
            if (not stack) or (heights[index]>=heights[stack[-1]]):
                stack.append(index)
                index+=1
            else:
                top_of_stack=stack.pop()
                current_area=heights[top_of_stack]*((index-stack[-1]-1) if stack else index)
                max_area=max(current_area,max_area)
        while stack:
            top_of_stack=stack.pop()
            current_area=heights[top_of_stack]*((index-stack[-1]-1) if stack else index)
            max_area=max(current_area,max_area)
        return max_area