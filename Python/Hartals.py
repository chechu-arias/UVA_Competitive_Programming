
n_cases = int(input())

for s in range(n_cases):

    n_days = int(input())
    n_parties = int(input())
    res = 0
    hartals = []
    for i in range(n_parties):
        hartal = int(input())
        if hartal < n_days:
            hartals.append(hartal)
    
    for day in range(1, n_days+1):
        hartal_cond = (day%7)
        if hartal_cond == 6 or hartal_cond == 0:
            continue
        else:
            cont_cond = False
            for hartal in hartals:
                if day%hartal == 0:
                    res += 1
                    cont_cond = True
                    break
            if cont_cond:
                continue
    
    print(res)

