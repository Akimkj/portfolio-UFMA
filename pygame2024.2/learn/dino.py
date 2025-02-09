import pygame
from pygame.locals import *
from sys import exit
import os 
from random import randrange
pygame.init()

#variaveis gerais
largura_tela = 990
altura_tela = 555
fundo = (255, 255, 255)

tela = pygame.display.set_mode((largura_tela, altura_tela))
pygame.display.set_caption("Dino")

#diretorios
diretorio_principal = os.path.dirname(__file__) # indica o caminho absoluto do arquivo do jogo
diretorio_secundario = os.path.join(diretorio_principal, "stylePrototipo")#serve para indicar o caminho absoluto de um arquivo dentro de uma pasta que se encontra no mesmo arquivo pai do diretorio principal

sprite_sheet = pygame.image.load(os.path.join(diretorio_secundario, "dinoSpritesheet.png")).convert_alpha() #o "os.path.join()" recebe como parametros a pasta do arquivo e o nome do arquivo. E o convert.alpha() faz com que, se a imagem tiver fundo transparente, ele irá ignora-lo.

#Classes
class Dino(pygame.sprite.Sprite): 
    def __init__(Self):
        super().__init__()
        Self.sprites = []
        for i in range(3): #Para otimizar código
            img = sprite_sheet.subsurface((i * 32,0), (32,32)) # topleft, largura e altura do frame
            img = pygame.transform.scale(img, (32 *3, 32 * 3))
            Self.sprites.append(img)
        Self.index_lista = 0
        Self.image = Self.sprites[Self.index_lista]
        Self.rect = Self.image.get_rect()
        Self.rect.center = (100, altura_tela - 80)
    
    def update(Self): #para atualizar imagens
        if Self.index_lista > 2:
            Self.index_lista = 0
        Self.index_lista += 0.25
        Self.image = Self.sprites[int(Self.index_lista)]

class Nuvens(pygame.sprite.Sprite):
    def __init__(Self):
        super().__init__()
        Self.image = sprite_sheet.subsurface((7 * 32, 0), (32, 32))
        Self.image = pygame.transform.scale(Self.image, (32 * 3, 32*3)) #adaptar tamanho
        Self.rect = Self.image.get_rect() #transforma a estrutura em um retângulo para poder desenhar na tela
        Self.rect.y = randrange(50, 200, 50)
        Self.rect.x = largura_tela + randrange(30, 300, 90)
    
    def update(Self): # para mover a nuvem horizontalmente
        if Self.rect.topright[0] < 0: #pega o ponto x[0] do canto superior direito do frame, para causar mais naturalidade
            Self.rect.x = largura_tela + randrange(30, 300, 90)
            Self.rect.y = randrange(50, 200, 50)
        Self.rect.x -= 8

class Chao(pygame.sprite.Sprite):
    def __init__(Self, pos_x):
        super().__init__()
        Self.image = sprite_sheet.subsurface((6 * 32, 0), (32, 32))
        Self.image = pygame.transform.scale(Self.image, (32 * 2, 32*2))
        Self.rect = Self.image.get_rect()
        Self.rect.y = altura_tela - 80
        Self.rect.x = pos_x * 64

    def update(Self):
        if Self.rect.topright[0] < 0: #pega o ponto x[0] do canto superior direito do frame, para causar mais naturalidade
            Self.rect.x = largura_tela
        Self.rect.x -= 8


todas_as_sprites = pygame.sprite.Group()
dino = Dino()
todas_as_sprites.add(dino)
for i in range(largura_tela * 2//60):
    chao = Chao(i)
    todas_as_sprites.add(chao)

for i in range(4): #adiciona 4 objetos nuvens no grupo 
    nuvem = Nuvens()
    todas_as_sprites.add(nuvem)

relogio = pygame.time.Clock()
rodando = True
while rodando:
    relogio.tick(45)
    tela.fill(fundo)
    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            exit()
    
    todas_as_sprites.draw(tela)
    todas_as_sprites.update()

    pygame.display.flip()