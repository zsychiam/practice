s = str(input())
a = int(input())
b = int(input())
c = int(input())
print("Чек")
print(s, " - ", b, "кг - ", a, "руб/кг", sep="")
print("Итого: ", a * b, "руб", sep="")
print("Внесено: ", c, "руб", sep="")
print("Сдача: ", c - a * b, "руб", sep="")