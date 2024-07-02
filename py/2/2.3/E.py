sum = 0
while (x := float(input())) != 0:
    if x >= 500:
        sum += x * 0.9
    else:
        sum += x
print(sum)