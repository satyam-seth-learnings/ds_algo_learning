class Parenthesis:
    def __init__(self):
        self.stack=[]
    
    def check(self,exp):
        for i in range(len(exp)):
            if exp[i] == '[' or exp[i] == '{' or exp[i] == '(':
                self.stack.append(exp[i])
                continue
            
            if len(self.stack)==0:
                return False
            
            if exp[i] == ')':
                if '(' != self.stack.pop():
                    return False
            
            if exp[i] == '}':
                if '{' != self.stack.pop():
                    return False
            
            if exp[i] == ']':
                if '[' != self.stack.pop():
                    return False
        if self.stack:
            return False
        return True

p=Parenthesis()
exp=input('Enter expression: ')
if p.check(exp):
    print('Given expression is balanced')
else:
    print('Given expression is not balanced')