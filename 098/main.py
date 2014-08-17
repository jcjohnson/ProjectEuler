import sys, itertools
from collections import Counter
from operator import itemgetter

def read_input():
  """ Reads input file from stdin """
  words = sys.stdin.readline().split(',')
  return [word[1:-1] for word in words]

def letter_hist_key(word):
  """
  Compute the letter histogram of a word, and transform it into a string.
  Since two words are palindromes iff they have the same letter histogram,
  this allows us to find palindromes efficiently.

  NOTE: The transformation of letter histogram -> may not be unique if the
  word contains numbers.
  """
  hist = Counter(word).most_common()
  hist.sort(key=itemgetter(0))
  return ''.join(letter + str(count) for letter, count in hist)

def find_palindromes(words):
  """
  Find palindromes in a list of strings. Returns a list of lists, where each
  inner list is a palindrome group.
  """
  key_to_words = {}
  for word in words:
    key = letter_hist_key(word)
    if key not in key_to_words:
      key_to_words[key] = []
    key_to_words[key].append(word)
  return [words for key, words in key_to_words.iteritems() if len(words) > 1]

def find_square_subs(word):
  """
  Find all mappings of letters to digits that make a word into a square.
  Returns a list of (mapping, square) tuples.
  """
  letter_mappings = []
  num = 1
  square_str = str(num * num)

  # We iterate over string versions of square numbers until they get too long.
  while len(square_str) <= len(word):
    if len(square_str) == len(word):
      # This square number has the same length as word, so try to compute a
      # bijective mapping from letters to digits.
      letter_to_digit = {}
      digit_to_letter = {}
      for digit, letter in zip(square_str, word):
        if (digit in digit_to_letter and digit_to_letter[digit] != letter or
            letter in letter_to_digit and letter_to_digit[letter] != digit):
          # The mapping isn't bijective; thus there is no letter mapping that
          # transforms this word into this square number.
          letter_to_digit = None
          digit_to_letter = None
          break
        digit_to_letter[digit] = letter
        letter_to_digit[letter] = digit
      if letter_to_digit is not None:
        letter_mappings.append((letter_to_digit, num * num))
    num += 1
    square_str = str(num * num)
  return letter_mappings

def find_best_square(word1, word2):
  """
  For a pair of words, return the largest square number that we can make by
  transforming both words with a common letter mapping. If there is no letter
  mapping that transforms both words into square numbers then return None.
  """
  word1_mappings = find_square_subs(word1)
  word2_mappings = find_square_subs(word2)
  best_square = None
  for mapping1, s1 in word1_mappings:
    for mapping2, s2 in word2_mappings:
      if mapping1 == mapping2:
        best_square = max(best_square, s1, s2)
  return best_square

def main():
  words = read_input()
  palindromes = find_palindromes(words)
  best_square = 0
  for palindrome_group in palindromes:
    for w1, w2 in itertools.combinations(palindrome_group, 2):
      best_square = max(best_square, find_best_square(w1, w2))
  print best_square

if __name__ == '__main__':
  main()

