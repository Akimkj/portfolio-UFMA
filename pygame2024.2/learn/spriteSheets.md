**Conceito**
Sprite sheet é uma imagem única que contém todos os frames de uma animação. Nas sprite sheets, os frames estão visualmente organizados em linhas e colunas, como uma matriz.
*Dica*
Em uma Sprite sheet, o recomendável é que cada frame possua a mesma proporção de largura e altura.

**Organização dos frames**
Cada frame ocupa uma posição na sprite sheet. Seguindo a definição na computação, o ínicio de uma imagem/frame sempre se dá pelo ponto superior esquerdo (topleft). Por exemplo, em uma sprite sheet que cada frame tem 32px de largura e de altura, o frame [0][0] está na coordenada x = 0, y = 0. Já o frame [0][1] está na coordenada x = 32, y = 0. Agora, o frame [1][0] está na coordenada x = 0, y = 32, pois houve um deslocamento vertical. 

*Site para sprites sheets*
OpenGameArt.org