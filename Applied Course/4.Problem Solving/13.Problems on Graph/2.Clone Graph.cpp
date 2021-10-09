#include<bits/stdc++.h>
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> visited;
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
        if(visited[node])
            return visited[node];
        Node* new_node=new Node(node->val);
        visited[node]=new_node;
        if(node->neighbors!=vector<Node*>())
        {
            vector<Node*> neigh;
            for(auto n:node->neighbors)
                neigh.push_back(cloneGraph(n));
            new_node->neighbors=neigh;
        }
        return new_node;
    }
};
int main()
{
    // https://leetcode.com/problems/clone-graph/
    return 0;
}