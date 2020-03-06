
solutions = dict()
solutions[1] = (0,0)

movements = [(-1,0), (0,-1), (+1,-1), (+1,0), (0,+1)]

while True:
    try:

        willy_n = int(input())

        if willy_n in solutions:

            print(f"{solutions[willy_n][0]} {solutions[willy_n][1]}")
        
        else:

            aux_willy = willy_n
            aux_willy -= 1
            dist_to_center = 0

            while aux_willy > 0:

                dist_to_center += 1
                aux_willy -= 6*dist_to_center

            aux_willy += (6*dist_to_center)-1
            despl_relat = aux_willy

            if despl_relat < (dist_to_center*6)//2:

                sol = (dist_to_center-1, 1)
                aux = 0

                while aux != despl_relat:
                    aux += 1
                    if sol[1] < dist_to_center and aux < dist_to_center:
                        sol = (sol[0]-1, sol[1]+1)
                    elif -sol[0] < dist_to_center:
                        sol = (sol[0]-1, sol[1])
                    elif sol[1] > 0:
                        sol = (sol[0], sol[1]-1)
                    else:
                        sol = (sol[0]+1, sol[1]-1)

            else:

                sol = (-dist_to_center+1, -1)
                aux = ((dist_to_center*6)//2)

                while aux != despl_relat:
                    aux += 1
                    if -sol[1] < dist_to_center and aux < ((dist_to_center*6)//2 + dist_to_center):
                        sol = (sol[0]+1, sol[1]-1)
                    elif sol[0] < dist_to_center:
                        sol = (sol[0]+1, sol[1])
                    elif sol[1] <= 0:
                        sol = (sol[0], sol[1]+1)
                    else:
                        sol = (sol[0]-1, sol[1]+1)
            

            solutions[willy_n] = sol
            print(f"{sol[0]} {sol[1]}")
            

    except EOFError:
        break