# https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        if not points:
            return 0
        points.sort()
        arrows=1
        currentEnd=points[0][1]
        for x in points[1:]:
            if x[0]<=currentEnd:
                currentEnd=min(currentEnd,x[1])
            else:
                arrows+=1
                currentEnd=x[1]
        return arrows