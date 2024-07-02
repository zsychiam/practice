N = int(input())
M = int(input())
result = 0
while (N % 10 != 0) or (M % 10 != 0):
    temp = (N % 10) + (M % 10)
    temp %= 10
    result *= 10
    result += temp
    N = int(N / 10)
    M = int(M / 10)
print(str(result)[::-1])
