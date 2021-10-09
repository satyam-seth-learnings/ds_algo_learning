# https://leetcode.com/problems/longest-common-prefix/
# Logic-1
class Solution:
    def commonPrefixUtil(self,str1,str2):
        n1=len(str1)
        n2=len(str2)
        i=j=0
        while i<n1 and j<n2:
            if str1[i]!=str2[j]:
                break
            i+=1
            j+=1
        return str1[:i]
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs)<1:
            return ""
        prefix=strs[0]
        for i in range(1,len(strs)):
            prefix=self.commonPrefixUtil(prefix,strs[i])
        return prefix
# Logic-2
class Solution:
    def findMinLenString(self,strs):
        minLen=len(strs[0])
        for i in range(1,len(strs)):
            if minLen>len(strs[i]):
                minLen=len(strs[i])
        return minLen
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs)<1:
            return ""
        minLen=self.findMinLenString(strs)
        result=""
        for i in range(minLen):
            current=strs[0][i]
            for j in range(1,len(strs)):
                if strs[j][i]!=current:
                    return result
            result+=current
        return result
# Logic-3
class Solution:
    def allCommanPrefix(self,strs,low,high):
        str1=strs[0]
        for word in strs:
            for i in range(low,high+1):
                if word[i]!=str1[i]:
                    return False
        return True
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs)==0:
            return ""
        minLen=len(min(strs,key=len))
        result=""
        low,high=0,minLen-1
        while low<=high:
            mid=(low+high)//2
            if self.allCommanPrefix(strs,low,mid):
                result+=strs[0][low:mid+1]
                low=mid+1
            else:
                high=mid-1
        return result
# Logic-4
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs)==0:
            return ""
        size=len(strs)
        strs.sort()
        end=min(len(strs[0]),len(strs[size-1]))
        i=0
        while i<end and strs[0][i]==strs[size-1][i]:
            i+=1
        return strs[0][:i]