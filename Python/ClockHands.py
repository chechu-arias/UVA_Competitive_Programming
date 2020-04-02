
while True:
    
    inp = input().split(":")
    h = int(inp[0])
    m = int(inp[1])
    
    if h == 0 and m == 0:
        break
    
    if h >= 12:
        h -= 12

    h = h*5 + (m/60)*5

    ang = abs(m-h)*6

    if (360-ang) < ang:
        ang = 360 - ang

    print("%.3f" % ang)