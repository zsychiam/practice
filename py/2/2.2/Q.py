a, b, c = float(input()), float(input()), float(input())
if not a and not b and not c:
    print('Infinite solutions')
elif not a and not b and c or b ** 2 < 4 * a * c:
    print('No solution')
elif b ** 2 == 4 * a * c:
    print(f'{-b / (2 * a):.2f}')
elif not a:
    print(f'{-c / b:.2f}')
else:
    roots = [(-b - (b ** 2 - 4 * a * c) ** 0.5) / (2 * a), (-b + (b ** 2 - 4 * a * c) ** 0.5) / (2 * a)]
    roots.sort()
    print(f'{roots[0]:.2f} {roots[1]:.2f}')