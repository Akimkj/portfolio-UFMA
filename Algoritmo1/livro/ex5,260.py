while True:
   number1 = int(input("Número 1: "))
   number2 = int(input("Número 2: "))
   while number1 - number2 >= 0:
      number1 -= number2
   print(number1)