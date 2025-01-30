def intersecaoMatrizes(mat1, mat2):
    resultados = []
    for i in range(len(mat1)):
        for j in range(len(mat1[0])):
            if mat1[i][j] in mat2:
                resultados.append(mat1[i][j])
    return resultados

matriz1 = [[1, 3, 4, 5], [7, 8, 9, 11], [12, 14, 16, 18], [24, 25, 46, 78]]
matriz2 = [[1, 2, 5, 6], [7, 9, 10, 11], [13, 15, 16, 19], [24, 27, 45, 79]]

print(intersecaoMatrizes(matriz1, matriz2))