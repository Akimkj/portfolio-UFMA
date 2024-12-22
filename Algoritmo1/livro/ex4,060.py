km = float(input("Quantos km você quer percorrer? "))
if (km <= 200):
    valor = km * 0.5
else:
    valor = km * 0.45

print(f"Valor da passagem: R${valor}")