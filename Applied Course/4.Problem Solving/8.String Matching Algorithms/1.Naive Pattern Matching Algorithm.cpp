#include<bits/stdc++.h>
using namespace std;
int match(string s1,string s2)
{
	int n=s1.length();
	int m=s2.length();
	int i,j;
	for(i=0;i<n-m;i++)
	{
		for(j=0;j<m;j++)
		{
			if(s1[i+j]!=s2[j])
				break;
		}
		if(j==m)
			return i;
	}
	return -1;
}
int main()
{
	string str1="ABCDEFGH";
	string str2="FG";
	cout<<match(str1,str2);
	return 0;
}