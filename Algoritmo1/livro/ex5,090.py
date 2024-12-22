# O código abaixo só dá erro quando o num1 é um valor negativo com com parte númerica menor que o num2 (positivo).

num1 = int(input("Digite um número: "))
num2 = int(input("Digite um número: "))
acumulador = 0
resto = 0
if (num2 == 0): # Análise de complexidade matemática
    print("Deu erro! Não é possível dividir um número por 0")
else: # Caso não tenha complexidade matemática
    if (num1 != 0): # Para operações não nulas
        if (num1 > 0 and num2 > 0): # Para operações entre dois números positivos
            if (num2 > num1):
                resto = num2
            else:
                while (num1 != 0):
                    num1 -= num2
                    acumulador += 1
                    if (num1 - num2 < 0):
                        resto = num1
                        break
        else: # Para operações com números negativos
            if (num1 > 0 and num2 < 0) or (num1 < 0 and num2 > 0): # Para operações entre um positivo e um negativo
                if (num1 >= num2):
                    while (num1 != 0):
                        num1 += num2
                        acumulador -= 1
                        if (num1 + num2 < 0):
                            resto = num1
                            break
                else:
                    while (num1 != 0):
                        num1 += num2
                        acumulador -= 1
                        if (num1 + num2 > 0):
                            resto = num1
                            break
            else: # Para operações entre dois negativos
                if (num2 < num1):
                    resto = num1
                while (num1 != 0):
                    if (num1 - num2 > 0):
                        resto = num1
                        break
                    num1 -= num2
                    acumulador += 1

    print(f"O resultado da divisão inteira é igual a {acumulador} e o resto dela é igual a {resto}.")   