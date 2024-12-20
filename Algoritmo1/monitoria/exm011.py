contador = 0
for i in range(10):
    number = int(input("Digite o número: "))
    if (number < 0):
        contador += 1

print(contador)