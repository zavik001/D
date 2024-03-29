import math

def is_binary_decimal(num):
   for digit in str(num):
      if digit not in ['0', '1']:
         return False
   return True

def can_be_binary_product(n):
   for i in range(1, int(math.sqrt(n)) + 1):
      if n % i == 0:
         if is_binary_decimal(i) and is_binary_decimal(n // i):
               return True
   return False

t = int(input())

for _ in range(t):
   n = int(input()) 
   if can_be_binary_product(n):
      print("YES")
   else:
      print("NO")
