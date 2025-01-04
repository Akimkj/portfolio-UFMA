deposito= float(input("Digite o valor inicial: "))
juros = float(input("Taxa de juros: "))
i = 1
while (i <= 24):
    deposito = deposito + (juros * deposito)
    print(f"valor: R$ {deposito:.2f}")
    i += 1
print(f"Valor final: R$ {deposito:.2f}")