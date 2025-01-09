def ehprimo(number):
    if (number == 0 or number == 1):
        return False
    contador = 0
    for i in range(2, number, 1):
        if (number % i == 0): 
            contador += 1
    if (contador > 0):
        return False
    else:
        return True
    


while True:
    digito = int(input("Digite um número: "))
    if (ehprimo(digito) == True):
        print("Eh primo")
    else:
        print("Não eh primo")

