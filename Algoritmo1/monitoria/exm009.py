def ehTriangulo(a: int, b: int, c: int):
    if (a < b + c) and (b < a + c) and (c < a + b):
        return True
    else: 
        return False
    
valorA = float(input("Digite o valor de A: "))
valorB = float(input("Digite o valor de B: "))
valorC = float(input("Digite o valor de C: "))

print(ehTriangulo(valorA, valorB, valorC))