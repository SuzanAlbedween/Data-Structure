
#Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively
# i.e first element should be max value, second should be min value, third should be second max,
# fourth should be second min and so on...

#Note: O(1) extra space is allowed. Also, try to modify the input array as required.

def RearrangeArrayAlternately(arr):
    n=len(arr)
    start=0
    end=n-1
    while (start < n):
        k = end
        temp = arr[end]
        while (k > start):
            arr[k] = arr[k - 1]
            k -= 1
        arr[start] = temp
        start += 2




    return arr
arr=[1,2,3,4,5,6]
arr2=[10 ,20 ,30 ,40 ,50 ,60 ,70 ,80 ,90 ,100 ,110]
print(RearrangeArrayAlternately(arr2))