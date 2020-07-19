#An element in a sorted array can be found in O(log n) time via binary search.
# But suppose we rotate an ascending order sorted array at some pivot unknown to you beforehand.
# So for instance, 1 2 3 4 5 might become 3 4 5 1 2.
# Devise a way to find an element in the rotated array in O(log n) time.
def SearchRotatedArray(arr,key):
    n=len(arr)-1;
    pivot=FindPivot(arr,0,n)
    print("pivot",pivot)
    if(pivot==-1):
        #the array not rotated
        return  BinarySearch(arr,0,n,key)
    if(arr[pivot]==key):
        return pivot
    if(arr[0]<=key):
        BinarySearch(arr, 0, pivot-1, key)
    return BinarySearch(arr,pivot+1,n,key)
def FindPivot(arr,start,end):
    if(start>end):
        return -1
    if(start==end):
        return start
    mid=int((start+end)/2)
    if(mid<end and arr[mid]>arr[mid+1]):
        return mid
    if(mid>start and arr[mid-1]>arr[mid]):
        return mid-1;
    if(arr[start]>=arr[mid]):
        return FindPivot(arr,start,mid-1)
    return FindPivot(arr,mid+1,end)


def BinarySearch(arr, l, h, key):
    if l > h:
        return -1

    mid = (l + h) // 2
    if arr[mid] == key:
        return mid

        # If arr[l...mid] is sorted
    if arr[l] <= arr[mid]:

        # As this subarray is sorted, we can quickly
        # check if key lies in half or other half
        if key >= arr[l] and key <= arr[mid]:
            return BinarySearch(arr, l, mid - 1, key)
        return BinarySearch(arr, mid + 1, h, key)

        # If arr[l..mid] is not sorted, then arr[mid... r]
    # must be sorted
    if key >= arr[mid] and key <= arr[h]:
        return BinarySearch(arr, mid + 1, h, key)
    return BinarySearch(arr, l, mid - 1, key)


# Driver program
arr = [4, 5, 6, 7, 8, 9, 1, 2, 3]
key = 4
value = SearchRotatedArray(arr,key)
if value != -1:
    print ("Index:",value)
else:
    print ("Key not found")




