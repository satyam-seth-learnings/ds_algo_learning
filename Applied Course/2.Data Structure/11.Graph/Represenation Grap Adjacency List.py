import sys

def createGraph(vertices):
    adjacency_list=[[] for i in range(vertices)]
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
            adjacency_list[origin].append(destination)
    return adjacency_list
            
def addEdge(adjacency_list,origin,destination,n):
    if(origin>=n or destination>=n or origin<0 or destination<0):
        print("invalid graph")
        return
    adjacency_list[origin].append(destination)
    return adjacency_list

def delEdge(adjacency_list,origin,destination,n):
    if(origin>=n or destination>=n or origin<0 or destination<0):
        print("invalid graph")
        return
    adjacency_list[origin].remove(destination)
    return adjacency_list
    
def display(adjacency_list):
    print(adjacency_list)

if __name__=='__main__':
    print("enter number of vertices")
    n=int(input())
    adjacency_list=createGraph(n)
    origin,destination=0,0
    while(1):
        print("1.Insert an edge\n")
        print("2.Delete an edge\n")
        print("3.Display\n")
        print("4.Exit\n")
        print("Enter your choice : ")
        choice=int(input())
        
        if choice==1:
            print("Enter orgin and destination to insert Edge")
            origin=int(input())
            destination=int(input())
            adjacency_list=addEdge(adjacency_list,origin,destination,n)
            
        elif choice==2:
            print("Enter orgin and destination to delete Edge")
            origin=int(input())
            destination=int(input())
            adjacency_list=delEdge(adjacency_list,origin,destination,n)
        elif choice==3:
            print("Display")
            display(adjacency_list)
        elif choice==4:
            sys.exit(0)
