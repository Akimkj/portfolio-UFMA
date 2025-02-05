def procuraVetorEmMatriz(v, m):
    count_linhas = 0
    for i in range(len(m)):
        count_VemM = 0
        for j in range(len(m[0])):
            if m[i][j] in v:
                count_VemM += 1
            if count_VemM >= len(v):
                count_linhas += 1
                break
    return count_linhas


vetor = [1, 5, 4, 6, 7]
matriz = [
    [1, 5, 4, 6, 8, 7, 9],
    [4, 6, 8, 2, 23, 1, 7],
    [1, 5, 2, 4, 6, 9, 7]
]
print(procuraVetorEmMatriz(vetor, matriz))