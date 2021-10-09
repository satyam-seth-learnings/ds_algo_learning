def wordbreak(s, words):
    if len(s) == 0: 
        return True
    # Test all prefixes
    for i in range(1, len(s)+1):
        sub = s[:i]
        if not sub in words: continue
        if wordbreak(s[i:], words):
            return True
    return False


### DP? O(n^2)
# cut(i) = s[:i] can be splitted
# cut(i+1) = OR{cut(j) and s[j:i] is a word for 0 <= j < i}
def wordbreak_DP(s, words):
    words = set(words)
    cut = {0: True}
    for i in range(1,len(s)+1):
        cut[i] = False
        for j in range(i):
            if cut[j] and s[j:i] in words:
                cut[i] = True
                break
    return cut[len(s)]


memo = {}
def wordbreak_memo(s, words):
    if s == '': return True
    global memo
    if s in memo: return memo[s]
    for i in range(1,len(s)+1):
        sub = s[:i]
        if not sub in words: continue
        if wordbreak_memo(s[i:], words):
            memo[s] = True#; print memo
            return True
    return False

if __name__ == '__main__':
    s = "catsanddogseat"
    words = set(["cat", "cats", "and", "sand", "dog", "dogs", "eat", "seat"])
    print(wordbreak(s, words))
    print (wordbreak_DP(s, words))
    print (wordbreak_memo(s, words))
