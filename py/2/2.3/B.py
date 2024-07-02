counter = 0
while (x := input()) != 'Приехали!':
    if 'зайка' in x:
        counter += 1
print(counter)