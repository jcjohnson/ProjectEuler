import sys
from operator import mul

length = 13
digits = [int(d) for d in sys.stdin.readline().strip()]
m = 0
for i in xrange(0, len(digits) - length + 1):
  m = max(m, reduce(mul, digits[i:i+length], 1))
print m
