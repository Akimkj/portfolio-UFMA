import pygame
from pygame.locals import *
import sys

#Inicializa todas as funções e variaveis da biblioteca pygame
pygame.init()

# configurações da janela
largura = 740
altura = 580
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
