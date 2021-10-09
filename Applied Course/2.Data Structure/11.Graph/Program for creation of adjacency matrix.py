def createMatrix():
    adj=[[0 for i in range(100)] for i in range(100)]
    max_edges=0
    print("enter number of vertices")
    n=int(input())
    print("enter graph type 1 for undirected and 2 for directed")
    graph_type=int(input())
    
    if graph_type==1:
        max_edges=(n*(n-1))/2
    else:
        max_edges=(n*(n-1))
    for i in range(max_edges):
        print("enter orgin=-1 and destination=-1 to break the loop")
        origin=int(input())
        destination=int(input())
        if(origin ==-1 and destination ==-1):
            break
        if(origin>=n or destination>=n or origin<0 or destination<0):
            print("invalid graph")
            break
        
        else:
            adj[origin][destination]=1
            if graph_type==1:
                adj[destination][origin]=1
    print("Adjacency list")            
    for i in range(n):
        for j in range(n):
            print(adj[i][j]),
        print("\n")

if __name__=='__main__':
    createMatrix()