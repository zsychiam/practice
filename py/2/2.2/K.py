a = int(input())
b = a % 10
c = (a // 10) % 10
d = (a // 100) % 10
if max(b, c, d) + min(b, c, d) == 2 * (b + c + d - max(b, c, d) - min(b, c, d)):
    print("YES")
else:
    print("NO")