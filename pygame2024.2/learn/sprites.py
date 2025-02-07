# Sprites - são objetos/imagens que se movem pela tela
# Para animar uma sprite, é necessária uma sequencia de imagens que se alteram rapidamente, com o objetivo de causar a sensação de movimento
import pygame
from pygame.locals import *
from sys import exit

pygame.init()

largura_tela = 640
altura_tela = 480
tela = pygame.display.set_mode((largura_tela, altura_tela))
pygame.display.set_caption("Sprites")
relogio = pygame.time.Clock()

#cria uma classe chamada Sapo que herda atributos e métodos de uma classe já pronta no pygame
class Sapo(pygame.sprite.Sprite):
    def __init__(self):
       pygame.sprite.Sprite.__init__(self) #herdar caracteristicas da SpriteClass
       self.sprites = [] #lista para armazenar todas as sprites do mesmo personagem
       self.sprites.append(pygame.image.load("pygame2024.2\\learn\\stylePrototipo\\sapo\\attack_1.png"))
       self.sprites.append(pygame.image.load("pygame2024.2\\learn\\stylePrototipo\\sapo\\attack_2.png"))
       self.sprites.append(pygame.image.load("pygame2024.2\\learn\\stylePrototipo\\sapo\\attack_3.png"))
       self.sprites.append(pygame.image.load("pygame2024.2\\learn\\stylePrototipo\\sapo\\attack_4.png"))
       self.sprites.append(pygame.image.load("pygame2024.2\\learn\\stylePrototipo\\sapo\\attack_5.png"))
       self.sprites.append(pygame.image.load("pygame2024.2\\learn\\stylePrototipo\\sapo\\attack_6.png"))
       self.sprites.append(pygame.image.load("pygame2024.2\\learn\\stylePrototipo\\sapo\\attack_7.png"))
       self.sprites.append(pygame.image.load("pygame2024.2\\learn\\stylePrototipo\\sapo\\attack_8.png"))
       self.sprites.append(pygame.image.load("pygame2024.2\\learn\\stylePrototipo\\sapo\\attack_9.png"))
       self.sprites.append(pygame.image.load("pygame2024.2\\learn\\stylePrototipo\\sapo\\attack_10.png"))
       self.atual = 0 #indice da lista com as sprites
       self.image = self.sprites[self.atual] #atributo herdado para mostrar a moviementação da sprite.
       self.image = pygame.transform.scale(self.image, (128 *3, 64 *3)) #aumenta ou diminui a escala a sprite
       self.rect = self.image.get_rect() #trata a sprite como um retangulo
       self.rect.topleft = 100, 100

       self.animar = False #atributo que diz quando a sprite vai animar ou não
    
    def atacar(self): #método que controla o atributo de animação
        self.animar = True

    def update(self): #método herdado da SpriteClass
        if self.animar == True:
            self.atual += 0.3 # esse valor controla a velocidade da animação
            if self.atual >= len(self.sprites):
                self.atual = 0
                self.animar = False
            self.image = self.sprites[int(self.atual)] # a função int() é para arredondar o indice para inteiro, e evitar erro no meu código
            self.image = pygame.transform.scale(self.image, (128 *3, 64 *3))


todas_as_sprites = pygame.sprite.Group()
sapo = Sapo()
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
                

    
    todas_as_sprites.draw(tela)
    todas_as_sprites.update() #atualiza o objeto da sprite na tela
    pygame.display.flip() 