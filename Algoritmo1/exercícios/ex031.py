def menorMaior(matriz):
    menor = matriz[0][0]
    maior = matriz[0][0]
    for i in range(len(matriz)):
        for j in range(len(matriz[i])):
            if matriz[i][j] > maior:
                maior = matriz[i][j]
            if matriz[i][j] < menor:
                menor = matriz[i][j]
    return (menor, maior)

inteiros = [[6, 7, -4],[4, 2, 1]]
menorValor, maiorValor = menorMaior(inteiros)
print(menorValor)
print(maiorValor)