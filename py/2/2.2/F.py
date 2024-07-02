a = int(input())
if a % 4 or not a % 100 and a % 400:
    print("NO")
else:
    print("YES")