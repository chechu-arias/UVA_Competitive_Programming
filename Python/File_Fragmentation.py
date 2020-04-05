cases = int(input())

input()

for c in range(cases+1):

    files = list()
    diff_files = dict()
    
    try:
        file = input().replace("\r","")
    except EOFError:
        break

    while len(file) > 0:
        if diff_files.get(file, []) == []:
            diff_files[file] = 1
            files.append(file)
        try:
            file = input().replace("\r","")
        except EOFError:
            break
    
    if len(files) <= 2:
        print(files[0]+files[-1])
        
    else:
        files = sorted(files, key=lambda x: len(x))

        files_with_min_length = [f for f in files if len(f) == len(files[0])]
        files_with_max_length = [f for f in files if len(f) == len(files[-1])]
        if len(files_with_min_length) == 1:
            files_with_min_length.extend( [f for f in files if len(f) == len(files[1])] )
            files_with_max_length.extend( [f for f in files if len(f) == len(files[-2])] )
        
        pairs = dict()
        res_pair = ""
        for mi in files_with_min_length:
            for ma in files_with_max_length:
                if len(mi+ma) == len(files[0])+len(files[-1]):
                    if pairs.get(mi+ma, []) == []:
                        pairs[mi+ma] = 1
                    else:
                        pairs[mi+ma] += 1
                        if pairs[mi+ma] == len(files_with_min_length):
                            res_pair = mi+ma
                            break

                    if pairs.get(ma+mi, []) == []:
                        pairs[ma+mi] = 1
                    else:
                        pairs[ma+mi] += 1
                        if pairs[ma+mi] == len(files_with_min_length):
                            res_pair = ma+mi
                            break

            if len(res_pair) > 0:
                break

        print(res_pair)
    
    if c < (cases-1):
        print()
    

    