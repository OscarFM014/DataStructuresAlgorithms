"""Implement quick sort in Python.
Input a list.
Output a sorted list."""
def quicksort(array):
    quicksortR(array, 0, len(array) - 1)
    return array

def quicksortR(array, left, right):
    if(left >= right):
        return

    pivot = array[(left + right) / 2]
    index = partition(array, left, right, pivot)
    quicksortR(array, left, index - 1)
    quicksortR(array, index, right)

def partition(array, left, right, pivot):
    while(left <= right):
        while(array[left] < pivot):
            left += 1

        while(array[right] > pivot):
            right -= 1
        
        if(left <= right):
            swap(array, left, right)
            left += 1
            right -= 1
    return left

def swap(array, left, right):
    array[left], array[right] = array[right], array[left]



test = [21, 4, 1, 3, 9, 20, 25, 6, 21, 14]
print (quicksort(test))