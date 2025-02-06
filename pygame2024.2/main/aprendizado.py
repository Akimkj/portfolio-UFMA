import pygame
from pygame.locals import *
import sys

#Inicializa todas as funções e variaveis da biblioteca pygame
pygame.init()

# configurações da janela
largura = 740
altura = 580
x = 0
y = 0
tela = pygame.display.set_mode((largura,altura))
pygame.display.set_caption("???")


#Loop principal do jogo
rodando = True
while rodando:
    # Analisa a ocorrencia de algum evento durante a execução
    for event in pygame.event.get():
        if event.type == pygame.QUIT: # botão sair
            rodando = False
            pygame.quit()
            sys.exit()
    #Atualiza a tela do jogo a cada interação
    pygame.display.update()

    #Desenhando retângulo                               
    retangulo1 = pygame.draw.rect(tela, (255, 0, 0), (x, y, 40, 40))
    #Desenhando circulos                                         raio
    #circulo1 = pygame.draw.circle(tela, (0, 255, 0), (300, 300), 30)
    #Desenhando linhas
    #linha1 = pygame.draw.line(tela, (200, 180, 20), (30, 30), (200, 160), 5)

