def bactracking(k, filled, board, min_r, min_c):

    def putBishop(row_p, col_p, option):
        if option == 0:
            board[row_p][col_p] = -1
        else:
            board[row_p][col_p] = 0
        
        size = len(board)-1

        aux_r, aux_c = row_p-1, col_p-1
        while aux_r >= 0 and aux_c >= 0:
            if option == 0:
                board[aux_r][aux_c] += 1
            else:
                board[aux_r][aux_c] -= 1
            aux_r -= 1
            aux_c -= 1
        
        aux_r, aux_c = row_p+1, col_p+1
        while aux_r <= size and aux_c <= size:
            if option == 0:
                board[aux_r][aux_c] += 1
            else:
                board[aux_r][aux_c] -= 1
            aux_r += 1
            aux_c += 1
        
        aux_r, aux_c = row_p-1, col_p+1
        while aux_r >= 0 and aux_c <= size:
            if option == 0:
                board[aux_r][aux_c] += 1
            else:
                board[aux_r][aux_c] -= 1
            aux_r -= 1
            aux_c += 1
        
        aux_r, aux_c = row_p+1, col_p-1
        while aux_r <= size and aux_c >= 0:
            if option == 0:
                board[aux_r][aux_c] += 1
            else:
                board[aux_r][aux_c] -= 1
            aux_r += 1
            aux_c -= 1
            
    def plausiblePos(row_p, col_p):

        possible = True
        size = len(board)-1

        aux_r, aux_c = row_p, col_p
        while aux_r >= 0 and aux_c >= 0:
            if board[aux_r][aux_c] == -1:
                possible = False
                break
            aux_r -= 1
            aux_c -= 1
        
        aux_r, aux_c = row_p, col_p
        while possible and aux_r <= size and aux_c <= size:
            if board[aux_r][aux_c] == -1:
                possible = False
                break
            aux_r += 1
            aux_c += 1
        
        aux_r, aux_c = row_p, col_p
        while possible and aux_r >= 0 and aux_c <= size:
            if board[aux_r][aux_c] == -1:
                possible = False
                break
            aux_r -= 1
            aux_c += 1
        
        aux_r, aux_c = row_p, col_p
        while possible and aux_r <= size and aux_c >= 0:
            if board[aux_r][aux_c] == -1:
                possible = False
                break
            aux_r += 1
            aux_c -= 1

        return possible


    #print(k, filled)
    if k == filled:
        #print(board)
        yield 1
    
    for row_p in range(min_r, len(board)):
        if row_p == min_r:
            min_c_used = min_c
        else:
            min_c_used = 0
        for col_p in range(min_c_used, len(board[row_p])):
            if board[row_p][col_p] == 0 and filled <= k:
                putBishop(row_p, col_p, 0)
                filled += 1
                yield from bactracking(k, filled, board, row_p, col_p)
                putBishop(row_p, col_p, 1)
                filled -= 1
    


out = open("861v2out.txt", "w")
out.write("{")

for n in range(1,9):
    for k in range(0,n**2+1):
        if k == 0:
            cont = 1
        elif k == 1:
            cont = n*n
        else:
            board = [[0 for x in range(n)] for y in range(n)]
            cont = 0
            for posib in bactracking(k, 0, board, 0, 0):
                cont += 1
        print(cont)
        if cont == 0:
            break
        out.write("\t({0}, {1}) : {2},\n".format(n,k,cont))

out.write("}")
out.close()
