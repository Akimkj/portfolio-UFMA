def palavraCerta(palavra):
    if (palavra != "mano") or (palavra != "velho") or (palavra != "aura") or (palavra != "nice"):
        return False
    else:
        return True
    
def sucesso(s1, s2, s3):
    contador = 0
    if palavraCerta(s1) and palavraCerta(s2)  and palavraCerta(s3):
        return 0
    if (s1 == s2 == s3):
        contador += 1
        return contador
    if (s1 != s2) or (s1 != s3):
        contador += 2
    if (s2 != s3):
        contador += 1
    return contador

palavra1 = input("Digite: ")
palavra2 = input("Digite: ")
palavra3 = input("Digite: ")

print(f"A quantidade de sucesso é igual a {sucesso(palavra1, palavra2, palavra3)}")