def notaReposicao(nota1, nota2, nota3):
    media = (nota1 + nota2 + nota3) / 3
    if (media >= 70):
        return 0
    elif (media < 70):
        menorNota = nota1
        if (nota2 < nota1) and (nota2 < nota3):
            menorNota = nota2
        if (nota3 < nota1) and (nota3 < nota2):
            menorNota = nota3
        
        restanteNota = 210 - (nota1 + nota2 + nota3)

        return restanteNota + menorNota

prova1 = float(input("Digite a nota da sua primeira prova: "))
prova2 = float(input("Digite a nota da sua segunda prova: "))
prova3 = float(input("Digite a nota da sua terceira prova: "))

if (notaReposicao(prova1, prova2, prova3) == 0):
    print("Você não precisa fazer reposição.")
else:
    print(f"Você precisa tirar {notaReposicao(prova1, prova2, prova3)} pontos na reposição!")