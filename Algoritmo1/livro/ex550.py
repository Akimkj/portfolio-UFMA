fim = int(input("Digite o final da contagem: "))
i = 0
count = 0
while (i <= fim):
    if (i != 0):
        print(i)
        count += 1
    if (count == 10):
        break
    i += 3