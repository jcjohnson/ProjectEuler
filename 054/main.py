

class Card:
  face_values = {'T': 10, 'J': 11, 'Q': 12, 'K': 13, 'A': 14}

  def __init__(self, s):
    self.s = s
    try:
      self.value = int(s[0])
    except ValueError:
      self.value = Card.face_values[s[0]]
    self.suit = s[1]

  def __str__(self):
    return str(self.value) + self.suit

def PrintHand(hand):
  print ' '.join(str(c) for c in hand)

def HandValue(hand):
  fns = {RoyalFlush: 10, StraightFlush: 9, FourOfAKind: 8, FullHouse: 7,
         Flush: 6, Straight: 5, ThreeOfAKind: 4, TwoPairs: 3, Pair: 2}

  rank = 1
  rankValue = []
  for (f, r) in fns.iteritems():
    (has, rv) = f(hand)
    if has and r > rank:
      rank, rankValue = r, rv

  values = sorted(c.value for c in hand)
  values.reverse()
  return [rank] + rankValue + values

def GetCounts(hand):
  values = {c.value for c in hand}
  d = {}
  for v in values:
    d[v] = len([c for c in hand if c.value == v])
  return d

def NOfAKind(hand, n):
  counts = GetCounts(hand)
  if n in counts.values():
    v = [v for (v, c) in counts.iteritems() if c == n][:1]
    return (True, v)
  return (False, [])

def Pair(hand):
  return NOfAKind(hand, 2)

def TwoPairs(hand):
  counts = GetCounts(hand)
  if 2 == len([c for c in counts.values() if c == 2]):
    vs = sorted([v for (v, c) in counts.iteritems() if c == 2])
    vs.reverse()
    return (True, vs)
  return (False, None)

def ThreeOfAKind(hand):
  return NOfAKind(hand, 3)

def Straight(hand):
  values = sorted(c.value for c in hand)
  start = values[0]
  target = [start, start + 1, start + 2, start + 3, start + 4]
  return (values == target, [])

def Flush(hand):
  return (len({c.suit for c in hand}) == 1, [])

def FullHouse(hand):
  (hasPair, pair) = Pair(hand)
  (hasTriple, triple) = ThreeOfAKind(hand)
  if hasPair and hasTriple:
    return (True, triple)
  return (False, [])

def FourOfAKind(hand):
  return NOfAKind(hand, 4)

def FourOfAKindTest():
  hand = ["3H", "3D", "3C", "6H", "3S"]
  hand = [Card(c) for c in hand]
  return FourOfAKind(hand)

def StraightFlush(hand):
  return (Straight(hand)[0] and Flush(hand)[0], [])

def RoyalFlush(hand):
  royal = sorted(c.value for c in hand) == [10, 11, 12, 13, 14]
  flush = Flush(hand)[0]
  return (royal and flush, [])

def RoyalFlushTest():
  hand = ["TH", "KH", "JH", "AH", "QH"]
  hand = [Card(c) for c in hand]
  return RoyalFlush(hand)

def test():
  p1hands = [['5H', '5C', '6S', '7S', 'KD'],
             ['5D', '8C', '9S', 'JS', 'AC'],
             ['2D', '9C', 'AS', 'AH', 'AC'],
             ['4D', '6S', '9H', 'QH', 'QC'],
             ['2H', '2D', '4C', '4D', '4S']]
  p2hands = [['2C', '3S', '8S', '8D', 'TD'],
             ['2C', '5C', '7D', '8S', 'QH'],
             ['3D', '6D', '7D', 'TD', 'QD'],
             ['3D', '6D', '7H', 'QD', 'QS'],
             ['3C', '3D', '3S', '9S', '9D']]
  for (p1, p2) in zip(p1hands, p2hands):
    p1 = [Card(s) for s in p1]
    PrintHand(p1)
    p1_hand_value = HandValue(p1)
    print p1_hand_value

    p2 = [Card(s) for s in p2]
    PrintHand(p2)
    p2_hand_value = HandValue(p2)
    print p2_hand_value

    if p1_hand_value > p2_hand_value:
      print 'Player 1 wins\n'
    else:
      print 'Player 2 wins\n'

def main():
  with open("poker.txt") as f:
    count = 0
    for line in f:
      cards = line.strip().split()
      p1 = [Card(s) for s in cards[:5]]
      p2 = [Card(s) for s in cards[5:]]
      if HandValue(p1) > HandValue(p2):
        count += 1
    print count

if __name__ == "__main__":
  main()
