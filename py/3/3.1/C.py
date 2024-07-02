length = int(input())
for _ in range(int(input())):
    line = input()
    print(line[:length - 3].ljust(length, ".") if len(line) > length else line)