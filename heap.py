
def heapify(a, n, i):
    while True:
        largest = i
        l = 2 * i + 1
        r = 2 * i + 2

        if l < n and a[l] > a[largest]:
            largest = l

        if r < n and a[r] > a[largest]:
            largest = r

        if largest == i:
            break

        a[i], a[largest] = a[largest], a[i]
        i = largest


def heap_sort(a):
    n = len(a)

    # Build Max Heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(a, n, i)

    # Sort in Ascending Order
    for i in range(n - 1, 0, -1):
        a[0], a[i] = a[i], a[0]
        heapify(a, i, 0)


a = list(map(int, input("Enter elements: ").split()))

heap_sort(a)

print("Sorted Array:", a)
print("Heap Used: Max Heap")
print("Time Complexity: O(n log n)")
print("Space Complexity: O(1)")
