def chaves(primos):
    r = []
    for i in range(len(primos)):
        for j in range(i + 1, len(primos)):
            for k in range(j + 1, len(primos)):
                if i != j and j != k:
                    r.append(primos[i] * primos[j] * primos[k])
    
    return r

print(chaves([2, 5, 11]))