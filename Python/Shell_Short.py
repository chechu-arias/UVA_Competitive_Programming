n_cases = int(input())

for case in range(n_cases):
    
    n_turtles = int(input())
    arrived = list()
    desired = list()
    
    for i in range(n_turtles):
        arrived.insert(0,input())
    
    for i in range(n_turtles):
        desired.insert(0,input())

    not_in_order = set()
    cont = 0
    for out_elem in desired:
        if out_elem in not_in_order:
            break
        cont += 1
        for in_elem in arrived:
            if in_elem == out_elem:
                break
            else:
                not_in_order.add(in_elem)
    
    reorder = desired[cont:]

    for turtle in reorder:
        print(turtle)
    

    print()