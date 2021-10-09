import sys
mat=[[0,1,0,0,0],
     [0,0,0,0,0],
     [0,1,0,0,0],
     [0,1,0,0,0],
     [0,1,0,0,0]]
def haveAquantiance(a,b):
    return mat[a][b]

def findCelebrity(n):
    celeb=0
    for i in range(n):
        if(haveAquantiance(celeb,i)==1):
            celeb=i
    for i in range(n):
        if(i!=celeb and haveAquantiance(celeb,i) and haveAquantiance(i,celeb)!=1):
            return -1
    return celeb

if __name__=='__main__':
    val=findCelebrity(5)
    if(val>0):
        print("Celebrity found {}".format(val))
    else:
        print("Celebrity not found")
