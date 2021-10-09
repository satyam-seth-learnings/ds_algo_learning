# https://leetcode.com/problems/critical-connections-in-a-network/
class Solution:
    def dfs(self,node,prev_node,bridges,graph,id,visited,ids,low_links):
        visited[node]=True
        low_links[node]=id
        ids[node]=id
        id+=1
        for next_node in graph[node]:
            if next_node==prev_node:
                continue
            if not visited[next_node]:
                self.dfs(next_node,node,bridges,graph,id,visited,ids,low_links)
                low_links[node]=min(low_links[node],low_links[next_node])
                if ids[node]<low_links[next_node]:
                    bridges.append([node,next_node])
            else:
                low_links[node]=min(low_links[node],ids[next_node])
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        def make_graph(connections):
            graph=collections.defaultdict(list)
            for edge in connections:
                a,b=edge
                graph[a].append(b)
                graph[b].append(a)
            return graph
        graph=make_graph(connections)
        id,node,prev_node=0,0,-1
        ids=[0 for _ in range(n)]
        low_links=[0 for _ in range(n)]
        visited=[False for _ in range(n)]
        bridges=[]
        self.dfs(node,prev_node,bridges,graph,id,visited,ids,low_links)
        return bridges