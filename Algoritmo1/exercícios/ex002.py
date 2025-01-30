a = 9
b = 8
print(a, b)
a, b = b, a
print(a, b)
'''
for i in range(7, 1001):
    num = str(i)
    if num[-1] == "7":
        print(i)
'''

def moveZeroes(nums):
    for i in nums:
        if i == 0:
            nums.append(i)
            nums.remove(i)