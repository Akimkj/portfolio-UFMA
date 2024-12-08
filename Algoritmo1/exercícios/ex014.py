def sumCount(value, d1, d2, d3, d4, d5):
    somaOcorrencia = 0
    if (value == d1):
        somaOcorrencia += d1
    if (value == d2):
        somaOcorrencia += d2
    if (value == d3):
        somaOcorrencia += d3
    if (value == d4):
        somaOcorrencia += d4
    if (value == d5):
        somaOcorrencia += d5
    return somaOcorrencia

print(sumCount(6, 3, 6, 6, 2, 6))