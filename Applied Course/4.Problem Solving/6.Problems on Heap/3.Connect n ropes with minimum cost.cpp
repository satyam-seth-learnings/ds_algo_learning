// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long,vector<long long>,greater<long long>> min_heap(arr,arr+n);
        long long cost=0;
        while(min_heap.size()>1)
        {
            long long first=min_heap.top();
            min_heap.pop();
            long long second=min_heap.top();
            min_heap.pop();
            cost+=(first+second);
            min_heap.push(first+second);
        }
        return cost;
    }
};