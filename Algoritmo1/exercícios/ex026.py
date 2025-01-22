import random
def bingo(cartela, sorteados):
    contador = 0
    for i in cartela:
        if i in sorteados:
            contador += 1
    return contador

listaCartela = []
listaSorteados = []

for i in range(6):
    listaCartela.append(random.randint(1, 60))
    listaSorteados.append(random.randint(1,60))

print(listaCartela)
print(listaSorteados)
print(bingo(listaCartela, listaSorteados))