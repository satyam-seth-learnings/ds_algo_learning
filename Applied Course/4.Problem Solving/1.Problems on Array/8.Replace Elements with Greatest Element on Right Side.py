# https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
# Logic-1
class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        l=[]
        for i in range(len(arr)-1):
            l.append(max(arr[i+1:]))
        l.append(-1)
        return l
# Logic-2
class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        n=len(arr)
        max_ele_seen_so_far=arr[n-1]
        arr[n-1]=-1
        for i in range(n-2,-1,-1):
            temp=arr[i]
            arr[i]=max_ele_seen_so_far
            if temp>max_ele_seen_so_far:
                max_ele_seen_so_far=temp
        return arr