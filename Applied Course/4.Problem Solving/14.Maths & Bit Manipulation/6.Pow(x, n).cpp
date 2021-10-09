#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    double myPow(double x, int n) {
        if(n<0)
        {
            x=1/x;
            n=-n;
        }
        double result=1;
        for(int i=0;i<n;i++)
            result*=x;
        return result;
    }
};
// Logic-2
class Solution {
public:
    double fastPow(double x,int n) {
        if(n==0)
            return 1.0;
        double A=fastPow(x,n/2); 
        if(n%2==0)
            return A*A;
        else 
            return A*A*x; 
    } 
    double myPow(double x, int n) {
        long long N=n;
        if(n<0) 
        { 
            x=1/x; 
            N=-1*N;
        } 
        return fastPow(x,n);
    }
};
int main()
{
    // https://leetcode.com/problems/powx-n/
    return 0;
}