quantKWh = float(input("Quantos kWh você usa? "))
tipoInstalacao = input("Qual o tipo da sua instalação? [r, i, c] \n")

precoPagar = 0
if (tipoInstalacao == "r"):
    if (quantKWh <= 500):
        precoPagar = quantKWh * 0.4
    else:
        precoPagar = quantKWh * 0.65
elif (tipoInstalacao == "i"):
    if (quantKWh <= 5000):
        precoPagar = quantKWh * 0.55
    else: 
        precoPagar = quantKWh * 0.60
elif (tipoInstalacao == "c"):
    if (quantKWh <= 1000):
        precoPagar = quantKWh * 0.55
    else:
        precoPagar = quantKWh * 0.60 

print(f"R$ {precoPagar}")