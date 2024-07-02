counter = 0
for i in range(int(input())):
    j = 2
    if (n := int(input())) > 1:
        counter += 1
        if n == 2:
            counter += 1
        while n % j:
            if j > n ** 0.5:
                break
            j += 1
        else:
            counter -= 1
print(counter)