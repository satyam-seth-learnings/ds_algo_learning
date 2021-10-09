def getTour(petrol,distance,n):
    s,start,diff=0,0,0
    for i in range(n):
        s=s+petrol[i]-distance[i]
        if(s<0):
            start=i+1
            diff+=s
            s=0
    if s+diff>0:
        return start
    else:
        return -1
    
if __name__=='__main__':
    petrol=[4,6,7,4]
    distance=[6,5,3,5]
    value=getTour(petrol,distance,4)
    print(value)
