# https://leetcode.com/problems/top-k-frequent-elements
# Logic-1
from collections import Counter
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hashMap=Counter(nums)
        temp=[i for i,v in sorted(hashMap.items(),key=lambda x:x[1],reverse=True)]
        return [temp[i] for i in range(k)]
# Logic-2
import heapq
from collections import Counter
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hashMap=Counter(nums)
        return heapq.nlargest(k,hashMap.keys(),key=hashMap.get)