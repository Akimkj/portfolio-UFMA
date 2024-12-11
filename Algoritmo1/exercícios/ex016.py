num1 = int(input("Digite o 1º número: "))
num2 = int(input("Digite o 2º número: "))

menornum = num1
if (num2 < num1):
    menornum = num2

if (num1 != num2):
    print(menornum)