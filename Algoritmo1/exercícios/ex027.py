def vales(vetor):
    contador = 0
    for i in range(1, len(vetor)):
        if vetor[i] >= vetor[i - 1]:
            continue
        else:
            if vetor[i] >= vetor[i + 1]:
                continue
            else:
                contador += 1
        
    return contador

relevo = [1, 2, 3, -3, -9, 4, 19, 7, 45]
print(vales(relevo))