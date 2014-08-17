import sys
from itertools import product

# This takes 18.589 seconds to run on my machine. Kinda slow.

def read_input(f):
  all_boards = []
  board = []
  for i, line in enumerate(f):
    # Skip the header that appears before each board
    if i % 10 == 0:
      continue

    # Parse a row of the board
    board.append([int(c) for c in line.strip()])

    # Finish the current board and start a new one
    if i % 10 == 9:
      all_boards.append(board)
      board = []
  return all_boards

def get_possible_moves(board):
  possible_moves = []
  for y, row in enumerate(board):
    row_moves = []
    for x, elem in enumerate(row):
      if elem != 0:
        row_moves.append(set())
        continue
      moves = set(xrange(1, 10))
      moves.difference_update(row)
      moves.difference_update(board[yy][x] for yy in xrange(9))
      cell_x0 = x - x % 3
      cell_y0 = y - y % 3
      cell_xys = product(xrange(cell_x0, cell_x0 + 3),
                         xrange(cell_y0, cell_y0 + 3))
      moves.difference_update(board[yy][xx] for xx, yy in cell_xys)

      if len(moves) == 0:
        return None
      row_moves.append(moves)
    possible_moves.append(row_moves)
  return possible_moves

def solve(board):
  possible_moves = get_possible_moves(board)
  if possible_moves is None:
    return False

  all_solved = True
  for y, row_moves in enumerate(possible_moves):
    for x, moves in enumerate(row_moves):
      if len(moves) > 0:
        all_solved = False
        for move in moves:
          board[y][x] = move
          if solve(board):
            return True
          board[y][x] = 0
        return False

  return all_solved

def main():
  boards = read_input(sys.stdin)

  answer = 0
  for i, board in enumerate(boards):
    solve(board)
    answer += 100 * board[0][0] + 10 * board[0][1] + board[0][2]
    print 'Done with puzzle %d' % (i + 1)
  print answer

if __name__ == '__main__':
  main()
