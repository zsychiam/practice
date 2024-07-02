counter, temp = 0, 0
for _ in range(int(input())):
    while (x := input()) != 'ВСЁ':
        if x == 'зайка':
            temp += 1
    if temp:
        counter += 1
        temp = 0
print(counter)