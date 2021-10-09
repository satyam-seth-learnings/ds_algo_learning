// https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing2704/1#
// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        // code here 
        int countL=0,countR=0,swaps=0,imbalance=0;
        for(int i=0;i<S.length();i++)
        {   
            if(S[i]=='[')
            {
                countL++;
                if(imbalance>0)
                {
                    swaps+=imbalance;
                    imbalance--;
                }
            }
            else if(S[i]==']')
            {
                countR++;
                imbalance=countR-countL;
            }
        }
        return swaps;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends