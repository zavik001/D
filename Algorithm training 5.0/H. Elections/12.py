def find_min_and_transform_vector(vector):
   n = len(vector)
   result = []
   for i in range(n):
      min_value = vector[-1] - vector[i]
      vector[-1], vector[i] = vector[i], vector[-1]
      result.append((min_value, vector.copy()))
      vector[-1], vector[i] = vector[i], vector[-1]
   return result

vector = [1, 2, 2, 4, 4]
result = find_min_and_transform_vector(vector)

for i, (min_value, transformed_vector) in enumerate(result):
   print(f"Для i = {i}, min = {min_value}, преобразованный вектор = {transformed_vector}")
def find_min_and_transform_vector(vector):
    n = len(vector)
    prefix_sum = [0] * (n + 1)
    for i in range(n):
        prefix_sum[i+1] = prefix_sum[i] + vector[i]
    result = []
    for i in range(n):
        l, r = i + 1, n
        while l < r:
            mid = (l + r) // 2
            if vector[mid] > vector[i]:
                r = mid
            else:
                l = mid + 1
        min_value = (prefix_sum[n] - prefix_sum[l]) - (n - l) * vector[i]
        vector[i] += min_value
        result.append((min_value, vector.copy()))
        vector[i] -= min_value
    return result

vector = [1, 2, 2, 4, 4]
result = find_min_and_transform_vector(vector)

for i, (min_value, transformed_vector) in enumerate(result):
    print(f"Для i = {i}, min = {min_value}, преобразованный вектор = {transformed_vector}")
