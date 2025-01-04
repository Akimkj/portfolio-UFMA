deposito = float(input("Qual o seu depósito inicial? R$"))
juros = float(input("Qual a taxa de juros mensal? "))
i = 1
depositoMensal = 0
while (i <= 24):
    depositoMensal = float(input(f"Quanto você vai depositar no {i}º mês? R$"))
    deposito = (depositoMensal + deposito) + ((deposito + depositoMensal) * juros)
    print(f"Valor do {i}º mês: R${deposito:.2f}")
    i += 1
print(f"Valor Final: R${deposito:.2f}")
