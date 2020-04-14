def quicksort(arr):
    if len(arr) < 2:
        return arr
    else:
        pivot = arr[0]
        smallThanPivot = []
        greatThanPivot = []
        for x in arr[1:]:
            if x<=pivot:
                smallThanPivot = smallThanPivot + [x]
            else:
                greatThanPivot = greatThanPivot + [x]
        return quicksort(smallThanPivot) + [pivot] + quicksort(greatThanPivot)

print(quicksort([7,1]))
print(quicksort([33,10,15]))
print(quicksort([10,33,7,15]))
print(quicksort([5,2,1,4,3]))