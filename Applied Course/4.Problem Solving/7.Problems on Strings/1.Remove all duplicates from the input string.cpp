// Logic-1
string removeDuplicateLetters(string s)
{
    string result;
    map<char,int> m;
    for(auto ele:s)
    {
        if(!m[ele])
        {
            result.push_back(ele);
            m[ele]++;
        }
    }
    sort(result.begin(),result.end());
    return result;
}
// Logic-2
char *removeDups(char str[]) 
{ 
	bool bin_hash[NO_OF_CHARS] = {0}; 
	int ip_ind = 0, res_ind = 0; 
	char temp; 
 
	/* In place removal of duplicate characters*/
	while (*(str + ip_ind)) 
	{ 
		temp = *(str + ip_ind); 
		if (bin_hash[temp] == 0) 
		{ 
			bin_hash[temp] = 1; 
			*(str + res_ind) = *(str + ip_ind); 
			res_ind++; 
		} 
		ip_ind++; 
	} 
 
	/* After above step string is stringiittg. 
		Removing extra iittg after string*/
	*(str+res_ind) = '\0'; 
 
	return str; 
}
// Logic-3
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26,0);
        for(char ch:s)
            freq[ch-'a']++;
        vector<char> result;
        vector<bool> visited(26,false);
        for(char ch:s)
        {
            if(!visited[ch-'a'])
            {
                visited[ch-'a']=true;
                if((result.size()>0)&&(ch<result[result.size()-1]))
                {
                    char lastChar=result[result.size()-1];
                    while((result.size()>0)&&(ch<lastChar)&&(freq[lastChar-'a']>0))
                    {
                        visited[lastChar-'a']=false;
                        result.pop_back();
                        if(result.size()>0)
                            lastChar=result[result.size()-1];
                    }
                }
                result.push_back(ch);
            }
            freq[ch-'a']--;
        }
        return string(result.begin(),result.end());
    }
};
int main()
{
    // https://www.youtube.com/watch?v=d7cw9wL8l9I
    // https://leetcode.com/problems/remove-duplicate-letters
    return 0;
}