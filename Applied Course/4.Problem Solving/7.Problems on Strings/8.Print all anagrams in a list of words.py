# https://leetcode.com/problems/group-anagrams/
# Logic-1
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams=collections.defaultdict(list)
        for word in strs:
            anagrams[tuple(sorted(word))].append(word)
        return [v for k,v in anagrams.items()]

# Logic-2
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram=collections.defaultdict(list)
        for word in strs:
            count=[0]*26
            for c in word:
                count[ord(c)-ord('a')]+=1
            anagram[tuple(count)].append(word)
        return anagram.values()

# Logic-3
from collections import defaultdict 

def printAnagramsTogether(words):
    groupedWords = defaultdict(list) 
    
    for word in words:
        
        groupedWords["".join(sorted(word))].append(word) 
    
    for group in groupedWords.values(): 
        print(" ".join(group))


if __name__ == "__main__": 
    arr = ["cat", "dog", "tac", "god", "act"] 
    printAnagramsTogether(arr)

# Logic-4
arr = ['cat', 'tac', 'man', 'dog', 'nam', 'bbt']
H = {}
for word in arr:
    d = [0]*26
    for letter in word:
        ascii_val = ord(letter)
        d[ascii_val - ord('a')]+=1
    word_key = tuple(d)
    if word_key in H:
        H[word_key].append(word)
    else:
        H[word_key] = [word]

print("All anagrams are: ")
for k, v in H.items():
    if len(v) > 1:
        for word in v:
            print(word, end=' ')