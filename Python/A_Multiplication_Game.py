
while True:
    try:
        
        n = int(input())

        if n == 1:
            print("Ollie wins.")
            continue

        p = 1
        while True:
            p *= 9
            if p >= n:
                print("Stan wins.")
                break
            
            p *= 2
            if p >= n:
                print("Ollie wins.")
                break

    except EOFError:
        break