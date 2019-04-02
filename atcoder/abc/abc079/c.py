a, b, c, d = list(input())

ops = ['-', '+']
for op1 in ops:
    for op2 in ops:
        for op3 in ops:
            if eval(a+op1+b+op2+c+op3+d) == 7:
                print(a+op1+b+op2+c+op3+d+'=7')
                exit()
