def calculateSpan(price,n,stock):
    stock[0]=1
    for i in range(1,n):
        c=1
        while ((i-c)>=0) and (price[i] > price[i - c]):
            c += stock[i - c]
        stock[i]=c
    return stock
            


if __name__=='__main__':
    price=[10, 4, 5, 90, 120, 80]
    n=len(price)
    stock=[0]*n
    stock=calculateSpan(price,n,stock)
    for i in stock:
        print("{} ".format(i)),
