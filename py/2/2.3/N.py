a = int(input())
sum = 0
if a == 1:
    print("NO")
    sum += 1
for i in range(2, int(a ** 0.5) + 1):
    if a % i == 0:
        print("NO")
        sum += 1
        break
if sum == 0:
    print("YES")