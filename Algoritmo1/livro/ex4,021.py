salário = float(input("Di.gi.te o salári.o para cálculo do ü1posto: ")) 
base = salário 
imposto = 0 
if base> 3000: 
    imposto = imposto + ((base - 3000) * 0.35)
    base = 3000  
if base > 1000:  
    imposto = imposto + ((base - 1000) * 0.20) 
print(f"Salário: R${salário:6.2f} Imposto a pagar: R${imposto:6.2f}") 