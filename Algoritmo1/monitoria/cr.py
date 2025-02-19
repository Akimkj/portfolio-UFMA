notaIccp = float(input("Média introdução a computação: "))
notaAlg1 = float(input("Média Algoritmo 1: "))
notaCvga = float(input("Média Cálculo Vetorial e Geometria analítica: "))
notaEtica = float(input("Média ética e cidadania: "))

cr = ((notaIccp * 3) + (4 * notaAlg1) + (4 * notaCvga) + (4 * notaEtica)) / 15

print(f"{cr:.2f}")