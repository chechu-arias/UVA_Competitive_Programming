n_cases = int(input())

for case in range(n_cases):
    
    N = int(input())
    print( N*(N-1)*(N-2)*(N-3)//24 + N*(N-1)//2 + 1 )