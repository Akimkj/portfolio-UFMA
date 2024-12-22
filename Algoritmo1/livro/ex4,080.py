num1 = int(input("Digite número 1: "))
num2 = int(input("Digite número 2: "))
operacao = input("Qual operação? [soma, subtração, multiplicação, divisão] ")
if (operacao == "soma"):
    print(num1 + num2)
elif (operacao == "subtração"):
    print(num1 - num2)
elif (operacao == "multiplicação"):
    print(num1 * num2)
elif (operacao == "divisão"):
    print(num1 / num2)