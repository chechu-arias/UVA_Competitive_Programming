
def min_casero(inp):
    min_v = 0
    pos_v = -1
    for pos in range(len(inp)):
        if min_v == 1:
            break
        val = inp[pos]
        if val != 0 and (pos_v == -1 or val < min_v):
            min_v = val
            pos_v = pos
    return min_v, pos_v


n_cases = int(input())

input()

for case in range(n_cases):

    n_candidatates = int(input())
    removed = []
    candidates = []
    candidates_cont = [0]*n_candidatates

    for j in range(n_candidatates):
        candidates.append(input().strip())
    
    votes = []
    voting_people = 0

    for i in range(1001):
        try:
            aux = ""
            aux = input()
        except:
            pass
        if aux != "":
            voting_people += 1
            votes.append([])
            votes[i]= list(map(int, aux.split(" ")))
        else:
            break
    
    while True:

        for i in range(voting_people):
            for j in range(len(votes[i])):
                if (votes[i][j]-1) not in removed:
                    candidates_cont[votes[i][j]-1] += 1
                    break

        val_max = max(candidates_cont)
        pos_max = candidates_cont.index(val_max)
        
        if len(removed) > 0:
            val_min, pos_min = min_casero(candidates_cont)
        else:
            val_min = min(candidates_cont)
            pos_min = candidates_cont.index(val_max)

        if val_max > voting_people/2:
            print(candidates[pos_max])
            break
        elif val_max == val_min:
            for i in range(len(candidates)):
                if i not in removed:
                    print(candidates[i])
            break
        else:
            for i in range(len(candidates)):
                if candidates_cont[i] == val_min:
                    removed.append(i)
            
        candidates_cont = [0] * n_candidatates
    
    if (case+1) != n_cases:
        print()