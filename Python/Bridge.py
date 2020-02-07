
def count_order(list_to_order):
    min_v = min(list_to_order)
    max_v = max(list_to_order)
    temp = [0]*(max_v-min_v+1)
    for val in list_to_order:
        cont = val - min_v
        temp[cont] += 1
    
    res = []
    aux = 0
    for pos in range(len(temp)):
        num = temp[pos]
        while num > 0:
            res.append(pos + min_v)
            num -= 1
    return res


def crossing(speeds):

    selected = []
    n_remaining = len(speeds)

    if n_remaining > 3:

        first = speeds[0]
        second = speeds[1]
        last = speeds[-1]
        almost_last = speeds[-2]

        if (2*second) < (first + almost_last):

            selected = [(first, second), (first,), (almost_last, last), (second,)]
        
        else:

            selected = [(first, last), (first,), (first, almost_last), (first,)]

        speeds.pop()
        speeds.pop()
    
    elif n_remaining == 3:

        selected = [(speeds[0], speeds[2]), (speeds[0],), (speeds[0], speeds[1])]
        speeds[:] = []
    
    elif n_remaining == 2:

        selected = [(speeds[0], speeds[1])]
        speeds[:] = []
    
    else:

        selected = [(speeds[0],)]
        speeds[:] = []
    
    return selected




n_cases = int(input())

for case in range(1, n_cases+1):
    input()
    n_person = int(input())
    speeds = list()
    for i in range(n_person):
        speeds.append(int(input()))

    time = 0
    result_crossing = []

    if n_person > 15:
        speeds = count_order(speeds)
    else:
        speeds = sorted(speeds)
    
    while len(speeds):

        strategy = crossing(speeds)
        for step in strategy:
            time += max(step)
            result_crossing.append(step)

    print(time)
    for step in result_crossing:
        print(" ".join(map(str, step)))

    if case < n_cases:
        print()