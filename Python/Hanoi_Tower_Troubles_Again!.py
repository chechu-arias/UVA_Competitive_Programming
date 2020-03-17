import math

def isRoot(num):
    calc = int(math.sqrt(num))

    if calc*calc == num:
        return True
    
    return False


cases = int(input())

allsolutions = dict()

for c in range(cases):
    N = int(input())

    if allsolutions.get(N, []) == []:

        roots = [0 for i in range(N)]
        actual = 1
        sol = 0
        while True:
            can_continue = False
            for pos in range(N):
                if roots[pos] == 0 or isRoot(actual+roots[pos]):
                    roots[pos] = actual
                    can_continue = True
                    break
            if not can_continue:
                sol = actual-1
                break
            actual += 1
        
        allsolutions[N] = sol
        print(sol)
    
    else:

        print(allsolutions[N])