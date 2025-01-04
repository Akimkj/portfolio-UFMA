valor = float(input("Valor inicial: R$"))
jurosTaxa = float(input("Qual o juros? "))
valorTotal = 0
valorMensalPago = 0
jurosTotal = 0
totalMeses = 0
valorTotalPago = 0
while (valor > 0):
    jurosTotal = jurosTotal + (valor * jurosTaxa)
    valor = valor + (valor * jurosTaxa)
    print(f"O valor da dívida neste mês é de R$ {valor:.2f}")
    valorMensalPago = float(input("Quanto você vai pagar esse mês? "))
    valorTotalPago = valorTotalPago + valorMensalPago
    valor = valor - valorMensalPago
    totalMeses += 1
print(f"Total de meses: {totalMeses}")
print(f"Total pago: R${valorTotalPago:.2f}")
print(f"Total de juros pago: R${jurosTotal:.2f}")
    