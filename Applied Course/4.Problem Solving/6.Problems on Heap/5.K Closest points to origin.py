# https://leetcode.com/problems/k-closest-points-to-origin
# Logic-1
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        points.sort(key=lambda P:P[0]**2+P[1]**2)
        return points[:k]
# Logic-2
import heapq
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        getDist=lambda p:-(p[0]**2+p[1]**2)
        heap=[]
        for point in points:
            if len(heap)<k:
                heapq.heappush(heap,(getDist(point),point))
            else:
                heapq.heappushpop(heap,(getDist(point),point))
        return [i[1] for i in heap]