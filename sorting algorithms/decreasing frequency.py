#Print the elements of an array in the decreasing frequency
# if 2 numbers have same frequency then print the one which came first.
#Input:  arr[] = {2, 5, 2, 8, 5, 6, 8, 8}
#Output: arr[] = {8, 8, 8, 2, 2, 5, 5, 6}
#Input: arr[] = {2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8}
#Output: arr[] = {8, 8, 8, 2, 2, 5, 5, 6, -1, 9999999}
#Time Complexity: O(nlogn)
import operator
class frequency:
    def __init__(self,v,c):
        self.value=v
        self.count=c
def partition(arr ,low, high):
    pivot=arr[high]
    i=low-1
    for j in range(low,high):
        if(arr[j]<pivot):
            i+=1
            arr[i],arr[j]=arr[j],arr[i]
    arr[i+1],arr[high]=arr[high],arr[i+1]
    return (i+1)
def quicksort(arr,low,high):
    if(low<high):
        pi=partition(arr,low,high)
        quicksort(arr,low,pi-1)
        quicksort(arr,pi+1,high)
def sortbyfrequency(arr,n):
    quicksort(arr,0,n-1)
    print(arr)
    f_arr=[]
    for i in range(n):
        c=f_arr.count(arr[i])
        if(c<1):
            f_arr.append(frequency(arr[i],1))
        else:
            f_arr.insert(arr[i],c+1)
    for k in range(len(f_arr)):
     print(f_arr[k].value ," ",f_arr[k].count)













arr= [2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8]
sortbyfrequency(arr,len(arr))
