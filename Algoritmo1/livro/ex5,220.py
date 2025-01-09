while (True):
    operacao = input("MENU:\n 1. adição\n 2. subtração\n 3. multiplicação\n 4. divisão\n 5. sair\n ESCOLHA: ")
    if (operacao == "sair"):
        break
    number = int(input("Qual o número que você quer ver a tabuada? "))
    tabuada = 1
    while (tabuada <= 10):
        if (operacao == "adição"):
            print(f"{number} + {tabuada} = {number + tabuada}")
        elif (operacao == "subtração"):
            print(f"{number} - {tabuada} = {number - tabuada}")
        elif (operacao == "multiplicação"):
            print(f"{number} X {tabuada} = {number * tabuada}")
        elif (operacao == "divisão"):
            print(f"{number} / {tabuada} = {number / tabuada}")
        tabuada += 1
            