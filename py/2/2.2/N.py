a = int(input())
b = a % 10
c = (a // 10) % 10
d = (a // 100) % 10

if min(b, c, d) == 0:
    print(b + c + d - min(b, c, d) - max(b, c, d), 
          min(b, c, d), 
          " ", 
          max(b, c, d), 
          b + c + d - min(b, c, d) - max(b, c, d), 
          sep="")
else:
    print(min(b, c, d), 
          b + c + d - min(b, c, d) - max(b, c, d), 
          " ", 
          max(b, c, d), 
          b + c + d - min(b, c, d) - max(b, c, d), 
          sep="")
