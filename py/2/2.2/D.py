a = int(input())
b = int(input())
c = int(input())

if a >= b and a >= c:
    print("1. Петя")
    if b >= c:
        print("2. Вася")
        print("3. Толя")
    else:
        print("2. Толя")
        print("3. Вася")

elif b >= a and b >= c:
    print("1. Вася")
    if a >= c:
        print("2. Петя")
        print("3. Толя")
    else:
        print("2. Толя")
        print("3. Петя")

else:
    print("1. Толя")
    if a >= b:
        print("2. Петя")
        print("3. Вася")
    else:
        print("2. Вася")
        print("3. Петя")