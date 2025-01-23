def quantVemM(M, V):
    lista = []
    for elemento in V:
        for i in range(len(M)):
            for j in range(len(M[i])):
                if elemento == M[i][j] and M[i][j] not in lista:
                    lista.append(M[i][j])
    return len(lista)

vetor = ["a", "b"]
matriz = [["i", "b", "x"], ["e", "a", "b"]]

print(quantVemM(matriz, vetor))