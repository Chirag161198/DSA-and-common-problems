def findSmallest(array):
    min_index = 0
    n = len(array)
    for i in range(1,n):
        if(array[i]<array[min_index]):
            min_index = i
    return min_index

def SelectionSort(array):
    newArr = []
    for _ in range(0,len(array)):
        min_index = findSmallest(array)
        newArr.append(array.pop(min_index))
    return newArr

print(SelectionSort([3,4,1,2,5,6,2]))
print(SelectionSort([5,3,6,2,10]))