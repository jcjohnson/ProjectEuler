from collections import deque, Counter
from random import randint, shuffle
from multiprocessing import Pool

board = [
  'GO', 'A1', 'CC1', 'A2', 'T1', 'R1', 'B1', 'CH1', 'B2', 'B3',
  'JAIL', 'C1', 'U1', 'C2', 'C3', 'R2', 'D1', 'CC2', 'D2', 'D3',
  'FP', 'E1', 'CH2', 'E2', 'E3', 'R3', 'F1', 'F2', 'U2', 'F3',
  'G2J', 'G1', 'G2', 'CC3', 'G3', 'R4', 'CH3', 'H1', 'T2', 'H2'
]

square_to_idx = {s: i for i, s in enumerate(board)}

def draw_card(deck):
  card = deck.pop()
  deck.appendleft(card)
  return card

def make_move(start, dice_sum, community_chest, chance):
  idx = start
  idx = (idx + dice_sum) % len(board)

  # Go to jail
  if board[idx] == 'G2J':
    return square_to_idx['JAIL']

  # It is possible to draw both a chance card and a community chest card in
  # the same turn only if we land on CH3, draw 10, and go back 3 spaces to CC3.
  # Therefore it suffices to check chance and then community chest.

  # Chance cards
  if board[idx].startswith('CH'):
    card = draw_card(chance)
    if card == 1:
      return square_to_idx['GO']
    elif card == 2:
      return square_to_idx['JAIL']
    elif card == 3:
      return square_to_idx['C1']
    elif card == 4:
      return square_to_idx['E3']
    elif card == 5:
      return square_to_idx['H2']
    elif card == 6:
      return square_to_idx['R1']
    elif card == 7 or card == 8:
      # Go to next railroad
      while not board[idx].startswith('R'):
        idx = (idx + 1) % len(board)
    elif card == 9:
      while not board[idx].startswith('U'):
        idx = (idx + 1) % len(board)
    elif card == 10:
      idx = (idx + len(board) - 3) % len(board)

  # Community chest
  if board[idx].startswith('CC'):
    card = draw_card(community_chest)
    if card == 1:
      return square_to_idx['GO']
    elif card == 2:
      return square_to_idx['JAIL']

  return idx

def simulate_game(num_moves, dice_size):
  community_chest = deque(xrange(16))
  shuffle(community_chest)

  chance = deque(xrange(16))
  shuffle(chance)

  move_counter = Counter()

  num_doubles = 0

  idx = 0
  for _ in xrange(num_moves):
    d1, d2 = randint(1, dice_size), randint(1, dice_size)
    if d1 == d2:
      num_doubles += 1
    else:
      num_doubles = 0
    if num_doubles == 3:
      num_doubles = 0
      idx = square_to_idx['JAIL']
    else:
      idx = make_move(idx, d1 + d2, community_chest, chance)
    move_counter.update([idx])

  return move_counter

def main():
  num_games = 20000
  moves_per_game = 1000
  dice_size = 4

  move_counter = Counter()
  for _ in xrange(num_games):
    move_counter.update(simulate_game(moves_per_game, dice_size))
 
  most_common = move_counter.most_common()

  # Printing out the percents helps debugging
  total_moves = sum(c[1] for c in most_common)
  percents = [(board[c[0]], float(c[1]) / total_moves) for c in most_common]
  print percents
  print
  
  # Print out the actual answer
  modal_string = ''
  for idx, _ in most_common[:3]:
    modal_string += str(idx).zfill(2)
  print modal_string

if __name__ == '__main__':
  main()
