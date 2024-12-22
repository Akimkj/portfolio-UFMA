num1 = int(input("Digite o primeiro número: "))
num2 = int(input("Digite o segundo número: "))
i = 0
acumulador = 0
if (num1 >= 0 and num2 >= 0):
    while (i < num2):
        acumulador += num1
        i += 1
else:
    if (num1 > num2):
        while (i > num2):
            acumulador -= num1
            i -= 1
    else:
        while (i > num1):
            acumulador -= num2
            i -= 1

print(f"O produto de {num1} e {num2} é igual a {acumulador}.")