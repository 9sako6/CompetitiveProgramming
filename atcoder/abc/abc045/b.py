sa = list(input())
sb = list(input())
sc = list(input())

s = {'a': sa, 'b': sb, 'c': sc}
turn = 'a'
while True:
    st = s[turn]
    if len(st) > 0:
        turn = st.pop(0)
    else:
        if turn == 'a':
            print('A')
            exit()
        elif turn == 'b':
            print('B')
            exit()
        elif turn == 'c':
            print('C')
            exit()
