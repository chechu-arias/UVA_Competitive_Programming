
d = 1
n = 1
fn = 1
seq = [0]*673370
seq[0] = 1
const = 2*10**9

while n <= const:
    if seq[d] == fn:
        d += 1
    n += d
    seq[fn] = n
    fn += 1

results = dict()

while True:
    
    n_in = int(input())
    if n_in == 0:
        break
    
    if results.get(n_in,[]) == []:
        for pos in range(len(seq)):
            if seq[pos] > n_in:
                break
        print(pos)
        results[n_in] = pos
    else:
        print(results[n_in])
    
    