# https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
# Logic-1
class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        counts=[(sum(row),i) for i,row in enumerate(mat)]
        counts.sort()
        return [counts[i][1] for i in range(k)]
# Logic-2
class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        def binary_search(row):
            low=0
            high=len(row)
            while low<high:
                mid=low+(high-low)//2
                if row[mid]==1:
                    low=mid+1
                else:
                    high=mid
            return low
        counts=[(binary_search(row),i) for i,row in enumerate(mat)]
        counts.sort()
        return [counts[i][1] for i in range(k)]
# Logic-3
class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        m = len(mat)
        n = len(mat[0])

        def binary_search(row):
            low = 0
            high = n
            while low < high:
                mid = low + (high - low) // 2
                if row[mid] == 1:
                    low = mid + 1
                else:
                    high = mid
            return low

        # Calculate the strength of each row using binary search.
        # Put the strength/index pairs into a priority queue.
        pq = []
        for i, row in enumerate(mat):
            strength = binary_search(row)
            entry = (-strength, -i)
            if len(pq) < k or entry > pq[0]:
                heapq.heappush(pq, entry)
            if len(pq) > k:
                heapq.heappop(pq)

        # Pull out and return the indexes of the smallest k entries.
        # Don't forget to convert them back to positive numbers!
        indexes = []
        while pq:
            strength, i = heapq.heappop(pq)
            indexes.append(-i)

        # Reverse, as the indexes are around the wrong way.
        indexes = indexes[::-1]

        return indexes