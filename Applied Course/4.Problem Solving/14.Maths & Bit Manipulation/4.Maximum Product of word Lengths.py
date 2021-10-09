# https://leetcode.com/problems/maximum-product-of-word-lengths
# Logic-1
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        def no_common_letters(word1,word2):
            for c in word1:
                if c in word2:
                    return False
            return True
        n=len(words)
        max_val=0
        for i in range(n):
            for j in range(i+1,n):
                if no_common_letters(words[i],words[j]):
                    max_val=max(max_val,len(words[i])*len(words[j]))
        return max_val
# Logic-2
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        n = len(words)
        masks = [0] * n
        lens = [0] * n
        bit_number = lambda ch : ord(ch) - ord('a')
        
        for i in range(n):
            bitmask = 0
            for ch in words[i]:
                # add bit number bit_number in bitmask
                bitmask |= 1 << bit_number(ch)
            masks[i] = bitmask
            lens[i] = len(words[i])
            
        max_val = 0
        for i in range(n):
            for j in range(i + 1, n):
                if masks[i] & masks[j] == 0:
                    max_val = max(max_val, lens[i] * lens[j])
        return max_val