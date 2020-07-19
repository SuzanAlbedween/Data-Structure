#You are given a list of n-1 integers and these integers are in the range of 1 to n.
# There are no duplicates in the list.
# One of the integers is missing in the list. Write an efficient code to find the missing integer.?
#Time Complexity : O(n)
def getmissingnumber(arr):
    n=len(arr)
    sum_arr=sum(arr)
    total=(n + 1)*(n + 2)/2
    return int(total)-sum_arr



if __name__ == '__main__':
    a = [1, 2, 4, 5, 6]
    miss = getmissingnumber(a)
    print(miss)

