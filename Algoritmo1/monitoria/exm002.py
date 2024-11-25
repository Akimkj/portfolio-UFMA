baseMaior = float(input("Qual o tamanho da base maior em cm? "))
baseMenor = float(input("Qual o tamanho da base menor em cm? "))
altura = float(input("Qual o tamanho da altura em cm? "))

areaTrapezio = ((baseMaior + baseMenor) * altura) / 2

print(f"O tamanho da área do trapézio é de {areaTrapezio:,.2f} cm²")