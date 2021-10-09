#include<bits/stdc++.h>
using namespace std;
bool check(string s)
{
    int count[256]={0};
    int oddcount=0;
    for(int i=0;i<s.length();i++)
    {
        count[s[i]]++;
        if(count[s[i]]%2==1)
            oddcount++;
        else
            oddcount--;
    }
    if(oddcount>1)
        return false;
    return true;
}
int main()
{
    string s;
    cin>>s;
    cout<<check(s);
    return 0;
}