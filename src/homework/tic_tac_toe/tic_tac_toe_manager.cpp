#include "tic_tac_toe_manager.h"

// pub

void TicTacToeManager::save_game(TicTacToe b)
{
  games.push_back(b);
}

void TicTacToeManager::get_winner_total(int& o, int& x, int& t)
{
  o = o_win;
  x = x_win;
  t = ties;
}

void TicTacToeManager::update_winner_count(string winner)
{
  if (winner == "C")
    ties++;
  else if (winner == "X")
    x_win++;
  else
    o_win++;
}

// priv

ostream& operator<<(std::ostream& out, const TicTacToeManager& manager)
{
  for (unsigned int i = 0; i < manager.games.size(); i++)
    out << manager.games[i];
  return out;
}
