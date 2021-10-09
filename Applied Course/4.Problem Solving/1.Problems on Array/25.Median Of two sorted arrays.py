# https://leetcode.com/problems/median-of-two-sorted-arrays/
# Logic-1
class Solution:
    def findMedianSortedArrays(self, A: List[int], B: List[int]) -> float:
        m, n = len(A), len(B)
        if m > n:
            A, B, m, n = B, A, n, m
        if n == 0:
            raise ValueError
        imin, imax, half_len = 0, m, (m + n + 1) // 2
        while imin <= imax:
            i = (imin + imax) // 2
            j = half_len - i
            if i < m and B[j-1] > A[i]:
                # i is too small, must increase it
                imin = i + 1
            elif i > 0 and A[i-1] > B[j]:
                # i is too big, must decrease it
                imax = i - 1
            else:
                # i is perfect

                if i == 0: max_of_left = B[j-1]
                elif j == 0: max_of_left = A[i-1]
                else: max_of_left = max(A[i-1], B[j-1])

                if (m + n) % 2 == 1:
                    return max_of_left

                if i == m: min_of_right = B[j]
                elif j == n: min_of_right = A[i]
                else: min_of_right = min(A[i], B[j])

                return (max_of_left + min_of_right) / 2.0
# Logic-2
def getMedian(arr1,arr2,n):
    i=0
    j=0
    
    count=0
    m1=-1
    m2=-1
    
    while(count<n+1):
        
        count+=1
        if i == n: 
            m1 = m2 
            m2 = arr2[0] 
            break
        elif j == n: 
            m1 = m2 
            m2 = arr1[0] 
            break
        if arr1[i] < arr2[j]: 
            m1 = m2 
            m2 = arr1[i] 
            i += 1
        else: 
            m1 = m2
            m2 = arr2[j] 
            j += 1
    return (m1 + m2)/2


if __name__=='__main__':
    a1=[1, 12, 15, 26, 38]
    a2=[2, 13, 17, 30, 45]
    if len(a1)!=len(a2):
        print("Median is not possible")
    else:
        print(getMedian(a1,a2,len(a1)))
