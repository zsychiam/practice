s = input()
a = int(input())
b = int(input())
c = int(input())
print("================Чек================")
print("Товар:", s.rjust(29, " "), sep="")
print("Цена:", end="")
print((str(b) + "кг * " + str(a) + "руб/кг").rjust(35 - 5))
print("Итого:", f"{a * b:26}", "руб", sep="")
print("Внесено:", f"{c:24}", "руб", sep="")
print("Сдача:", f"{c - a * b:26}", "руб", sep="")
print("===================================", sep="")