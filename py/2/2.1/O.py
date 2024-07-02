a = int(input())
b = int(input())
c = int(input())
print(f"{(a + (b + c) // 60) % 24:02}", ":", f"{(b + c) % 60:02}", sep="")