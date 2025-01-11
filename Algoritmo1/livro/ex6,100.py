notas = [0, 0, 0, 0, 0, 0, 0]
soma = 0
indice = 1
for i in notas:
    notas[i] = float(input(f"Digite sua {indice}º nota: "))
    indice += 1
    soma += notas[i]

print(f"Sua média é de {soma / len(notas):.2f}")