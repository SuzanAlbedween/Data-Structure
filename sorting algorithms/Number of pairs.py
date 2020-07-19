#Given two arrays X and Y of positive integers, find number of pairs such that xy > yx (raised to power of)
# where x is an element from X and y is an element from Y.
import math

def Number_of_pairs(arr1,arr2,n,m):
    if(n>=m):
      return  count_num_of_pairs(arr1,arr2,n,m)
    else:
        return count_num_of_pairs(arr2,arr1,m,n)
def count_num_of_pairs(biggest,smallest,n,m):
    res=0
    for i in range(n):
        for j in range(m):
            if(math.pow(biggest[i],smallest[j])>math.pow(smallest[j],biggest[i])):
                res+=1
    return res
arr1=[2 ,1 ,6]
arr2=[1,5]
print(count_num_of_pairs(arr1,arr2,len(arr1),len(arr2)))


