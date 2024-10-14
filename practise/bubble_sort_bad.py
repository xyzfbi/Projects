import random
print("Enter array size: ")
length = int(input())
arr = [random.randint(0,101) for i in range(length)]
print(*arr)
for i in range(length - 1):
    for j in range(length - i - 1):
        if arr[j] > arr[j + 1]:
            arr[j], arr[j + 1] = arr[j + 1], arr[j]

print(*arr)
#i = 0 j