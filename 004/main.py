def is_palindrome(x):
  forward = list(str(x))
  backward = list(str(x))
  backward.reverse()
  return forward == backward

m = 0
for x in xrange(100, 1000):
  for y in range(x, 1000):
    if is_palindrome(x * y):
     m = max(m, x * y)

print m
