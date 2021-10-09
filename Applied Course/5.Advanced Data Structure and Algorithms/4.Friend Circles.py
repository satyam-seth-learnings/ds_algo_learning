# https://leetcode.com/problems/number-of-provinces
# Logic-1
class Solution:
    def dfs(self,M,i,n,visited):
        visited[i]=True
        for j in range(n):
            if M[i][j]==1 and visited[j]==False:
                self.dfs(M,j,n,visited)
    
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n=len(isConnected)
        visited=[False for i in range(n)]
        result=0
        for i in range(n):
            if visited[i]==False:
                self.dfs(isConnected,i,n,visited)
                result+=1
        return result
# Logic-2
class Solution:
    def find(self,parent,i):
        if parent[i]==-1:
            return i
        return self.find(parent,parent[i])
    
    def union(self,parent,x,y):
        xset=self.find(parent,x)
        yset=self.find(parent,y)
        if xset!=yset:
            parent[yset]=xset
    
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n=len(isConnected)
        parent=[-1 for i in range(n)]
        for i in range(n):
            for j in range(n):
                if isConnected[i][j]==1 and i!=j:
                    self.union(parent,i,j)
        result=0
        for i in range(n):
            if parent[i]==-1:
                result+=1
        return result