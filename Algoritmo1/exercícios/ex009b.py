def ataque(atq1, atq2, atq3, def1, def2, def3):

    #maior atq e def
    maiorAtq = atq1
    if atq2 > atq1 and atq2 > atq3:
        maiorAtq = atq2
    if atq3 > atq1 and atq3 > atq2:
        maiorAtq = atq3 

    maiorDef = def1
    if def2 > def1 and def2 > def3:
        maiorDef = def2
    if def3 > def1 and def3 > def2:
        maiorDef = def3

    #menor atq e def
    menorAtq = atq1
    if atq2 < atq1 and atq2 < atq3:
        menorAtq = atq2
    if atq3 < atq1 and atq3 < atq2:
        menorAtq = atq3

    menorDef = def1
    if def2 < def1 and def2 < def3:
        menorDef = def2
    if def3 < def1 and def3 < def2:
        menorDef = def3
    
    #meio atq e def
    meioAtq = atq1
    if atq2 > menorAtq and atq2 < maiorAtq:
        meioAtq = atq2
    if atq3 > menorAtq and atq3 < maiorAtq:
        meioAtq = atq3

    meioDef = def1
    if def2 > menorDef and def2 < maiorAtq:
        meioDef = def2
    if def3 > menorDef and def3 < maiorAtq:
        meioDef = def3

    quantAtaques = 0
    if maiorAtq > maiorDef:
        quantAtaques = quantAtaques + 1
    if menorAtq > menorDef:
        quantAtaques = quantAtaques + 1
    if meioAtq > meioDef:
        quantAtaques = quantAtaques + 1
    
    return quantAtaques
'''
*oposição*
> ---> <=
< ---> >=
>= ---> <
<= ---> >
== ---> !=
'''
ataque1 = int(input("Digite a jogada de ataque: "))
ataque2 = int(input("Digite a jogada de ataque: "))
ataque3 = int(input("Digite a jogada de ataque: "))
print("=" * 25)
defesa1 = int(input("Digite a jogada de defesa: "))
defesa2 = int(input("Digite a jogada de defesa: "))
defesa3 =  int(input("Digite a jogada de defesa: "))

print(f"A quantidade de ataques foi igual a {ataque(ataque1, ataque2, ataque3, defesa1, defesa2, defesa3)}.")