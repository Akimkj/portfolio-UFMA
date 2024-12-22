i = int(input("Digite o início da tabela: "))
fim = int(input("Digite o final da tabela: "))
while (i < 1 or i > 10) or (fim < 1 or fim > 10):
    print("Desculpe, Mas o início e o final da tabela precisa ser de números entre 0 e 10")
    i = int(input("Digite o início da tabela: "))
    fim = int(input("Digite o final da tabela: "))

while (i <= fim):
    print(f"2 X {i} = {2 * i}")
    i += 1