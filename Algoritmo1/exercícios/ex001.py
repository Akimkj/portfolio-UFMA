v = [-3, 0, 1, 2, 5]              

'''def moveZeroes(nums):
    for i in nums:
        if i == 0:
            nums.append(i)
            nums.remove(i)
    return nums'''
def moveZeroes(nums):
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            if nums[i] == 0:
                nums[i], nums[j] = nums[j], nums[i]
                
    
    return nums

print(moveZeroes(v))

def emOrdem(vetor):
    '''for i in range(len(vetor)):
        for j in range(i + 1, len(vetor)):
            if vetor[i] >= vetor[j]:
                return False'''
    for i in range(len(vetor) - 1):
        if vetor[i] >= vetor[i + 1]:
            return False
    
    return True

print(emOrdem(v))

