#ifndef _MINIMAX_BENCHMARKER_H
#define _MINIMAX_BENCHMARKER_H

#include <vector>
#include <random>
#include <time.h>
#include <iostream>
#include <stdio.h>
#include <chrono>
#include <cassert>
#include "TicTacToeMinimax.h"

using namespace std;

class MinimaxBenchmarker
{
    public:
        void benchmarkMinimaxVsMinimax(TicTacToeMinimax* ticTacToeMinimax, int board, bool isMaxTurn);
        void benchmarkEvaluate(TicTacToeMinimax* ticTacToeMinimax, int board, bool isMaxTurn);
        void benchmarkEvaluateAll(TicTacToeMinimax* ticTacToeMinimax, int board, bool isMaxTurn);
        void printBoard(int board);
        void printState(int state);
};
#endif