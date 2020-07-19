#Given an unsorted array A of size N of non-negative integers, find a continuous sub-array which adds to a given number S.

def fun1(arr, n, sum):
    current_sum = 0
    res = []
    first=0
    count=0
    while( current_sum !=sum and count<n):
        current_sum += arr[count]

        if( current_sum >sum):
            current_sum-=arr[first]
            first+=1
        elif(sum!=current_sum):
            count+=1



    res.append(first)
    res.append(count)
    return res



arr = [1, 2, 3, 4 ,5 ,6 ,7, 8 ,9 ,10]
#t = int(input())
print(fun1(arr, 10, 15))
