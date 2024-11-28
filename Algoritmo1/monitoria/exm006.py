def ehmaior(n1: float, n2: float, n3: float):
    if (n1 > n2 and n1 > n2):
        return n1
    elif (n2 > n3):
        return n2
    else:
        return n3

numero1 = float(input("Digite o 1º número: "))
numero2 = float(input("Digite o 2º número: "))
numero3 = float(input("Digite o 3º número: "))

print(ehmaior(numero1, numero2, numero3))