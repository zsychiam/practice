n, a = int(input()), int(input())
for _ in range(n - 1):
    b = int(input())
    while b:
        a, b = b, a % b
print(a)