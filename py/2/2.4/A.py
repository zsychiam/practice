for i in range(1, (x := int(input())) + 1):
    for j in range(1, x + 1):
        if j < x:
            print(i * j, end=' ')
        else:
            print(i * j)    