//
//  methods.hpp
//  you_are_looser
//
//  Created by Ваня Ткаченко on 12/11/15.
//  Copyright © 2015 Stead. All rights reserved.
//

#ifndef methods_hpp
#define methods_hpp

#include <iostream>
#include <time.h>
#include <math.h>
//#include <Windows.h>
#include <fstream>
#include <string>

//for chess_board;
const double FINAL_TEMPERATURE = 0.05;
const double decr = 0.85;
const int n_iter = 50;

using namespace std;

class ChessBoard
{
private:
    int* figures;
    int aproxEnergy;
    int boardWidth;
    
public:
    /*changing position of two elements will be appliance in the finding needed  figures` replacement
     with using extra variable*/
    void ChangeFigures(int &, int &);
    /*constructor with one parameter 'width' for initialization our chess board`s quantity.
     initialization figure array and figure placing arrisways*/
    ChessBoard(int);
    //Destructor with deleting figure array after finishing work with our chess board
    ~ChessBoard();
    /*drawing the chess table with needed figures for visual demonstration finded solution
     after using of simulated annealing algorithm*/
    void DrawBoard();
    /*returns the number of errors for every figure (searching another figures in every figure`s arrisway)*/
    int ErrorsNumber();
    /*realization of simulated annealing algorithm with two parametres double& - first temeparature`s value
     and int - number of iterations for searching solution for each step of changing the temperature*/
    void Solution();
};

#endif /* methods_hpp */
