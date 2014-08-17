#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Using solve_faster and compiling with -O3, this only takes 0.175 seconds to
// run. More than a 100x speedup over the Python version!

void read_boards(vector<vector<int>>* boards) {
  boards->clear();
  int line_num = -1;
  string line;
  vector<int> board;
  while (getline(cin, line)) {
    line_num++;
    if (line_num % 10 == 0) continue;
    for (int i = 0; i < 9; i++) {
      board.push_back(line[i] - '0');
    }
    if (line_num % 10 == 9) {
      boards->push_back(board);
      board.clear();
    }
  }
}

void compute_neighbors(vector<vector<int>>* neighbors) {
  neighbors->clear();
  for (int idx = 0; idx < 81; idx++) {
    int y = idx / 9;
    int x = idx % 9;
    vector<int> nn;
    for (int yy = 0; yy < 9; yy++) {
      if (yy != y) nn.push_back(yy * 9 + x);
    }
    for (int xx = 0; xx < 9; xx++) {
      if (xx != x) nn.push_back(y * 9 + xx);
    }
    int cell_x0 = x - x % 3;
    int cell_y0 = y - y % 3;
    for (int yy = cell_y0; yy < cell_y0 + 3; yy++) {
      for (int xx = cell_x0; xx < cell_x0 + 3; xx++) {
        if (xx != x && yy != y) nn.push_back(yy * 9 + xx);
      }
    }
    neighbors->push_back(nn);
  }
}

// For speed, we pack the allowed moves of each position of the board into the
// bits of an int. When this returns, (*moves)[idx] gives the allowed moves
// for board[idx], where the ith bit of (*moves)[idx] is set iff it is legal
// to set board[idx] to i.
// If an empty space has no legal moves then the board is not a partial
// solution; in this situation we return false.
bool compute_possible_moves(const vector<int>& board,
                            const vector<vector<int>>& neighbors,
                            vector<int>* moves) {
  moves->clear();
  for (int idx = 0; idx < 81; idx++) {
    if (board[idx] > 0) {
      moves->push_back(0);
      continue;
    }
    int mm = 1022; // bits 1 through 9 set
    for (int n : neighbors[idx]) {
      mm &= ~(1 << board[n]);
    }
    if (mm == 0) return false;
    moves->push_back(mm);
  }
  return true;
}

bool solve(vector<int>* board,
           const vector<vector<int>>& neighbors) {
  vector<int> moves;
  bool has_moves = compute_possible_moves(*board, neighbors, &moves);
  if (!has_moves) {
    return false;
  }

  bool all_solved = true;
  for (int idx = 0; idx < 81; idx++) {
    if (moves[idx] != 0) {
      all_solved = false;
      for (int m = 1; m <= 9; m++) {
        // Check if the mth bit of moves[idx] is set
        if ((moves[idx] & (1 << m)) != 0) {
          (*board)[idx] = m;
          if (solve(board, neighbors)) return true;
          (*board)[idx] = 0;
        }
      }
      return false;
    }
  }

  return all_solved;
}

bool solve_faster_helper(vector<int>* board,
                         const vector<vector<int>>& neighbors,
                         vector<int>* moves) {
  bool all_solved = true;
  for (int idx = 0; idx < 81; idx++) {
    // If an empty space on the board has no legal moves then current state
    // of the board is not a partial solution, so return false.
    if ((*board)[idx] == 0 && (*moves)[idx] == 0) return false;

    if ((*moves)[idx] != 0) {
      all_solved = false;
      for (int m = 1; m <= 9; m++) {
        // Check if the mth bit of (*moves)[idx] is set
        if (((*moves)[idx] & (1 << m)) != 0) {
          // Set the board of the chosen space to the move
          (*board)[idx] = m;

          // Since we have just set board[idx], it now has no legal moves.
          // In order to clean up after ourselves later, we need to cache the
          // allowed moves of idx.
          int my_moves = (*moves)[idx];
          (*moves)[idx] = 0;

          // Since we just set board[idx] to m, m is no longer a legal move for
          // any neighbor of idx. In order to clean up after ourselves later we
          // keep track of which indices were actually changed.
          vector<int> changed_neighbors;
          changed_neighbors.push_back(idx);
          for (int n_idx : neighbors[idx]) {
            // Check if moves[n_idx] has the mth bit set
            if (((*moves)[n_idx] & (1 << m)) != 0) {
              // Clear the mth bit
              (*moves)[n_idx] &= ~(1 << m);
              changed_neighbors.push_back(n_idx);
            }
          }

          if (solve_faster_helper(board, neighbors, moves)) return true;

          // If we get here then setting idx to m did not result in a solution,
          // so we need to reset board and moves to be in the state they were
          // before.
          (*board)[idx] = 0;
          (*moves)[idx] = my_moves;
          for (int n_idx : changed_neighbors) {
            // Set the mth bit
            (*moves)[n_idx] |= (1 << m);
          }
          
        }
      }
      return false;
    }
  }
}

// In order to be a bit faster and use less memory, we avoid recomputing the
// legal moves for the entire board at each step of the search.
// We do a full scan of the board to determine all legal moves at the start of
// the search, and each step of the search will mutate the moves vector in-place
// rather than recomputing it.
bool solve_faster(vector<int>* board,
                  const vector<vector<int>>& neighbors) {
  vector<int> moves;
  bool has_moves = compute_possible_moves(*board, neighbors, &moves);
  if (!has_moves) return false;
  return solve_faster_helper(board, neighbors, &moves);
}

void print_board(const vector<int>& board) {
  for (int idx = 0; idx < 81; idx++) {
    cout << board[idx];
    if (idx % 9 == 8) cout << endl;
  }
}

int main() {
  // For speed, we flatten each board to be a 1D vector
  vector<vector<int>> boards;
  read_boards(&boards);

  // neighbors[idx] is a vector of the linear indices of the board that are in
  // the same row or col or cell as idx.
  vector<vector<int>> neighbors;
  compute_neighbors(&neighbors);
  
  int board_num = 0;
  int answer = 0;
  for (vector<int>& board : boards) {
    board_num++;
    bool solved = solve_faster(&board, neighbors);
    answer += 100 * board[0] + 10 * board[1] + board[2];
  }
  cout << answer << endl;

  return 0;
}
