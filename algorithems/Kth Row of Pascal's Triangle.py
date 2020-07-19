#Given an index k, return the kth row of the Pascal’s triangle.

#Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

#Example:

#Input : k = 3

#Return : [1,3,3,1]

def GetRow(k):
    res=[0]*(k+1)
    print(res)
    print(len(res))
    x=1
    for i in range(k+1):
        res[i]=x
        x=int(x*(k-i)/(i+1))
    return res
print(GetRow(3))