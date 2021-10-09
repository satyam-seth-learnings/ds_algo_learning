#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combos;
        vector<string> chars;
        if(digits.size()==0)
            return combos;
        combos=getChars(digits[0]);
        for(int i=1;i<digits.size();i++)
        {
            vector<string> temp=combos;
            chars=getChars(digits[i]);
            combos.clear();
            for(int j=0;j<temp.size();j++)
                for(int k=0;k<chars.size();k++)
                    combos.push_back(temp[j]+chars[k]);
        }
        return combos;
    }
    vector<string> getChars(char num)
    {
        switch(num)
        {
            case '2': return {"a","b","c"};
            case '3': return {"d","e","f"};
            case '4': return {"g","h","i"};
            case '5': return {"j","k","l"};
            case '6': return {"m","n","o"};
            case '7': return {"p","q","r","s"};
            case '8': return {"t","u","v"};
            default:  return {"w","x","y","z"};
        }
    }
};
int main()
{
    // https://leetcode.com/problems/letter-combinations-of-a-phone-number/
    return 0;
}