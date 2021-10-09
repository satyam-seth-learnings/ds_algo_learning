# Logic-1
def canFormPalindrome(s):
    count=[0]*256
    odd=0
    for i in range(len(s)):
        count[ord(s[i])]+=1
    
    for i in count:
        if i%2!=0:
            odd+=1
        if(odd>1):
            return False
    return True
if __name__=='__main__':
    s="madmac"
    val=canFormPalindrome(s)
    if val==True:
        print("Palindrome can be formed")
    else:
        print("Palindrome cannot be formed")

# Logic-2
def is_palindrome(string):
	string = string.lower()
	result = ord(string[0])
	for item in string[1:]:
		result ^= ord(item)
 
	if result == 0 or (result >= ord('a') and result <= ord('z')):
		return True
	return False

print(is_palindrome("Carrace"))