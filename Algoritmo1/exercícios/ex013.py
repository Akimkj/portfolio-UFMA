def fullhouse (d1, d2, d3, d4, d5):
    dados = [d1, d2, d3, d4, d5]
    dados.sort()

    if dados[0] == dados[1] != dados[2] == dados[3] == dados[4]:
        return True
    else:
        return False

print(fullhouse(1, 4, 4, 4, 1))