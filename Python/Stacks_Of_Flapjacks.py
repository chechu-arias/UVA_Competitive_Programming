
while True:
    try:
        inp = input()
        print(inp)
        inp = list(map(int, inp.replace("  ", " ").split(" ")))

        size = len(inp)

        while size > 0:

            max_val = max(inp[:size])
            max_pos = inp.index(max_val)

            if (max_pos+1) == size:
                size -= 1
            elif max_pos == 0:
                print(len(inp)-size+1, end=" ")
                inp[:size] = inp[:size][::-1]
            else:
                print(len(inp)-max_pos, end=" ")
                inp[:max_pos+1] = inp[:max_pos+1][::-1]

        print(0)

    except EOFError:
        exit()