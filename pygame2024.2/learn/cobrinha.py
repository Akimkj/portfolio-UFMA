import pygame
from pygame.locals import *
from sys import exit
from random import randint
pygame.init()

#Nessa função, recebe a lista com as coordenadas no corpo da cobra, e faz com que desenhe na tela
def aumentaCobra(lista_cobra):
    for XeY in lista_cobra:
        pygame.draw.rect(tela, (0, 255, 0), (XeY[0], XeY[1], largura_cobra, altura_cobra))

#janela
largura_tela = 740
altura_tela = 680
tela = pygame.display.set_mode((largura_tela, altura_tela))
pygame.display.set_caption("Jogo da cobrinha")
relogio = pygame.time.Clock()

#configuração cobrinha e maçã
largura_cobra = 40
altura_cobra = 40
pos_x_cobra = (largura_tela // 2) - (largura_cobra // 2)
pos_y_cobra = (altura_tela // 2) - (altura_cobra // 2)
velocidade = 5
x_control = velocidade
y_control = 0
lista_corpo = []
comprimento_inicial = 5
#
largura_maca = 30
altura_maca = 30
pos_x_maca = randint(20, largura_tela - 20)
pos_y_maca = randint(20, altura_tela - 20)

#Texto 
fonte = pygame.font.SysFont('arial', 40, True, False)
pontos = 0

#som
sound_moeda = pygame.mixer.Sound("pygame2024.2\\learn\\stylePrototipo\\smw_coin.wav")
sound_moeda.set_volume(1)


rodando = True
while True:
    mensagem = f"Pontos: {pontos}"
    texto_formatado = fonte.render(mensagem, True, (0, 0, 0))
    relogio.tick(60)
    tela.fill((255, 255, 255))
    for event in pygame.event.get():
        if event.type == QUIT:
            rodando = False
            pygame.quit()
            exit()
        if event.type ==  KEYDOWN: 
            if event.key == K_a:
                if x_control == velocidade:
                    pass
                else:
                    x_control = -velocidade
                    y_control = 0
            if event.key == K_d:
                if x_control == -velocidade:
                    pass
                else:
                    x_control = +velocidade
                    y_control = 0
            if event.key == K_w:
                if y_control == velocidade:
                    pass
                else:
                    x_control = 0
                    y_control = -velocidade
            if event.key == K_s:
                if y_control == -velocidade:
                    pass
                else:
                    x_control = 0
                    y_control = +velocidade
   
    pos_x_cobra += x_control
    pos_y_cobra += y_control

    cobra = pygame.draw.rect(tela, (0, 255, 0), (pos_x_cobra, pos_y_cobra, largura_cobra, altura_cobra))
    maca = pygame.draw.rect(tela, (255, 0, 0), (pos_x_maca, pos_y_maca, largura_maca, altura_maca))

    if cobra.colliderect(maca):
        pontos += 1
        comprimento_inicial += 2
        sound_moeda.play()
        pos_x_maca = randint(20, largura_tela - (largura_maca + 20))
        pos_y_maca = randint(20, altura_tela - (altura_maca + 20))

    #lista para pegar as posições atuais e anteriores da cobra 
    lista_cabeca = []
    lista_cabeca.append(pos_x_cobra)
    lista_cabeca.append(pos_y_cobra)
    lista_corpo.append(lista_cabeca)

    #impõe um limite no tamanho da lista do corpo da cobra, para não crescer indefinidamente
    if len(lista_corpo) > comprimento_inicial:
        del lista_corpo[0]

    aumentaCobra(lista_corpo)

    tela.blit(texto_formatado, (520, 20))
    pygame.display.flip()