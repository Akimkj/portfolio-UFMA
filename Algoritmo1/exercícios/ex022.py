nota1 = int(input("Nota: "))
nota2 = int(input("Nota: "))
nota3 = int(input("Nota: "))
nota4 = int(input("Nota: "))
nota5 = int(input("Nota: "))

listaNotas = [nota1, nota2, nota3, nota4, nota5]
listaNotas.sort()

media = (listaNotas[1] + listaNotas[2] + listaNotas[3]) / 3

print(media)
