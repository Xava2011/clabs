#ifndef INCLUDED__FIND_LINES_H
#define INCLUDED__FIND_LINES_H

#include <vector>
#include <iterator>
#include <iostream>
#include "game-repr.h"

// Obliczanie d�ugo�ci u�o�onych linii

namespace KIK {

namespace {
      // Struktura opisuj�ca kierunek ruchu
      struct MoveDirection {
            int dx;
            int dy;
      };

      // W tych kierunkach b�dziemy szukali linii
      MoveDirection directions[] = { {1,0}, {1,1}, {0,1}, {-1,1} };

      // Zwi�ksz ruch (punkt) o wsp�rz�dne (dx, dy)
      inline Move& operator+=(Move& m, const MoveDirection& d) { m.x+=d.dx; m.y+=d.dy; return m; }

      // Sprawd�, czy dany ruch znajduje si� wewn�trz planszy gry
      inline bool insideBoard(const Move& m, const GameBoard& b) { return m.x >= 0 && m.y >= 0 && m.x < b.width() && m.y < b.height(); }

      // Funkcja, kt�ra ma najwi�kszy wp�yw na wydajno�� ca�ego programu -- zlicz linie z�o�one
      // ze znaczk�w 'tile' w kierunku 'd', d�ugo�ci obliczonych linii zapisz na iterator 'out'
      template <typename OutputIter>
      void findLineInDirection(const GameBoard& board, const tileT tile,
                          const MoveDirection d, OutputIter out)
      {
            // tablica, w kt�rej pami�tamy, czy dany punkt ju� odwiedzili�my
            std::vector<bool> used_tiles(board.width() * board.height());

            // dla wszystkich punkt�w na planszy: pr�buj i�� jak najdalej si� da
            // w kierunku wyznaczonym przez 'd', zaznaczaj�c zliczane pozycje.
            // Omijaj pola ju� odwiedzone.
            for (int i = 0; i < board.height(); ++i)
                  for (int j = 0; j < board.width(); ++j) {
                        Move m(j, i);
                        if (used_tiles[m.y*board.width() + m.x] == false) {
                              int line_length = 0;
                              while (insideBoard(m, board) && board.at(m.x, m.y) == tile) {
                                    used_tiles[m.y*board.width() + m.x] = true;
                                    ++line_length;
                                    m += d;
                              }
                              if (line_length > 1) {
                                    *out = line_length;
                                    ++out;
                              }
                        }
                  }
      }

}

// Zlicz wszystkie linie utworzone przez gracza 'player'
template <typename OutputIter>
void findLines(const GameBoard& board, playerT player, OutputIter it)
{
      tileT tile = tileOfPlayer(player);
      for (int i = 0; i < 4; ++i)
            findLineInDirection(board, tile, directions[i], it);
}

}

#endif

