import pygame
import sys

pygame.init()

tela = pygame.display.set_mode((600, 400))
clock = pygame.time.Clock()
surface_teste = pygame.Surface((100, 200))
surface_teste.fill("Green")
fundo = pygame.image.load()
fundo = pygame.transform.smoothscale(fundo, (600, 400))
fonte = pygame.font.Font(None, 50)
texto_surface = fonte.render('Joguinho', False, "Red")

rodando = True

while rodando:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()
    
    tela.blit(surface_teste, (0,0))
    clock.tick(60)