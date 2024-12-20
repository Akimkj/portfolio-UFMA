valorCasa = float(input("Qual o preço da casa? "))
salario = float(input("Qual o seu salário? "))
quantAnos = int(input("Em quantos anos você pretende comprar? "))

prestacaoMensal = valorCasa / (quantAnos * 12)

if (prestacaoMensal <= (30/100 * salario)):
    print("Emprestimo aprovado!")
else:
    print("Emprestimo recusado!")
