a = int(input())
print(max(a % 10 + (a // 10) % 10, (a // 10) % 10 + (a // 100) % 10), 
      min(a % 10 + (a // 10) % 10, (a // 10) % 10 + (a // 100) % 10),
      sep="")
