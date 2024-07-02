a = 0
b = 0
while (x := input()) != "СТОП":
    if x == "СЕВЕР":
        a += int(input())
    if x == "ЮГ":
        a -= int(input())
    if x == "ВОСТОК":
        b += int(input())
    if x == "ЗАПАД":
        b -= int(input())
print(a, b, sep='\n')