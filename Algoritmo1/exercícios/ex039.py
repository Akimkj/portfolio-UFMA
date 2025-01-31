def organize_zeros_ones(arr: list) -> list:
  left = 0
  right = len(arr) - 1
  while left <= right:
    if arr[left] > arr[right]:
      arr[left], arr[right] = 0,1
      left += 1
      right -= 1
    elif arr[left] == arr[right]:
      right -= 1
    
  return arr  
print(organize_zeros_ones([1, 1, 0, 0, 1, 0]))