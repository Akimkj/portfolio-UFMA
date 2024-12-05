quantMetaisLata1 = int(input("Quantos metais tem na lata 1? "))
quantMetaisLata2 = int(input("Quantos metais tem na lata 2? "))
quantVidrosLata1 = int(input("Quantos vidros tem na lata 1? "))
quantVidrosLata2 = int(input("Quantos vidros tem na lata 2? "))

def orgLixo(metais1, metais2, vidros1, vidros2):
      if (metais1 + vidros1 < metais2 + vidros2):
            return metais1, vidros1
      else:
            return metais2, vidros2
      
print(orgLixo(quantMetaisLata1, quantMetaisLata2, quantVidrosLata1, quantVidrosLata2))

