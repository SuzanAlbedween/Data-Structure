#You are given an n x n 2D matrix representing an image.

#Rotate the image by 90 degrees (clockwise).

#You need to do this in place.

#Note that if you end up using an additional array, you will only receive partial score.
#Time Complexity o(n)

def RotateMatrix90(A):
    N=len(A[0])
    print(N)
    for i in range(N//2):
        for j in range(i,N-i-1):
            temp = A[i][j]
            A[i][j] = A[N - 1 - j][i]
            A[N - 1 - j][i] = A[N - 1 - i][N - 1 - j]
            A[N - 1 - i][N - 1 - j] = A[j][N - 1 - i]
            A[j][N - 1 - i] = temp
def printMatrix(A):
    N = len(A[0])
    for i in range(N):
        print(A[i])

A=[[1,2,3],[4,5,6],[7,8,9]]
print("befor rotata ",A)
print("---------------------")
RotateMatrix90(A)
printMatrix(A)
