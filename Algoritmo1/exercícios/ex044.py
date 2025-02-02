def inverter_vetor(vetor):
    left = 0
    right = len(vetor) - 1
    while left < right:
        vetor[left], vetor[right] = vetor[right], vetor[left]
        left += 1
        right -= 1
    return vetor

              
v = [1,2,3,4,6,9,10]
print(inverter_vetor(v))