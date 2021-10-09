#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long ans=0;
        for(int i=0;i<columnTitle.size();i++)
        {
            if(i!=columnTitle.size()-1)
                ans=(ans+columnTitle[i]-'A'+1)*26;
            else
                ans=ans+columnTitle[i]-'A'+1;
        }
        return ans;
    }
};
int main()
{
    // https://leetcode.com/problems/excel-sheet-column-number/
    return 0;
}