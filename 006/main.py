nums = list(xrange(1, 101))
print sum(nums) ** 2 - sum(x ** 2 for x in nums)
