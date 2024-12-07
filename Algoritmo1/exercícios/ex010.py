def converter(lifeForm1, lifeForm2, lifeForm3, lifeForm4, lifeForm5):
    if (lifeForm1 == "elefante"):
        lifeForm1 = 123
    elif (lifeForm1 == "humano"):
        lifeForm1 = 234
    elif (lifeForm1 == "papagaio"):
        lifeForm1 = 345
    elif (lifeForm1 == "cachorro"):
        lifeForm1 = 456

    if (lifeForm2 == "elefante"):
        lifeForm2 = 123
    elif (lifeForm2 == "humano"):
        lifeForm2 = 234
    elif (lifeForm2 == "papagaio"):
        lifeForm2 = 345
    elif (lifeForm2 == "cachorro"):
        lifeForm2 = 456

    if (lifeForm3 == "elefante"):
        lifeForm3 = 123
    elif (lifeForm3 == "humano"):
        lifeForm3 = 234
    elif (lifeForm3 == "papagaio"):
        lifeForm3 = 345
    elif (lifeForm3 == "cachorro"):
        lifeForm3 = 456

    if (lifeForm4 == "elefante"):
        lifeForm4 = 123
    elif (lifeForm4 == "humano"):
        lifeForm4 = 234
    elif (lifeForm4 == "papagaio"):
        lifeForm4 = 345
    elif (lifeForm4 == "cachorro"):
        lifeForm4 = 456

    if (lifeForm5 == "elefante"):
        lifeForm5 = 123
    elif (lifeForm5 == "humano"):
        lifeForm5 = 234
    elif (lifeForm5 == "papagaio"):
        lifeForm5 = 345
    elif (lifeForm5 == "cachorro"):
        lifeForm5 = 456

    return lifeForm1, lifeForm2, lifeForm3, lifeForm4, lifeForm5
def scannerAnimais(vida1, vida2, vida3, vida4, vida5):
    quantAnimais = 0
    if (vida1 == 123) or (vida1 == 234) or (vida1 == 345) or (vida1 == 456):
        quantAnimais += 1
    if (vida2 == 123) or (vida2 == 234) or (vida2 == 345) or (vida2 == 456):
        quantAnimais += 1
    if (vida3 == 123) or (vida3 == 234) or (vida3 == 345) or (vida3 == 456):
        quantAnimais += 1
    if (vida4 == 123) or (vida4 == 234) or (vida4 == 345) or (vida4 == 456):
        quantAnimais += 1
    if (vida5 == 123) or (vida5 == 234) or (vida5 == 345) or (vida5 == 456):
        quantAnimais += 1
    
    return quantAnimais

life1 = input("Digite uma forma de vida de wakanda: ")
life2 = input("Digite uma forma de vida de wakanda: ")
life3 = input("Digite uma forma de vida de wakanda: ")
life4 = input("Digite uma forma de vida de wakanda: ")
life5 = input("Digite uma forma de vida de wakanda: ")

life1, life2, life3, life4, life5 = converter(life1, life2, life3, life4, life5)

print(f"A quantidade de animais scanneados é igual a {scannerAnimais(life1, life2, life3, life4, life5)}")
