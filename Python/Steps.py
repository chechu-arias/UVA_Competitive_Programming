def calc_res(val):

    for i in range(1, val+1):
        if ((i+1)**2) >= val:
            break
    
    if val > (i+i**2):
        print(2*i+1)
        results[val] = 2*i+1
    else:
        print(2*i)
        results[val] = 2*i


results = dict()

n_cases = int(input())

for case in range(n_cases):
    inp = list(map(int, input().strip().split()))
    x, y = inp[0], inp[1]
    val = y - x
    if val == 0 or val == 1:
        print(val)
    elif val >= 2147395600:
        print(92681)
    elif results.get(val, -1) != -1:
        print(results[val])
        continue
    else:
        calc_res(val)

