def criarMatriz():
    mat = []
    indiceMat = 0
    num = 1
    
    for i in range (5):
        mat.append([])
        for j in range(4):
            mat[indiceMat].append(num)
            num += 2
        indiceMat += 1
    
    return mat

print(criarMatriz())
    

