import math

while True:
    try:
        inp = input().split(" ")

        ram_rate = int(inp[0])
        depth = int(inp[1])

        if ram_rate == 1:

            print(ram_rate)

        elif depth == 1:

            print(math.factorial(ram_rate))

        else:

            n_nodes = 1
            n_nosons = 1

            for i in range(1, depth+1):
                if i != depth:
                    n_nosons += ram_rate**i
                n_nodes += ram_rate**i

            aux = math.factorial(n_nodes-1)
            cont = 1

            while n_nosons >= 3:
                aux = aux//(n_nosons**(ram_rate**cont))
                n_nosons = n_nosons//ram_rate
                cont += 1

            print(aux)

    except EOFError:
        break