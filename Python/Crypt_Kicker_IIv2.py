
n_cases = int(input())

input()
for case in range(1, n_cases+1):

    line = input()
    inp = []

    order = ["t", "h", "e", " ", "q", "u", "i", "c", "k", " ", "b", "r", "o", "w", "n", " ", "f", "o", "x", " ", "j", "u", "m", "p", "s", " ", "o", "v", "e", "r", " ", \
        "t", "h", "e", " ", "l", "a", "z", "y", " ", "d", "o", "g"]
    
    space_pos = [3,9,15,19,25,30,34,39]
    
    conversion = dict()
    found = False

    while len(line) > 0:
        
        appears = dict()
        inp.append(line)

        for pos in range(len(line)):

            try:
                appears[line[pos]].append(pos)
            except KeyError:
                appears[line[pos]] = [pos]
        
        if (len(appears) == 27) and (appears[" "] == space_pos) and (line[0:2] == line[31:33]):
            for pos in range(len(line)):
                if conversion.get(line[pos], []) == []:
                    conversion[line[pos]] = order[pos]
            found = True
            break

        try:
            line = input()
        except EOFError:
            break

    if not found:
        if case == n_cases:
            print("No solution.", end="")
        else:
            print("No solution.")
    
    else:

        while len(line) > 0:
            try:
                line = input()
            except EOFError:
                break
            inp.append(line)
        
        for pos in range(len(inp)):

            for car in inp[pos]:
                print(conversion[car], end="")
            
            if (pos+1 != len(inp)):
                print()

    print()
    
    


