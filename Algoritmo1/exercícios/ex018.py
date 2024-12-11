def qualEhPar(n1, n2, n3, n4):
    if (n1 % 2 == 0):
        return n1
    if (n2 % 2 == 0):
        return n2
    if (n3 % 2 == 0):
        return n3
    if (n4 % 2 == 0):
        return n4

num1 = int(input("Digite um número: "))
num2 = int(input("Digite um número: "))
num3 = int(input("Digite um número: "))
num4 = int(input("Digite um número: "))

print(qualEhPar(num1, num2, num3, num4))
