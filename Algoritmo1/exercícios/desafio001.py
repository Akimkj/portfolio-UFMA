# prototipo

def zeroes_ones(v):
    for i in range(len(v) - 1):
        if v[i] == 0:
            continue
        if v[i] > v[i + 1]:
            v[i], v[i +1] = 0,1
        
    return v

vetor = [0, 1, 1, 0, 0, 0, 1]

print(zeroes_ones(vetor))