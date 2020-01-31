n_cases = int(input())

input()
for case in range(n_cases):
    
    RAM = [0 for i in range(1000)]
    register = [0 for i in range(10)]
    
    cont = 0
    pos = -1
    res = 0
    repeating_code = False

    while True:

        if not repeating_code:   
            inp = int(input())
        else:
            inp = RAM[pos]

        if cont == pos:
            repeating_code = False

        if not repeating_code:
            RAM[cont] = inp

        op = inp // 100
        d = (inp % 100) // 10

        if op == 1:
            res += 1
            break
        elif op in (2, 3, 4):
            n = (inp % 100) % 10
            if op == 2:
                register[d] = n
            elif op == 3:
                register[d] += n
            elif op == 4:
                register[d] *= n
        elif op in (5, 6, 7):
            s = (inp % 100) % 10
            if op == 5:
                register[d] = register[s]
            elif op == 6:
                register[d] += register[s]
            elif op == 7:
                register[d] *= register[s]
        elif op in (8, 9):
            a = (inp % 100) % 10
            if op == 8:
                register[d] = RAM[register[a]]
            elif op == 9:
                RAM[register[a]] = register[d]
        elif op == 0:
            s = (inp % 100) % 10
            if register[s] != 0:
                repeating_code = True
                pos = register[d] - 1

        if register[d] >= 1000:
            register[d] %= 1000

        res += 1
        
        if not repeating_code:
            cont += 1
        else:
            pos += 1

    EOF = False
    try:
        inp = input()
    except EOFError:
        EOF = True
    while(inp != '' or EOF):
        try:
            inp = input()
        except EOFError:
            break

    print(res)
    if (case+1) < n_cases:
        print()