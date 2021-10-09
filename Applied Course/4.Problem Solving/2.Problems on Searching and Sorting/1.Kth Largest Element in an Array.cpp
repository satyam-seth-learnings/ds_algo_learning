#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};
// Logic-2
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int> > heap;
        for(auto num:nums)
        {
            heap.push(num);
            if(heap.size()>k)
                heap.pop();
        }
        return heap.top();   
    }
};
// Logic-3
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // could be solved using quick-select algorithms
        // worst case O(n^2) but expected O(n)
        
        int start = 0, end = nums.size() -1;
        while(start <= end){
            int pos = partition(nums, start, end);
            if(pos == k-1)
                return nums[pos];
            
            else if(pos > k-1)
                end = pos-1;
            else{
                start = pos+1;
            }
        }
        return -1;
    }
    
    int partition(vector<int>& nums, int start, int end){
        int pivot = nums[end];
        int count = start; //count of elements greater than the pivot
        
        for(int i=start; i < end; i++){
            if(nums[i] > pivot){
                swap(nums[i], nums[count]);
                count++;
            }
        }
        
        swap(nums[count], nums[end]);
        return count;
    }
};
int main()
{
    // https://leetcode.com/problems/kth-largest-element-in-an-array/
    return 0;
}