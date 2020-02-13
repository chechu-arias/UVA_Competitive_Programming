def get_solution(res, used_sums, sums, cont_res):

    if cont_res == len(res):
        return res

    for pos in range(len(sums)):
        if used_sums[pos] == 0:
            val = sums[pos] - res[0]
            used_sums[pos] = cont_res+1
            aux = 1
            filled = []
            canbe = False
            for fillpos in range(len(sums)):
                if used_sums[fillpos] == 0 and val + res[aux] == sums[fillpos]:
                    aux += 1
                    used_sums[fillpos] = cont_res+1
                    filled.append(fillpos)
                    if aux == cont_res:
                        canbe = True
                        break

            if canbe:
                res[cont_res] = val
                return get_solution(res, used_sums, sums, cont_res+1)
            
            for clearpos in range(len(filled)):
                used_sums[clearpos] = 0


while True:
    try:
        inp = list(map(int, input().strip().split(" ")))
        
        n_numbers = inp[0]
        sums = sorted(inp[1:])
        used_sums = [0]*len(sums)
        res = [0]*n_numbers

        cont_res = 0

        first, second = sums[0], sums[1]

        for pos in range(2, len(sums)):

            calc = first + second - sums[pos]

            if (calc%2) == 0:

                res[0] = calc//2
                res[1] = first - res[0]
                res[2] = second - res[0]
                used_sums[0] = used_sums[1] = used_sums[pos] = 1
                cont_res = 3

                res = get_solution(res, used_sums, sums, cont_res)
                if res == None:
                    used_sums = [0]*len(sums)
                    cont_res = 0
                    res = [0]*n_numbers
                    continue

                if res != None:
                    for pos in range(len(res)-1):
                        print(res[pos], end=" ")
                    print(res[-1])
                    break
        

        if cont_res == 0:
            print("Impossible")
            continue


    except EOFError:
        break
