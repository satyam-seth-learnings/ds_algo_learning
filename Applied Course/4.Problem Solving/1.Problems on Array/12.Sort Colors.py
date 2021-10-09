# Logic-1
def DNF012(arr,n):
    low=0
    high=n-1
    mid=0
    
    while(mid<=high):
        if(arr[mid]==0):
            arr[mid],arr[low]=arr[low],arr[mid]
            low+=1
            mid+=1
        elif(arr[mid]==1):
            mid+=1
        else:
            arr[mid],arr[high]=arr[high],arr[mid]
            high-=1
    return arr

if __name__=='__main__':
    arr=[0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
    arr=DNF012(arr,len(arr))
    print(arr)
# Logic-2
class Solution:
    def sortColors(self, nums):
        """
        Dutch National Flag problem solution.
        """
        p0 = curr = 0
        p2 = len(nums) - 1

        while curr <= p2:
            if nums[curr] == 0:
                nums[p0], nums[curr] = nums[curr], nums[p0]
                p0 += 1
                curr += 1
            elif nums[curr] == 2:
                nums[curr], nums[p2] = nums[p2], nums[curr]
                p2 -= 1
            else:
                curr += 1