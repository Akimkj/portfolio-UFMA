def encontrarProduto(v, alvo):
    left = 0
    right = len(v) - 1
    while left < right:
        if v[left] * v[right] == alvo:
            return True
        elif v[left] * v[right] < alvo:
            left += 1
        else:
            right -= 1
    return False

print(encontrarProduto([1, 2, 4, 7, 9, 10], 2))