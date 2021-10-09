class Evaluation:
    def __init__(self):
        self.stack=[]
    def isEmpty(self):
        return self.stack==[]
    def push(self,op):
        self.stack.append(op)
    def pop(self):
        if not self.isEmpty():
            return self.stack.pop()
        return '$'
    def evaluatePostfix(self,exp):
        for c in exp:
            if c.isdigit():
                self.push(c)
            else:
                a=self.stack.pop()
                b=self.stack.pop()
                self.push(str(eval(a+c+b)))
        return int(self.pop())
e=Evaluation()
print(e.evaluatePostfix('231*+9-'))