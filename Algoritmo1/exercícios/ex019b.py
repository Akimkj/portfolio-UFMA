def contaDigitos(nota1, nota2, nota3, nota4, nota5):
    lista = [nota1, nota2, nota3, nota4, nota5]
    cont = 0
    for i in lista:
        if (i // 10 == 8) or (i % 10 == 8):
            cont += 1
    return cont
