num1 = int(input("Digite o 1º número: "))
num2 = int(input("Digite o 2º número: "))
num3 = int(input("Digite o 3º número: "))
num4 = int(input("Digite o 4º número: "))
menorNum = min(num1, num2, num3, num4)

maiorNum = max(num1, num2, num3, num4)

somaMaiorMenor = maiorNum + menorNum
restante = (num1 + num2 + num3 + num4) - (somaMaiorMenor)

if(somaMaiorMenor > restante):
    print("Maior")
elif(somaMaiorMenor == restante):
    print("Igual")
else:
    print("Menor")