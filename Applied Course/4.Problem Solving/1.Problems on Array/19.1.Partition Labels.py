# https://leetcode.com/problems/partition-labels/
class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        last_occurence={c:i for i,c in enumerate(S)}
        j=start=0
        result=[]
        for i,c in enumerate(S):
            j=max(j,last_occurence[c])
            if i==j:
                result.append(i-start+1)
                start=i+1
        return result