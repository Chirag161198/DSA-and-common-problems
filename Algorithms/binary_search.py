def binary_search(array, x):
    low = 0
    high = len(array) - 1
    while low<=high:
        mid = int(low+high)//2
        if(array[mid]==x):
            return mid
        elif(array[mid]<x):
            low = mid + 1
        else:
            high = mid - 1
    return None

my_list = [1,3,4,5,7,9]

print(binary_search(my_list,3)) # 1
print(binary_search(my_list,6)) # None
