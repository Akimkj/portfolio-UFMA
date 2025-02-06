#POO - Programação orientada a objetos
'''
- É um modo diferente de programar, sendo algo característico de linguagens de alto nível (Python, C#, Java etc.)
- Permite uma melhor reutilização de código, ou seja, menos linhas
- Representa melhor o mundo real
'''
#Características de POO
'''
- Objetos: São instâncias de classes, que determinam qual informação
um objeto contém e como ele pode manipulá-la.
- Classe: é uma descrição de um conjunto de objetos que
compartilham os mesmos atributos, operações, relacionamentos e
semântica.
- Atributos: São variáveis que pertencem a um objeto. Os dados de
um objeto são armazenados nos seus atributos. Também pode ser interpretados comos as caracteristicas em comum presente em uma classe.
- Métodos: são procedimentos ou funções que realizam as ações
próprias do objeto. Assim, os métodos são as ações que o objeto
pode realizar.
'''
class Cachorros:
    #Esse é o método construtor, uma função que permite criar diferentes objetos. O primeiro paramêtro de todos os métodos sempre é self, para indicar que estamos mexendo com funções dentro de uma classe.
    def __init__(self, nome, cor_pelo, idade, tamanho):
        self.nome = nome # atributo
        self.cor_pelo = cor_pelo # atributo
        self.idade = idade # atributo
        self.tamanho = tamanho # atributo
    
    def latir(self): # método latir
        print("Au Au")
    def correr(self): # método correr
        print(f"{self.nome} está correndo !")
cachorro1 = Cachorros("Akim", "Preto", 4, "grande") #instanciando um objeto

print(cachorro1.nome)
print(cachorro1.idade)
cachorro1.idade = 6
print(cachorro1.idade)
cachorro1.latir()
cachorro1.correr()