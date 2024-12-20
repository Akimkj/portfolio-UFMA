a = int(input("Número: "))
b = int(input("Número: "))
c = int(input("Número: "))

maiorNum = a
if b > a and b > c:
    maiorNum = b
if c > a and c > b:
    maiorNum = c

menorNum = a 
if b < a and b < c:
    menorNum = b
if c < a and c < b:
    menorNum = c

print(maiorNum, menorNum)