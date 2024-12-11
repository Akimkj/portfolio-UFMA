baseMenor = int(input("Tamanho da base menor: "))
baseMaior = int(input("Tamanho da base Maior: "))
altura = int(input("Tamanho da altura: "))

if (baseMenor == baseMaior == altura):
    print("É um quadrado")
elif(baseMenor == baseMaior) and (baseMaior != altura):
    print("É um retângulo")
else:
    print("É um trapézio")
