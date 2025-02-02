def eh_palindromo(string: str) -> bool:
    left = 0
    right = len(string) - 1
    palindromoTeste1 = []
    for i in range(len(string)):
        palindromoTeste1.append(string[i])
    palindromoTeste2 = []
    for i in range(len(string)):
        palindromoTeste2.append(string[i])
    while left < right:
        palindromoTeste2[left], palindromoTeste2[right] = palindromoTeste2[right], palindromoTeste2[left]
        left += 1
        right -= 1
    
    if palindromoTeste1 == palindromoTeste2:
        return True
    return False
print(eh_palindromo("arere"))