def quantPares(matriz):
    quantNumPares = 0
    for i in range(len(matriz)):
        for j in range(len(matriz[i])):
            if matriz[i][j] % 2 == 0:
                quantNumPares += 1
    return quantNumPares

inteiros = [[1, 2, 3],[4, 5, 7], [1, 2, 2]]

print(quantPares(inteiros))