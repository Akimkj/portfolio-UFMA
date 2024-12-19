quantCigarrospDia = int(input("Cigarros por dia: "))
quantAnos = int(input("Quantidades de anos fumando: "))
minutosPerdidos = (quantCigarrospDia * 10) * 365 * quantAnos
diasPerdidos = minutosPerdidos // 1440

print(f"Dias perdidos: {diasPerdidos}")