capital = float(input("Qual o valor do capital a ser investido? "))
time = int(input("Por quantos meses esse valor será investido? "))
taxa = 30/100
montante = capital * ((1 + taxa)**time)

jurosCompostos = montante - capital

