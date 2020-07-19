#Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
def sub_array_max_sum(arr):
    dp = []
    n = len(arr)
    dp.append(arr[0])
    for i in range(1, n):
        dp.append(max(arr[i], dp[i - 1] + arr[i]))
        print(dp)
    print(max(dp))



arr1=[1 ,2, 3 ,-2 ,5]
arr2=[-1, -2, -3 ,-4]
sub_array_max_sum(arr2)
#print(-10-(-9))