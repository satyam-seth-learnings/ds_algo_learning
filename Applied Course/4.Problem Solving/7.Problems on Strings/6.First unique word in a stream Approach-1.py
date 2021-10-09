def nonRepeatingStream(stream):
    DLL=[]
    
    checked=[False]*256
    
    for i in range(len(stream)):
        x=stream[i]
        print("Reading " + x + " from stream")
        if not checked[ord(x)]:
            
            if x not in DLL or len(DLL)==0:
                DLL.append(x)
            else:
                DLL.remove(x)
                checked[ord(x)] = True
                
        if len(DLL)!=0:
            print("First non-repeating character so far is ")
            print(str(DLL[0]))
            
if __name__=='__main__':
    stream="appliedaicourseai"
    nonRepeatingStream(stream)
                

