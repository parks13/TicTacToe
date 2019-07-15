#include "tttmodel.h"
#include <iostream>

TTTModel::TTTModel()
{
    reset();
}

void TTTModel::reset()
{
    std::cout << "reset called" << std::endl;

    // Set the board clear
    boardStatus = "---------";
}

void TTTModel::put(int row, int col)
{
    std::cout << "put called with row " << row << " and col " << col << std::endl;

    // Determine the position of input for string
    int pos = (row * 3) + col;

    // Save the turn as a QChar
    QString XorY = getWhosTurn();
    QChar mark = XorY[0];

    // Put the mark in the pos
    boardStatus[pos] = mark;

}

QString TTTModel::getCurrentBoard() // something like "---XOXX--"
{
    return boardStatus;
}

QString TTTModel::getWhosTurn() // "X" or "O" or if somebody already won, return anything
{
    // X starts first, then O X O X O X. Done by counting the number of X or O or - characters
    if (boardStatus.count(QLatin1Char('-')) == 9)
        return "X";

    if (boardStatus.count(QLatin1Char('X')) > boardStatus.count(QLatin1Char('O')))
        return "O";

    if (boardStatus.count(QLatin1Char('X')) == boardStatus.count(QLatin1Char('O')))
        return "X";

    return "X";
}

bool TTTModel::hasSomeoneWon() // return if somebody has won
{
    // Check if there is a winner
    if (Winner("X") == "X" || Winner("O") == "O")
        return true;

    // Return false if no winner is found
    return false;
}

QString TTTModel::whosWinner() // return "X" or "O" if there's any winner. return anything if there's no winner yet
{
    if (Winner("X") == "X")
        return "X";

    if (Winner("O") == "O")
        return "O";

    return "nothing";
}

// A function to determine winner
QString TTTModel::Winner(QString player)
{
    if (boardStatus[0] == player)
    {
        if (boardStatus[1] == player)
        {
            if (boardStatus[2] == player)
                return player;
        }
        if (boardStatus[3] == player)
        {
            if (boardStatus[6] == player)
                return player;
        }
        if (boardStatus[4] == player)
        {
            if (boardStatus[8] == player)
                return player;
        }
    }
    if (boardStatus[1] == player)
    {
        if (boardStatus[4] == player)
        {
            if (boardStatus[7] == player)
                return player;
        }
    }
    if (boardStatus[2] == player)
    {
        if (boardStatus[4] == player)
        {
            if (boardStatus[6] == player)
                return player;
        }
        if (boardStatus[5] == player)
        {
            if (boardStatus[8] == player)
                return player;
        }
    }
    if (boardStatus[3] == player)
    {
        if (boardStatus[4] == player)
        {
            if (boardStatus[5] == player)
                return player;
        }
    }
    if (boardStatus[6] == player)
    {
        if (boardStatus[7] == player)
        {
            if (boardStatus[8] == player)
                return player;
        }
    }
    return "no winner";
}





















