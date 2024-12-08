def ataque(atq1, atq2, atq3, def1, def2, def3):
    atqs = [atq1, atq2, atq3]
    defs = [def1, def2, def3]
    maiorAtq = max(atqs)
    menorAtq = min(atqs)
    maiorDef = max(defs)
    menorDef = min(defs)
    meioAtq = (atq1 + atq2 + atq3) - (maiorAtq + menorAtq)
    meioDef = (def1 + def2 + def3) - (maiorDef + menorDef)
    quantAtq = 0

    if (maiorAtq > maiorDef):
        quantAtq += 1
    if (meioAtq > meioDef):
        quantAtq += 1
    if (menorAtq > menorDef):
        quantAtq += 1
    
    return quantAtq

ataque1 = int(input("Digite a jogada de ataque: "))
ataque2 = int(input("Digite a jogada de ataque: "))
ataque3 =  int(input("Digite a jogada de ataque: "))
print("=" * 25)
defesa1 = int(input("Digite a jogada de defesa: "))
defesa2 = int(input("Digite a jogada de defesa: "))
defesa3 =  int(input("Digite a jogada de defesa: "))

print(f"A quantidade de ataques foi igual a {ataque(ataque1, ataque2, ataque3, defesa1, defesa2, defesa3)}.")