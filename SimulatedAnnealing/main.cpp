//
//  main.cpp
//  you_are_looser
//
//  Created by Ваня Ткаченко on 12/11/15.
//  Copyright © 2015 Stead. All rights reserved.
//

#include "methods.hpp"

int main()
{
    srand(time(NULL)); //for correct working 'rand'-function
    
    int sizeOfBoard;
    
    cout << "Enter the size of the chess board : "; cin >> sizeOfBoard;
    
    ChessBoard& DemoChessBoard = *(new ChessBoard(sizeOfBoard));
    DemoChessBoard.DrawBoard();
    DemoChessBoard.Solution();
    
    delete &DemoChessBoard;
    return 0;
}