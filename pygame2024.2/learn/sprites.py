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


rodando = True
while rodando:
    relogio.tick(60)
    tela.fill((0, 0, 0))
    for event in pygame.event.get():
        if event.type == QUIT:
            rodando = False
            pygame.quit()
            exit()

    

    pygame.display.flip() 