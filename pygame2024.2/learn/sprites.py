# Sprites - são objetos/imagens que se movem pela tela
# Para animar uma sprite, é necessária uma sequencia de imagens que se alteram rapidamente, com o objetivo de causar a sensação de movimento
import pygame
from pygame.locals import *
from sys import exit

pygame.init()

largura_tela = 990
altura_tela = 555
tela = pygame.display.set_mode((largura_tela, altura_tela))
pygame.display.set_caption("Sprites")
relogio = pygame.time.Clock()

#cria uma classe chamada Sapo que herda atributos e métodos de uma classe já pronta no pygame
class Sapo(pygame.sprite.Sprite):
    def __init__(Self):
       super().__init__() #herdar caracteristicas da SpriteClass
       Self.sprites = [] #lista para armazenar todas as sprites do mesmo personagem
       Self.sprites.append(pygame.image.load("pygame2024.2\\learn\\stylePrototipo\\sapo\\attack_1.png"))
       Self.sprites.append(pygame.image.load("pygame2024.2\\learn\\stylePrototipo\\sapo\\attack_2.png"))
       Self.sprites.append(pygame.image.load("pygame2024.2\\learn\\stylePrototipo\\sapo\\attack_3.png"))
       Self.sprites.append(pygame.image.load("pygame2024.2\\learn\\stylePrototipo\\sapo\\attack_4.png"))
       Self.sprites.append(pygame.image.load("pygame2024.2\\learn\\stylePrototipo\\sapo\\attack_5.png"))
       Self.sprites.append(pygame.image.load("pygame2024.2\\learn\\stylePrototipo\\sapo\\attack_6.png"))
       Self.sprites.append(pygame.image.load("pygame2024.2\\learn\\stylePrototipo\\sapo\\attack_7.png"))
       Self.sprites.append(pygame.image.load("pygame2024.2\\learn\\stylePrototipo\\sapo\\attack_8.png"))
       Self.sprites.append(pygame.image.load("pygame2024.2\\learn\\stylePrototipo\\sapo\\attack_9.png"))
       Self.sprites.append(pygame.image.load("pygame2024.2\\learn\\stylePrototipo\\sapo\\attack_10.png"))
       Self.atual = 0 #indice da lista com as sprites
       Self.image = Self.sprites[Self.atual] #atributo herdado para mostrar a moviementação da sprite.
       Self.image = pygame.transform.scale(Self.image, (128 *3, 64 *3)) #aumenta ou diminui a escala a sprite
       Self.rect = Self.image.get_rect() #trata a sprite como um retangulo
       Self.rect.topleft = 250, 300 #posiciona o objeto na tela // x, y

       Self.animar = False #atributo que diz quando a sprite vai animar ou não
    
    def atacar(Self): #método que controla o atributo de animação
        Self.animar = True

    def update(Self): #método herdado da SpriteClass
        if Self.animar == True:
            Self.atual += 0.3 # esse valor controla a velocidade da animação
            if Self.atual >= len(Self.sprites):
                Self.atual = 0
                Self.animar = False
            Self.image = Self.sprites[int(Self.atual)] # a função int() é para arredondar o indice para inteiro, e evitar erro no meu código
            Self.image = pygame.transform.scale(Self.image, (128 *3, 64 *3))

#Imagem de fundo
imagem_fundo = pygame.image.load("pygame2024.2\\learn\\stylePrototipo\\pantano.jpg").convert()
imagem_fundo = pygame.transform.scale(imagem_fundo, (largura_tela, altura_tela))

#criando objetos para classe
todas_as_sprites = pygame.sprite.Group() #criando grupo para todas as classes
sapo = Sapo() #instanciando uma classe
todas_as_sprites.add(sapo) #adicionando

for i in range(8):
    todas_as_sprites.add(sapo)
rodando = True
while rodando:
    relogio.tick(60)
    tela.fill((0, 0, 0))
    for event in pygame.event.get():
        if event.type == QUIT:
            rodando = False
            pygame.quit()
            exit()
        if event.type == KEYDOWN:
            if event.key == K_f:
                sapo.atacar()
                

    tela.blit(imagem_fundo, (0,0))
    todas_as_sprites.draw(tela)
    todas_as_sprites.update() #atualiza o objeto da sprite na tela
    pygame.display.flip() 