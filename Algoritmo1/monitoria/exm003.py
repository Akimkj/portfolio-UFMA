capital = float(input("Qual o valor do capital a ser investido? "))
time = int(input("Por quantos meses esse valor será investido? "))
taxa = float(input("Qual a quantidade da taxa (em decimal)? "))
montante = capital * (1 + taxa)**time

jurosCompostos = montante - capital

print(f"O valor total de juros é de R${jurosCompostos:,.2f}")