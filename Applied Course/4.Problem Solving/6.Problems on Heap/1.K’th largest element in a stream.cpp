#include<bits/stdc++.h>
using namespace std;
class KthLargest {
public:
    int n;
    priority_queue<int,vector<int>,greater<int>> min_heap;
    KthLargest(int k, vector<int>& nums) {
        for(auto ele:nums)
        {
            min_heap.push(ele);
            if(min_heap.size()>k)
                min_heap.pop();
        }
        n=k;
    }
    int add(int val) {
        min_heap.push(val);
        if(min_heap.size()>n)
            min_heap.pop();
        return min_heap.top();    
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
int main()
{
    // https://leetcode.com/problems/kth-largest-element-in-a-stream
    return 0;
}