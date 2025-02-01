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
   
v=[3,23,0,1,0,3,0]
print(moveZeroes(v))