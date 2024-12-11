def contaDigitos8(nota1: int, nota2: int, nota3: int, nota4: int, nota5: int):
    contador = 0
    if nota1 % 10 == 8 or nota1 // 10 == 8:
        contador += 1
    if nota2 % 10 == 8 or nota2 // 10 == 8:
        contador += 1
    if nota3 % 10 == 8 or nota3 // 10 == 8:
        contador += 1
    if nota4 % 10 == 8 or nota4 // 10 == 8:
        contador += 1
    if nota5 % 10 == 8 or nota5 // 10 == 8:
        contador += 1
    return contador

nota1 = int(input("Digite a nota do primeiro aluno: "))
nota2 = int(input("Digite a nota do segundo aluno: "))
nota3 = int(input("Digite a nota do terceiro aluno: "))
nota4 = int(input("Digite a nota do quarto aluno: "))
nota5 = int(input("Digite a nota do quinto aluno: "))
print(contaDigitos8(nota1, nota2, nota3, nota4 ,nota5))