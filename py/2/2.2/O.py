a = int(input())
b = int(input())
c = a % 10
d = (a // 10) % 10
e = b % 10
f = (b // 10) % 10
print(max(c, d, e, f), (c + d + e + f - max(c, d, e, f) - min(c, d, e, f)) % 10, min(c, d, e, f), sep="")