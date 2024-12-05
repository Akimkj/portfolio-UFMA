def temRaizesReais(a:float, b:float, c:float):
    delta = b**2 - (4 * a * c)
    if (a != 0) and (delta >= 0):
        return True
    else:
        return False
    
valorA = float(input("Digite o valor de A: "))
valorB = float(input("Digite o valor de B: "))
valorC = float(input("Digite o valor de C: "))

print(temRaizesReais(valorA, valorB, valorC))