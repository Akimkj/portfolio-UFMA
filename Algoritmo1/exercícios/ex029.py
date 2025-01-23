def temPositivosENegativos(matriz):
    QuantPositivos = 0
    QuantNegativos = 0
    for i in range(len(matriz)):
        for j in range(len(matriz[i])):
            if matriz[i][j] > 0:
                QuantPositivos += 1
            if matriz[i][j] < 0:
                QuantNegativos += 1
            if (QuantNegativos >= 1) and (QuantPositivos >= 1):
                return True
    return False


inteiros = [[2, 3, 2],[5, -6, 2],[1, 2, 2]]

print(temPositivosENegativos(inteiros))