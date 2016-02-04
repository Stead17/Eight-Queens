//
//  methods.cpp
//  you_are_looser
//
//  Created by Ваня Ткаченко on 12/11/15.
//  Copyright © 2015 Stead. All rights reserved.
//

#include "methods.hpp"

using namespace std;

void ChessBoard::ChangeFigures(int &x, int &y)
{
    
    int temp = figures[x];
    figures[x] = figures[y];
    figures[y] = temp;
};
ChessBoard::ChessBoard(int width) : boardWidth(width)
{
    figures = new int[boardWidth];
    for (int i = 0; i < boardWidth; i++)
        figures[i] = i;
};
ChessBoard::~ChessBoard()
{
    delete[] figures;
}
void ChessBoard::DrawBoard()
{
    cout << "\n";
    for (int i = 0; i < boardWidth; i++)
    {
        for (int j = 0; j < boardWidth; j++)
        {
            if (j == figures[i]) cout << " " << 1 << " ";
            else
                cout << " 0 ";
        }
        cout << endl;
    }
};
int ChessBoard::ErrorsNumber()
{
    int conflNum = 0;
    for (int i = 0; i < boardWidth; i++)
    {
        for (int j = 0; j < boardWidth; j++)
        {
            if ((i != j) && (abs(i - j) == abs(figures[i] - figures[j])))
                conflNum++;
        }
    }
    return conflNum;
};

void ChessBoard::Solution()
{
    double t0 = 50;
    int resSolution = ErrorsNumber();
    
    while (t0 > FINAL_TEMPERATURE)
    {
        for (int i = 0; i < n_iter; i++)
        {
            int y, x = rand() % boardWidth;
            do {
                y = rand() % boardWidth;
            } while (x == y);
            
            ChangeFigures(x, y);
            
            int workSolution = ErrorsNumber();
            double delta = workSolution - resSolution;
            
            if (delta > 0)
            {
                double P = exp((-delta) / t0);
                double randNumber = ((double)(rand())) / (RAND_MAX + 1);
                
                if (P < randNumber)
                    ChangeFigures(x, y);
                else
                    resSolution = workSolution;
            }
            else
                resSolution = workSolution;
            
        }
        
        if (resSolution == 0) break;
        
        t0 *= decr;
    }
    
    this->DrawBoard();
    cout << "\nErrors = " << resSolution << "\n";
};