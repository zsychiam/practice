summ = 0
for _ in range(int(input())):
    summ += sum(map(int, list(input())))
print(summ)