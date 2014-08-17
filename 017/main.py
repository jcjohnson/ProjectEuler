ones = {
  1: 'one',
  2: 'two',
  3: 'three',
  4: 'four',
  5: 'five',
  6: 'six',
  7: 'seven',
  8: 'eight',
  9: 'nine',
  10: 'ten',
  11: 'eleven',
  12: 'twelve',
  13: 'thirteen',
  14: 'fourteen',
  15: 'fifteen',
  16: 'sixteen',
  17: 'seventeen',
  18: 'eighteen',
  19: 'nineteen'
}

tens = {
  1: 'ten',
  2: 'twenty',
  3: 'thirty',
  4: 'forty',
  5: 'fifty',
  6: 'sixty',
  7: 'seventy',
  8: 'eighty',
  9: 'ninety',
}

def num_to_str(num):
  """
  This only works for integers 1 <= num <= 1000 and could probably be much more
  efficient, but it is good enough to solve the problem.
  """
  if num == 1000:
    return 'one thousand'
  hs = ''
  if num >= 100:
    h = num / 100
    hs = ones[h] + ' hundred'
  o = num % 100
  os = ''
  if o in ones:
    os = ones[o]
  else:
    if o / 10 in tens:
      os = tens[o / 10]
    if o % 10 in ones:
      os += ' ' + ones[o % 10]
  if len(hs) > 0 and len(os) > 0:
    return hs + ' and ' + os
  else:
    return hs + os

count = 0
for x in range(1, 1001):
  s = num_to_str(x)
  count += len(s.replace(' ', ''))
print count
