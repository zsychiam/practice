int = int(input())
str = input()
ans1 = "Я больше никогда не буду писать "
ans2 = '"'
ans3 = "!\n" 
ans = "Я больше никогда не буду писать" + """ + str + """ + "!\n" 
print((ans1 + ans2 + str + ans2 + ans3) * int)