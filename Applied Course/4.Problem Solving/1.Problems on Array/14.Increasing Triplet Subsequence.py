# https://leetcode.com/problems/increasing-triplet-subsequence
def findTriplet(arr,n):
    if(n<3):
        return False
    mid,low=-1,-1
    min_index=0
    for i in range(n):
        if(arr[i]<=arr[min_index]):
            min_index=i
        elif(mid==-1):
            low=min_index
            mid=i
        elif(arr[i] <= arr[mid]):
            low=min_index
            mid=i
        else:
            return arr[low],arr[mid],arr[i]

if __name__=='__main__':
    arr=[5, 4, 3, 7, 6, 1, 9]
    print(findTriplet(arr,len(arr)))