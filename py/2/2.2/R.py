a = int(input())
b = int(input())
c = int(input())
if max(a, b, c) ** 2 == min(a, b, c) ** 2 + (a + b + c - max(a, b, c) - min(a, b, c)) ** 2:
    print("100%")
elif max(a, b, c) ** 2 > min(a, b, c) ** 2 + (a + b + c - max(a, b, c) - min(a, b, c)) ** 2:
    print("велика")
else:
    print("крайне мала")