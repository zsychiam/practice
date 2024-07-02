a = int(input())
b = int(input())
c = int(input())

if a >= b and a >= c:  
    print("          Петя")
    if b >= c:  
        print("  Вася")
        print("                  Толя")
    else:          
        print("  Толя")
        print("                  Вася")
    print("   II      I      III  ")

elif b >= a and b >= c:  
    print("          Вася")
    if a >= c:  
        print("  Петя")
        print("                  Толя")
    else:          
        print("  Толя")
        print("                  Петя")
    print("   II      I      III  ")

else:  
    print("          Толя")
    if a >= b:  
        print("  Петя")
        print("                  Вася")
    else:          
        print("  Вася")
        print("                  Петя")
    print("   II      I      III  ") 
