def tour(petrol,distance,n):
    start=0
    end=1
    curr_petrol=petrol[start]-distance[start]
    while end!=start or curr_petrol<0:
        while curr_petrol<0 and start!=end:
            curr_petrol=curr_petrol-(petrol[start]-distance[start])
            start=(start+1)%n
            if start==0:
                return -1
        curr_petrol=curr_petrol+petrol[end]-distance[end]
        end=(end+1)%n
    return start
            

if __name__=='__main__':
    petrol=[4,6,7,4]
    distance=[6,5,3,5]
    value=tour(petrol,distance,4)
    print(value)
