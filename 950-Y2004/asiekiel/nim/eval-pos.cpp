#include "eval-pos.h"
#include "find-lines.h"
#include <config.h>
#include <algorithm>
#include <iostream>
#include <iterator>

namespace KIK {

namespace {
      
      // Funkcja pomocnicza -- szybkie podnoszenie do pot�gi drugiej
      inline int pow2(int a, int n) { return a << (n - 1); }

      // Obiekt funkcyjny, kt�ry oblicza ocen� pozycji na podstawie obliczonych
      // wcze�niej d�ugo�ci linii.
      // Je�eli znaleziono lini� o d�ugo�ci wygrywaj�cej, to zwr�� WinningPosition.
      // W przeciwnym wypadku ocena jest sum� ocen za poszczeg�lne lini�, gdzie linia
      // d�ugo�ci n ma ocen� 4*(2^n).
      struct PositionEvaluator {
      private:
            int note;
      public:
            PositionEvaluator(): note(0) {}
            void operator()(int line_length) {
                  if (line_length == Config::winning_line_length)
                        note = WinningPosition;
                  else if (note < WinningPosition)
                        note += pow2(4, line_length);
            }
            operator int() { return note; }
      };
}

// Oblicz d�ugo�ci linii u�o�onych przez obydwu graczy. Je�eli sytuacja na planszy
// jest wygrywaj�ca/przegrywaj�ca dla gracza aktualnie wykonuj�cego ruch, to
// poinformuj o tym zwracaj�c odpowiednio WinningPosition/LosingPosition.
// W przeciwnym wypadku ocena jest r�nic� punkt�w aktualnego gracza i przeciwnika.
int EvaluateStaticPosition(const GameBoard& board)
{
      std::vector<int> current, other;
      findLines(board, board.whoseTurn(), std::back_inserter(current));
      findLines(board, opponent(board.whoseTurn()), std::back_inserter(other));

      int cur_note   = std::for_each(current.begin(), current.end(), PositionEvaluator());
      int other_note = std::for_each(other.begin(), other.end(), PositionEvaluator());

      if (cur_note == WinningPosition)
              return WinningPosition;
      if (other_note == WinningPosition)
            return LosingPosition;
      return cur_note - other_note;
}

}
