def colunasComUFMA(mat):
    quantColunas = 0
    for j in range(5):
        ufmaNaLinha = 0
        for i in range(4):
            if mat[i][j] == "UFMA":
                ufmaNaLinha += 1
            if mat[i][j] == "UFMA" and ufmaNaLinha == 1:
                quantColunas += 1
    return quantColunas

matrizes = [
    ["UFMA", "oi", "olá", "mano", "cara"],
    ["UFMA", "UFMA", "olá", "velho", "oioi"],
    ["UFMA", "","", "UFMA", ""],
    ["", "", "UFMA", "", ""],
]

print(colunasComUFMA(matrizes))