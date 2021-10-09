import sys
from collections import defaultdict 

def createGraph(vertices):
    adjacency_list=defaultdict(list)
    return adjacency_list
            
def addEdge(adjacency_list,origin,destination,n):
    if(origin>=n or destination>=n or origin<0 or destination<0):
        print("invalid graph")
        return
    adjacency_list[origin].append(destination)
    return adjacency_list

def BFS(adjacency_list,v,visited):
    queue=[]
    
    queue.append(v)
    visited[v]=True
    
    while queue:
        s=queue.pop()
        print(s)
        for i in adjacency_list[s]:
            if visited[i] == False: 
                    queue.append(i) 
                    visited[i] = True
        
if __name__=='__main__':
    adjacency_list=createGraph(6)
    adjacency_list=addEdge(adjacency_list,0,1,6)
    adjacency_list=addEdge(adjacency_list,0,2,6)
    adjacency_list=addEdge(adjacency_list,1,3,6)
    adjacency_list=addEdge(adjacency_list,1,4,6)
    adjacency_list=addEdge(adjacency_list,4,5,6)
    adjacency_list=addEdge(adjacency_list,2,5,6)
    visited=[False]*6
    print("DFS of the given graph")
    BFS(adjacency_list,0,visited)

