class PriorityQueue:
    def heapify(self, arr, n, i):
        largest = i
        left = 2*i + 1
        right = 2*i + 2

        if left < n and arr[i] < arr[left]:
            largest = left
        if right < n and arr[largest] < arr[right]:
            largest = right
		#if root is not largest, swap with largest and
		#continue heapify
        if largest != i:
            arr[i], arr[largest] = arr[largest], arr[i]
            self.heapify(arr, n, largest)

    def buildMaxHeap(self, arr, n):
        for i in range(n//2 - 1, -1, -1):
            self.heapify(arr, n, i)

    def findMaxElement(self, arr):
        return arr[0]

    def extractMaxElement(self, arr, n):
        ele = arr[0]
        arr[0] = arr[n-1]
        arr.pop()
        self.heapify(arr, n-1, 0)
        return ele

    def insertNewElement(self, arr, n, ele):
        arr.append(ele)
        #Index of the last element = curr_length - 1 = (n+1) - 1 = n
        curr=n
        if curr%2==0:
            parent=(curr-2)//2
        else:
            parent=(curr-1)//2
        while parent>=0:
            if arr[parent] < arr[curr]:
                arr[parent], arr[curr] = arr[curr], arr[parent]
            curr=parent
            if curr%2==0:
                parent=(curr-2)//2
            else:
                parent=(curr-1)//2

    def increaseKey(self, arr, initial_key, updated_key):
        curr=arr.index(initial_key)
        if curr is not None and updated_key - initial_key > 0:
            arr[curr] = updated_key
            # If current is not equal to root, then only we need to proceed further
            if curr!=0:
                if curr%2==0:
                    parent=(curr-2)//2
                else:
                    parent=(curr-1)//2
                while parent>=0:
                    if arr[parent] < arr[curr]:
                        arr[parent], arr[curr] = arr[curr], arr[parent]
                    curr=parent
                    if curr%2==0:
                        parent=(curr-2)//2
                    else:
                        parent=(curr-1)//2
        else:
            raise Exception("Invalid Input")

arr = [4, 1, 3, 2, 16, 9, 10, 14, 8, 7]
h = PriorityQueue()
h.buildMaxHeap(arr, len(arr))
print(h.extractMaxElement(arr, len(arr)))
h.insertNewElement(arr, len(arr), 20)
h.insertNewElement(arr, len(arr), 12)
h.increaseKey(arr, 9, 21)
h.increaseKey(arr, 14, 17)
h.increaseKey(arr, 21, 50)
print(arr)