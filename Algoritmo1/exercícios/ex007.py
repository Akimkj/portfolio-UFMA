def winner(play1, play2):
    if (play1 == "scissor" and play2 == "stone") or (play1 == "stone" and play2 == "paper") or (play1 == "paper" and play2 == "scissor"):
        return "Player2"
    elif (play1 == play2):
        return "draw"
    else:
        return "Player1"

jogador1 = input("Player1, faça sua escolha: ")
jogador2 = input("Player2, faça sua escolha: ")    
print(f"Quem vençeu foi o {winner(jogador1, jogador2)}")
