salario = float(input("Seu salário: "))
aumento = 0
if (salario > 1250):
    aumento = 10/100 * salario
else:
    aumento = 15/100 * salario

print(f"Aumento: R${aumento}")