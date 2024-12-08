num1 = int(input("Digite o 1º número: "))
num2 = int(input("Digite o 2º número: "))
num3 = int(input("Digite o 3º número: "))
num4 = int(input("Digite o 4º número: "))
menorNum = num1
if (num2 < num1) and (num2 < num3) and (num2 < num4):
    menorNum = num2
elif (num3 < num1) and (num3 < num2) and (num3 < num4):
    menorNum = num3
elif (num4 < num1) and (num4 < num2) and (num4 < num3):
    menorNum = num4

maiorNum = num2
if (num1 > num2) and (num1 > num3) and (num1 > num4):
    maiorNum = num1
elif (num3 > num1) and (num3 > num2) and (num3 > num4):
    maiorNum = num3
elif (num4 > num1) and (num4 > num2) and (num4 > num3):
    maiorNum = num4

somaMaiorMenor = maiorNum + menorNum
restante = (num1 + num2 + num3 + num4) - (somaMaiorMenor)

if(somaMaiorMenor > restante):
    print("Maior")
elif(somaMaiorMenor == restante):
    print("Igual")
else:
    print("Menor")