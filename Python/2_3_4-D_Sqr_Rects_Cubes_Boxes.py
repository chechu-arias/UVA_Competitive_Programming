while True:

    try:
        
        N = int(input())

        aux = N*(N+1)//2

        N_r2 = aux*aux
        N_r3 = N_r2*aux
        N_r4 = N_r3*aux

        N_s2 = 0
        N_s3 = 0
        N_s4 = 0
        for i in range(1, N+1):
            N_s2 += i*i
            N_s3 += i*i*i
            N_s4 += i*i*i*i

        N_r2 -= N_s2
        N_r3 -= N_s3
        N_r4 -= N_s4
        
        print(N_s2, N_r2, N_s3, N_r3, N_s4, N_r4)

    except EOFError:
        break
