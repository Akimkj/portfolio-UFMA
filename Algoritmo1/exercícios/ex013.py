def fullhouse (d1, d2, d3, d4, d5):
    if (d1 == d2 != d3 == d4 == d5) or (d1 == d3 != d2 == d4 == d5) or (d1 == d4 != d2 == d3 == d5) or (d1 == d5 != d2 == d3 == d4):
        return True
    elif (d2 == d3 != d1 == d4 == d5) or (d2 == d4 != d1 == d3 == d5) or (d2 == d5 != d1 == d3 == d4):
        return True
    elif (d3 == d4 != d1 == d2 == d5) or (d3 == d5 != d1 == d2 == d4):
        return True
    elif (d4 == d5 != d1 == d2 == d3):
        return True
    else:
        return False
    
print(fullhouse(1, 1, 4, 2, 2))