def eh_quadrado_magico(matriz):
    listaLinhas = []
    listaColunas = []
    # analisa linhas
    for i in range(len(matriz)):
        somador = 0
        for j in range(len(matriz[0])):
            somador += matriz[i][j]
        listaLinhas.append(somador)
    
    for i in range(1, len(listaLinhas)):
        if listaLinhas[i] != listaLinhas[i - 1]:
            return False
        
    # analisa colunas
    for j in range(len(matriz[0])):
        somador = 0
        for i in range(len(matriz)):
            somador += matriz[i][j]
        listaColunas.append(somador)
    
    for i in range(1, len(listaColunas)):
        if listaColunas[i] != listaColunas[i - 1]:
            return False
    '''
    somaDiagonalP = 0
    somaDiagonalS = 0  
    # analisa diagonais
    for i in range(len(matriz)):
        for j in range(len(matriz[0])):
            if i == j:
                somaDiagonalP += matriz[i][j]
    '''
    return True

mat = [
    [1, 2],
    [2, 1]
]

print(eh_quadrado_magico(mat))


    

