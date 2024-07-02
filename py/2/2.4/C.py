for z in range(1, x := int(input()) + 1):
    if z in (sum(range(i)) for i in range(x)):
        print(z)
    else:
        print(z, end=' ')