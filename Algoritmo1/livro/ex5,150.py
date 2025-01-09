totalCompras = 0.0
while (True):
    codigoCompra = int(input("Código: "))
    if (codigoCompra == 0):
        break
    quantCompra = int(input("Quantidade: "))
    if (codigoCompra == 1):
        totalCompras += (quantCompra * 0.5)
    elif (codigoCompra == 2):
        totalCompras += (quantCompra * 1)
    elif (codigoCompra == 3):
        totalCompras += (quantCompra * 4)
    elif (codigoCompra == 5):
        totalCompras += (quantCompra * 7)
    elif (codigoCompra == 9):
        totalCompras += (quantCompra * 8)
    else:
        print("Código inválido!")
    print(f"valor: R${totalCompras:.2f}")

print(f"Total: R${totalCompras:.2f}")

     