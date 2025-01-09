valor = float(input(" Digite o valor a pagar: ")) 
cédulas = 0
moedas = 0 
atual = 100.0
atual2 = 0.5
apagar= valor
while (True): 
    if atual <= apagar:
        apagar -= atual 
        cédulas += 1
    else: 
        print(f"{cédulas} cédula (s) de R${atual}") 
        if apagar == 0:
            break
        if atual == 100:
            atual = 50
        elif atual == 50: 
            atual = 20 
        elif atual == 20: 
            atual = 10 
        elif atual == 10: 
            atual = 5 
        elif atual == 5: 
            atual  = 1
        cédulas= 0

    if atual2 <= apagar:
        apagar -= atual2
        moedas += 1
    else:
        print(f"{moedas} moeda (s) de R${atual2}")
        if apagar == 0:
            break
        if atual2 == 0.5:
            atual2 = 0.10
        elif atual2 == 0.10:
            atual2 = 0.05
        elif atual2 == 0.05:
            atual2 = 0.02
        elif atual2 == 0.02:
            atual2 = 0.01
        moedas = 0