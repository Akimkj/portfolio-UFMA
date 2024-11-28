num1 = int(input("Numero 1: "))
num2 = int(input("Numero 2: "))
num3 = int(input("Numero 3: "))

if (num1 > num2 and num1 > num3):
    print(num1)
elif (num2 > num3):
    print(num2)
else:
    print(num3)