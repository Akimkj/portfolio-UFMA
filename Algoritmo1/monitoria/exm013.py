for i in range(4, 45):
    print(i, end=": ")
    for j in range(1, i + 1):
        if (i % j == 0):
            print(j, end=" ")
    print()