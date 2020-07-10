import numpy as np
t = int(input())
while t>0:
    x = np.array([int(i) for i in input().split()])
    y = np.array([int(i) for i in input().split()])
    
    t-=1

    # Ans = 1
    #print(np.all((y-x) == (y-x)[0]))
    if np.all((y-x) == (y-x)[0]):
        print('1')
        continue
    f=0
    for i in range(3):
        if x[i] != 0:
            if y[i]%x[i]==0 and np.all(x*(y[i]//x[i])==y):
                f = 1
            break
    if(f):
        print('1')
        continue

    # Ans = 2

    # n(S) 3 -> ax + b = y
    # ax1 + b = y1
    # ax2 + b = y2
    # y2-y1/x2-x1

    f=0
    for i in range(3):
        if x[(i+1)%3]-x[i] != 0 and (y[(i+1)%3]-y[i])%(x[(i+1)%3]-x[i]) == 0:
            a = (y[(i+1)%3]-y[i])//(x[(i+1)%3]-x[i])
            b = y[0] - a*x[0]
            if np.all(a*x+b == y):
                f=1
                break

    if(f):
        print('2')
        continue

    # n(S) 2 same subset
    