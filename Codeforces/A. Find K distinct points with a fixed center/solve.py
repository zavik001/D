def generate_points(xc, yc, k):
    points = []
    
    if k % 2 == 0:
        for i in range(k // 2):
            points.append((xc + i, yc + i))
            points.append((xc - i, yc - i))
    else:
        points.append((xc, yc))
        for i in range(1, k // 2 + 1):
            points.append((xc + i, yc + i))
            points.append((xc - i, yc - i))
    
    return points

def solve():
    t = int(input())
    results = []
    for _ in range(t):
        xc, yc, k = map(int, input().split())
        points = generate_points(xc, yc, k)
        for point in points:
            print(point[0], point[1])

solve()
