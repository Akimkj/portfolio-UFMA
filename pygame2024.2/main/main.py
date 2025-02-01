import pygame
import sys

pygame.init()

# Configuração para o tamanho da tela/janela
LARGURA_TELA = 600
ALTURA_TELA = 400
tela = pygame.display.set_mode((LARGURA_TELA, ALTURA_TELA))
pygame.display.set_caption("Joguinho com Movimentação e Imagem")  # Define o título da janela

clock = pygame.time.Clock()

# Carrega a imagem de fundo
 #fundo = pygame.image.load("pygame2024.2\\style\\montanhas.jpg")
 #fundo = pygame.transform.smoothscale(fundo, (LARGURA_TELA, ALTURA_TELA))

#configuração da cor de fundo
corFundo = (0, 0, 0)


# Configuração da fonte e texto
fonte = pygame.font.Font(None, 50)
texto_surface = fonte.render('Joguinho', True, "Red")  # O segundo argumento é para suavização (anti-aliasing)

# Carrega a imagem do personagem

personagem_imagem = pygame.image.load("pygame2024.2\\style\\heart.webp")  #Endereço da imagem
personagem_largura = personagem_imagem.get_width()  # Largura da imagem
personagem_altura = personagem_imagem.get_height()  # Altura da imagem


# Configuração do personagem
personagem_x = LARGURA_TELA // 2 - personagem_largura // 2  # Posição inicial no centro da tela
personagem_y = ALTURA_TELA // 2 - personagem_altura // 2
personagem_velocidade = 3  # Velocidade de movimentação

rodando = True

while rodando:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            rodando = False

    # Captura das teclas pressionadas
    teclas = pygame.key.get_pressed()

    # Movimentação do personagem
    if teclas[pygame.K_LEFT] and personagem_x > 0:  # Movimenta para a esquerda
        personagem_x -= personagem_velocidade
    if teclas[pygame.K_RIGHT] and personagem_x < LARGURA_TELA - personagem_largura:  # Movimenta para a direita
        personagem_x += personagem_velocidade
    if teclas[pygame.K_UP] and personagem_y > 0:  # Movimenta para cima
        personagem_y -= personagem_velocidade
    if teclas[pygame.K_DOWN] and personagem_y < ALTURA_TELA - personagem_altura:  # Movimenta para baixo
        personagem_y += personagem_velocidade

    # Desenha o fundo, o texto e o personagem na tela
    tela.fill(corFundo) #cor de fundo
     #tela.blit(fundo, (0, 0)) #imagem de fundo
    tela.blit(texto_surface, (250, 50))  # Posiciona o texto no topo da tela
    tela.blit(personagem_imagem, (personagem_x, personagem_y))  # Desenha o personagem

    # Atualiza a tela
    pygame.display.update()

    # Controla a taxa de atualização da tela
    clock.tick(60)

pygame.quit()
sys.exit()