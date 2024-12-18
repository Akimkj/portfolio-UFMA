precoMercadoria = float(input("Qual o valor do produto? R$"))
percentoDesconto = int(input("Qual o percentual de desconto? "))

desconto = precoMercadoria * percentoDesconto/100
precoMercadoria = precoMercadoria - desconto

print(f"desconto: R${desconto}")
print(f"Novo preço: R${precoMercadoria}")