def find_missing(arr):
    x1,x2=1,arr[0]
    for i in range(2,len(arr)):
        x1^=arr[i]
    for ele in arr:
        x2^=ele
    return x1^x2
arr=[1,2,3,5]
print(find_missing(arr))    