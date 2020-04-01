
cases = int(input())

for _ in range(cases):

    n_snowflakes = int(input())
    diff_snowflakes = set()
    positions = list()
    max_length = 0

    for i in range(n_snowflakes):

        snowflake = int(input())

        if snowflake not in diff_snowflakes:

            diff_snowflakes.add(snowflake)
            positions.append(snowflake)

        else:

            if max_length < len(diff_snowflakes):
                max_length = len(diff_snowflakes)

            ini = 0
            for i in range(len(positions)):
                if positions[i] == snowflake:
                    ini = i+1
                    break

            positions = positions[ini:]
            diff_snowflakes.clear()
            for i in range(len(positions)):
                diff_snowflakes.add(positions[i])

            diff_snowflakes.add(snowflake)
            positions.append(snowflake)
            
    if max_length < len(diff_snowflakes):
        max_length = len(diff_snowflakes)

    print(max_length)