def yahtzee(d1: int, d2: int, d3: int, d4: int, d5: int):
    if (d1 == d2 == d3 == d4 != d5) or (d1 == d2 == d3 == d5 != d4):
        return True
    elif (d1 == d2 == d4 == d5 != d3) or (d1 == d3 == d4 == d5 != d2):
        return True
    elif (d2 == d3 == d4 == d5 != d1):
        return True
    else:
        return False
    
valord1 = int(input("Digite o valor de D1: "))
valord2 = int(input("Digite o valor de D2: "))
valord3 = int(input("Digite o valor de D3: "))
valord4 = int(input("Digite o valor de D4: "))
valord5 = int(input("Digite o valor de D5: "))


print(yahtzee(valord1, valord2, valord3, valord4, valord5))