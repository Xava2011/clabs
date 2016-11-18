17.X.2003

NIM

int FindGoodMove(int nCoins) {
   for (ka�dego mo�liwego ruchu) {
     Oblicz warto�� uk�adu po wykonaniu tego ruchu.
     Je�li pozycja jest z�a (prowadzi do przegranej),
        to wykonaj ten ruch.
   }
   Zwr�� NoGoodMove wskazuj�c w ten spos�b, 
   �e nie ma dobrego ruchu.
}

gdzie, np. NoGoodMove==-1.

int FindGoodMove(int nCoins) {
   int nTaken;
   for (nTaken=1; nTaken<=MaxTake; nTaken++) {
      if (isBadPosition(nCoins-nTaken))
         return nTaken;
   }
   return NoGoodMove;
}

bool IsBadPosition(int nCoins) {
   if (nCoins==1) return TRUE;
   return (FindGoodMove(nCoins)==NoGoodMove);  
}
