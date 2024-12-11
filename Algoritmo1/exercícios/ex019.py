
def contaDigito8(nota1, nota2, nota3, nota4, nota5):
    contador = 0
    if (nota1 == 8) or (nota1 == 18) or (nota1 == 28) or (nota1 == 38) or (nota1 == 48) or (nota1 == 58) or (nota1 == 68) or (nota1 == 78) or (nota1 >= 80 and nota1 <= 89) or (nota1 == 98):
        contador += 1
    if (nota2 == 8) or (nota2 == 18) or (nota2 == 28) or (nota2 == 38) or (nota2 == 48) or (nota2 == 58) or (nota2 == 68) or (nota2 == 78) or (nota2 >= 80 and nota2 <= 89) or (nota2 == 98):
        contador += 1
    if (nota3 == 8) or (nota3 == 18) or (nota3 == 28) or (nota3 == 38) or (nota3 == 48) or (nota3 == 58) or (nota3 == 68) or (nota3 == 78) or (nota3 >= 80 and nota3 <= 89) or (nota3 == 98):
        contador += 1
    if (nota4 == 8) or (nota4 == 18) or (nota4 == 28) or (nota4 == 38) or (nota4 == 48) or (nota4 == 58) or (nota4 == 68) or (nota4 == 78) or (nota4 >= 80 and nota4 <= 89) or (nota4 == 98):
        contador += 1
    if (nota5 == 8) or (nota5 == 18) or (nota5 == 28) or (nota5 == 38) or (nota5 == 48) or (nota5 == 58) or (nota5 == 68) or (nota5 == 78) or (nota5 >= 80 and nota5 <= 89) or (nota5 == 98):
        contador += 1 # contador = contador + 1
    return contador
    
print(contaDigito8(80, 5, 18, 67, 98))


def temOito(num):
    if (num >= 80 and num <= 89):
        return 1
    if (num == 8) or (num == 18) or (num == 28) or (num == 38) or (num == 48) or (num == 58) or (num == 68) or (num == 78) or (num == 98):
        return 1
    return 0
    
def contaDigito8(nota1, nota2, nota3, nota4, nota5):
    contador = temOito(nota1) + temOito(nota2) + temOito(nota3) + temOito(nota4) + temOito(nota5)
    return contador

print(contaDigito8(40, 68, 80, 13, 88))


