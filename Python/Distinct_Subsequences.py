cases = int(input())

for c in range(cases):

    word = input()
    pattern = input()
    
    pd = [[0 for i in range(len(word))] for j in range(len(pattern))]

    for j in range(0, len(word)):
        pd[0][j] = int(pattern[0] == word[j])

    res = 0
    for i in range(1, len(pattern)):
        counter = 0
        for j in range(i, len(word)):

            counter += pd[i-1][j-1]

            if pattern[i] == word[j]:
                pd[i][j] = counter

                if i == len(pattern)-1:
                    res += pd[i][j]

    print(res)
