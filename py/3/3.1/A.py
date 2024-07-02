for _ in range(int(input())):
    if (word := input())[0] not in 'абв':
        print('NO')
        break
else:
    print('YES')    