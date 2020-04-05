cases = int(input())

input()

for c in range(cases+1):

    files = list()
    
    try:
        file = input().replace("\r","")
    except EOFError:
        break

    while len(file) > 0:
        files.append(file)
        try:
            file = input().replace("\r","")
        except EOFError:
            break
    
    if len(files) <= 2:
        print(files[0]+files[-1])
        
    else:

        all_posibilities = dict()
        for f1 in files:
            for f2 in files:
                if all_posibilities.get(f1+f2, []) == []:
                    all_posibilities[f1+f2] = 1
                else:
                    all_posibilities[f1+f2] += 1
                
                if all_posibilities.get(f2+f1, []) == []:
                    all_posibilities[f2+f1] = 1
                else:
                    all_posibilities[f2+f1] += 1

        max = -1
        res_pair = ""
        for file in all_posibilities.keys():
            if all_posibilities[file] > max:
                res_pair = file
                max = all_posibilities[file]
        print(res_pair)
    
    if c < (cases-1):
        print()
    

    