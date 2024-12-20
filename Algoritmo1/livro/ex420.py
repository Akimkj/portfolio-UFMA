velocidade = float(input("Digite a velocidade do seu carro: "))

if (velocidade <= 80):
    print("Você não foi multado!")
else:
    multa = (velocidade - 80) * 5
    print(f"Você foi MULTADO! O valor de sua multa é de R${multa}")