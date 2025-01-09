quantNumber = 0
somaNumbers = 0
number = int(input("Digite um número: "))

while (number != 0):
    quantNumber += 1
    somaNumbers += number
    number = int(input("Digite um número:"))

print(f"Quantidade: {quantNumber}")
print(f"Soma: {somaNumbers}")
print(f"Média: {somaNumbers/quantNumber:.2f}")