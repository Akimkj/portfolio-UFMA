def maiorColuna(matriz):
    
    lista = []
    num = 0
    for j in range(len(matriz[num])):
        soma = 0
        for i in range(len(matriz)):
            soma += i
        lista.append(soma)
        num +=1
    maior = max(soma)
    
    return i


    

num = [[1, 1, 30],[4,5,6],[7,8,9]]

print(maiorColuna(num))

            
