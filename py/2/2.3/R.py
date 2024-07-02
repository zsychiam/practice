a = int(input())
count = 0
while a != 1:
    if count != 0:
        print("*", end=" ")
    found_divisor = False
    for i in range(2, int(a ** 0.5) + 1):
        if a % i == 0:
            print(i, end=" ")
            a //= i
            found_divisor = True
            break
    if not found_divisor:
        print(a, end=" ")
        a = 1
    count += 1