a = float(input("Digite um número:"))
b = float(input("Digite outro número: "))
c = float(input("Digite outro número: "))
d = float(input("Digite outro número: "))

lista = [a, b, c, d]
lista.sort()
segundoMenor = lista[1]
segundoMaior = lista[2]

print(segundoMenor, segundoMaior)
