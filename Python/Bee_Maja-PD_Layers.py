
solutions = dict()
solutions[1] = (0,0)

movements = [(-1,+1), (-1,0), (0,-1), (+1,-1), (+1,0), (0,+1), (-1,+1)]

while True:
    try:

        willy_n = int(input())

        if willy_n in solutions:

            print(f"{solutions[willy_n][0]} {solutions[willy_n][1]}")
        
        else:

            aux_willy = willy_n
            aux_willy -= 1
            dist_to_center = 0
            total_layers = 1

            while aux_willy > 0:

                dist_to_center += 1
                aux_willy -= 6*dist_to_center
                total_layers += 6*dist_to_center

            total_layers -= 6*dist_to_center-1
            aux_willy += (6*dist_to_center)-1
            despl_relat = aux_willy

            sol = (dist_to_center, 0)
            n_movements_in_type = 0
            mov_type = 0
            mov_type_offset = 0

            for val in range(total_layers, willy_n+1):
                
                if n_movements_in_type < (dist_to_center):

                    n_movements_in_type += 1
                    sol = (sol[0]+movements[mov_type][0], sol[1]+movements[mov_type][1])

                    if mov_type == 0 and sol[1] == dist_to_center:
                        mov_type += 1
                        n_movements_in_type = 0

                else:

                    mov_type += 1
                    n_movements_in_type = 1
                    sol = (sol[0]+movements[mov_type][0], sol[1]+movements[mov_type][1])

                
                if solutions.get(val, []) == []:
                    solutions[val] = sol

            print(f"{sol[0]} {sol[1]}")
            

    except EOFError:
        break




