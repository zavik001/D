N = int(input())
a = list(map(int, input().split()))

M = int(input())
b = list(map(int, input().split()))

result = []
i = j = 0
while i < N and j < M:
    if a[i] <= b[j]:
        result.append(a[i])
        i += 1
    else:
        result.append(b[j])
        j += 1

while i < N:
    result.append(a[i])
    i += 1

while j < M:
    result.append(b[j])
    j += 1

for val in result:
    print(val, end=" ")
