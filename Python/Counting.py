vals = [1,2,5]
for i in range(3,1001):
    vals.append(2*vals[-1] + vals[-2] + vals[-3])

while True:
    try:
        val = int(input())
        print(vals[val])
    except EOFError:
        break
