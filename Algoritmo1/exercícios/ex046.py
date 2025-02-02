def fatorial_inteiro(num):
    fatorial = 1        
    for i in range(1, num + 1):
        fatorial *= i
    return fatorial

print(fatorial_inteiro(5))