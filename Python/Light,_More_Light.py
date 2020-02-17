while True:
    val = int(input())
    if val == 0:
        break
    else:
        sqrt = int(val**(1/2))
        if (sqrt * sqrt) == val:
            print("yes")
        else:
            print("no")