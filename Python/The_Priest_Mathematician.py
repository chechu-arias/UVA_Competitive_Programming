
results = []

while True:

    try:

        N = int(input())

        #Number already computed
        if len(results) > N:

            print(results[N-1])

        #First number
        elif len(results) == 0:

            res = 0
            cont = 1
            local = 0
            aumento = 0
            for i in range(N):
                res += 2**aumento
                results.append(res)
                local += 1
                if local == cont:
                    cont += 1
                    aumento += 1
                    local = 0

            print(res)

        #Compute from last value stored
        else:

            indic = len(results)
            cont = 0
            for i in range(1, 10000):
                cont += i
                if cont > indic:
                    break
            
            res = results[-1]
            aumento = i-1
            local = i - (cont-indic)
            cont = i

            for i in range(indic, N):
                res += 2**aumento
                results.append(res)
                local += 1
                if local == cont:
                    cont += 1
                    aumento += 1
                    local = 0
            
            print(res)

    except EOFError:

        break
