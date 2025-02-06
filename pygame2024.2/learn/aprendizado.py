import pygame
from pygame.locals import *
import sys
from random import randint
#Inicializa todas as funções e variaveis da biblioteca pygame
pygame.init()

#Configurando música de fundo
pygame.mixer.music.set_volume(0.3)
musica_de_fundo = pygame.mixer.music.load('pygame2024.2\\learn\\stylePrototipo\\BoxCat Games - Defeat.mp3')
pygame.mixer.music.play(-1)

#Configurando som da moeda
sound_coin = pygame.mixer.Sound('pygame2024.2\\learn\\stylePrototipo\\smw_coin.wav')
sound_coin.set_volume(1)

#Configurações da janela
largura = 740
altura = 580
tela = pygame.display.set_mode((largura,altura))
pygame.display.set_caption("???") # titulo da janela

#configurações dos retangulos
#OBS: meio = largura_tela // 2 - largura_objeto // 2 
x = largura // 2 - 20
y = altura // 2 - 20
x_azul = randint(30, 700)
y_azul = randint(20, 540)
# objeto que vai servir para controlar fps do jogo 
relogio = pygame.time.Clock()

#Configurações de texto      family size bold  italic
fonte = pygame.font.SysFont('arial', 40, True, True)
pontos = 0

#Loop principal do jogo
rodando = True
while rodando:
    #Controlando FPS do jogo
    relogio.tick(60)
    #Configurando a mensagem a ser exibida 
    mensagem = f"Pontos: {pontos}"
    texto_formatado = fonte.render(mensagem, False, (255, 255, 255))
    #Define, por padrão, a cor da tela a cada repetição
    tela.fill((0, 0, 0))
    # Analisa a ocorrencia de algum evento durante a execução
    for event in pygame.event.get():
        if event.type == QUIT: # botão sair
            rodando = False
            pygame.quit()
            sys.exit()
        '''if event.type ==  KEYDOWN: controla a posição do objeto a cada toque
            if event.key == K_a:
                x -= 1
            if event.key == K_d:
                x += 1
            if event.key == K_w:
                y -= 1
            if event.key == K_s:
                y += 1'''
        
    # Controla o movimento de um objeto ao pressionar uma das teclas indicadas, além disso, impõe um limite até onde o objeto pode se mover.
    if pygame.key.get_pressed()[K_a]:
        if x > 0:
            x -= 5
    if pygame.key.get_pressed()[K_d]:
        if x < largura - 40:
            x += 5
    if pygame.key.get_pressed()[K_w]:
        if y > 0:
            y -= 5
    if pygame.key.get_pressed()[K_s]:
        if y < altura - 40:
            y += 5
    

    #Desenhando retângulo                               
    retangulo1 = pygame.draw.rect(tela, (255, 0, 0), (x, y, 40, 40))
    retangulo2 = pygame.draw.rect(tela, (0, 0, 225), (x_azul, y_azul, 40, 40))

    #Fazendo uso de colisões
    if retangulo1.colliderect(retangulo2):
        pontos += 1
        sound_coin.play()
        x_azul = randint(20, 700)
        y_azul = randint(20, 540)
    
    #Mostrando o texto na tela 
    tela.blit(texto_formatado, (520, 40))
    #Atualiza a tela do jogo a cada interação (recomendável ficar no fim do loop)
    pygame.display.flip()
    

