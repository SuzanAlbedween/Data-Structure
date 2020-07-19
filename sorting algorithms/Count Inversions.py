#Count Inversions in an array | (Using Merge Sort)
#Inversion Count for an array indicates – how far (or close) the array is from being sorted.
# If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum.
#Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j
#Example:
#Input: arr[] = {8, 4, 2, 1}
#Output: 6
#Explanation: Given array has six inversions:
#(8,4), (4,2),(8,2), (8,1), (4,1), (2,1).


# Function to Use Inversion Count
def mergesort(arr,n):
    temparr=[0]*n
    return _mergesort(arr,temparr,0,n-1)

# This Function will use MergeSort to count inversions
def _mergesort(arr,temparr,left,right):
    # A variable var_count is used to store
    # inversion counts in each recursive call
    var_count=0

    if(left<right):
        mid=(right+left)//2
        var_count+=_mergesort(arr,temparr,left,mid)
        var_count+=_mergesort(arr,temparr,mid+1,right)
        var_count+=merge(arr,temparr,left,mid,right)

    return var_count
# This function will merge two subarrays in a single sorted subarray
def merge(arr,temparr,left,mid,right):

    i=left
    j=mid+1
    k=left
    counter=0
    while(i<=mid and j<=right):
        if(arr[i]<=arr[j] ):
            temparr[k]=arr[i]
            k+=1
            i+=1
        else:
            temparr[k]=arr[j]
            counter+=(mid-i+1)
            j += 1
            k += 1
    while(i<=mid):
        temparr[k]=arr[i]
        k+=1
        i+=1

    while(j<=right):
        temparr[k]=arr[j]
        k+=1
        j+=1

    for loopvar in range(left,right+1):
        arr[loopvar]=temparr[loopvar]
    return counter
arr = [1,20, 6, 4, 5]
n = len(arr)
result = mergesort(arr, n)
print("Number of inversions are", result)