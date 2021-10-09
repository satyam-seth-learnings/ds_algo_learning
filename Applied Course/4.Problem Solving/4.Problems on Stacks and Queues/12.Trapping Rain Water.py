# https://leetcode.com/problems/trapping-rain-water
# Logic-1 O(n2)
class Solution:
    def trap(self, height: List[int]) -> int:
        n=len(height)
        result=0
        for i in range(1,n-1):
            left=height[i]
            for j in range(i):
                left=max(left,height[j])
            right=height[i]
            for j in range(i+1,n):
                right=max(right,height[j])
            result=result+min(left,right)-height[i]
        return result
# Logic-2 O(n)
class Solution:
    def trap(self, height: List[int]) -> int:
        n=len(height)
        if(n==0):
            return 0
        left=[0]*n
        right=[0]*n
        result=0
        left[0]=height[0]
        for i in range(1,n):
            left[i]=max(left[i-1],height[i])
        right[n-1]=height[n-1]
        for i in range(n-2,-1,-1):
            right[i]=max(right[i+1],height[i])
        for i in range(n):
            result+=min(left[i],right[i])-height[i]
        return result
# Logic-3 O(n)
class Solution:
    def trap(self, height: List[int]) -> int:
        n=len(height)
        stack=[]
        result=0
        for current  in range(n):
            while stack and height[current]>height[stack[-1]]:
                top=stack[-1]
                stack.pop()
                if not stack:
                    break
                distance=current-stack[-1]-1
                bounded_height=min(height[current],height[stack[-1]])-height[top]
                result+=(distance*bounded_height)
            stack.append(current)
        return result
# Logic-4 O(n)
class Solution:
    def trap(self, height: List[int]) -> int:
        n=len(height)
        left_max=0
        right_max=0
        left=0
        right=n-1
        result=0
        while left<right:
            if height[left]<height[right]:
                if height[left]>=left_max:
                    left_max=height[left]
                else:
                    result+=(left_max-height[left])
                left+=1
            else:
                if height[right]>=right_max:
                    right_max=height[right]
                else:
                    result+=(right_max-height[right])
                right-=1
        return result