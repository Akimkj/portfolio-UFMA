quantMetaisLata1 = int(input("Quantos metais tem na lata 1? "))
quantMetaisLata2 = int(input("Quantos metais tem na lata 2? "))
quantVidrosLata1 = int(input("Quantos vidros tem na lata 1? "))
quantVidrosLata2 = int(input("Quantos vidros tem na lata 2? "))

quantMinMovimento = 0

if (quantMetaisLata1 >= quantMetaisLata2): 
      quantMetaisLata1 += quantMetaisLata2
      quantMinMovimento += quantMetaisLata2
      quantMetaisLata2 = 0
else:
      quantMetaisLata2 += quantMetaisLata1
      quantMinMovimento = quantMetaisLata1
      quantMetaisLata1 = 0

if (quantVidrosLata1 >= quantVidrosLata2): 
      quantVidrosLata1 += quantVidrosLata2
      quantMinMovimento += quantVidrosLata2
      quantVidrosLata2 = 0
else:
      quantVidrosLata2 += quantVidrosLata1
      quantMinMovimento += quantVidrosLata1
      quantVidrosLata1 = 0

print(quantMinMovimento)

