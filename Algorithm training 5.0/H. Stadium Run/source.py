import sys

def find_min_positive_double(*args):
    min_positive = sys.float_info.max

    for num in args:
        if num > 0 and num < min_positive:
            min_positive = num

    if min_positive == sys.float_info.max:
        print("Нет положительных чисел")
    
    return min_positive

def main():
    L, x1, v1, x2, v2 = map(float, input().split())

    time = -1

    if x1 == x2 or x1 == L - x2 or x2 == L - x1:
        time = 0
    elif v1 != 0 and v2 != 0:
        if v1 != v2:
            time = find_min_positive_double(abs(x2 - x1) / abs(v1 - v2), (L - x1 - x2) / (v1 + v2), (L + x2 - x1) / (v1-v2), (L + x1 - x2) / (v2 - v1))
        else:
            if v1 > 0:
                if (L - x1 - x2) / (2*v1) > 0:
                    time = min(abs(L - abs(x2 + x1) / 2) / v1, (L - x1 - x2) / (2*v1))
                else:
                    time = abs(L - abs(x2 + x1) / 2) / v1
            else:
                if (L - x1 - x2) / (2*v1) > 0:
                    time = min((abs(x2 + x1)/2 )/ abs(v1), (L - x1 - x2) / (2*v1))
                else:
                    time = (abs(x2 + x1)/2 )/ abs(v1)
    elif v1 == 0 and v2 == 0:
        if x1 == x2:
            time = 0
    else:
        if x1 == x2:
            time = 0
        else:
            if v1 == 0:
                if x2 > x1:
                    if v2 > 0:
                        time = (L - x2 + x1) / v2
                    else:
                        time = (x2 - x1) / v2
                else:
                    if v2 > 0:
                        time = (x1 - x2)  / v2
                    else:
                        time = (x2 + L - x1) / v2
            else:
                if x1 > x2:
                    if v1 > 0:
                        time = (L - x1 + x2) / v1
                    else:
                        time = (x1 - x2) / v1 
                else:
                    if v1 > 0:
                        time = (x2 - x1) / v1
                    else:
                        time = (x1 + L - x2) / v1

    if time > L:
        time = -1

    if time == -1:
        print("NO")
    else:
        print("YES")
        print("{:.10f}".format(time))

if __name__ == "__main__":
    main()
