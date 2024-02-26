//
//  main.cpp
//  nTacToe
//
//  Created by Nooruddin Mohammadi on 2/25/24.
//
//This is new comment
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int N = 10;
void initBoard(char board[N][N], int n);
void printBoard(char board[N][N], int n);
bool isGameOver(char board[N][N], int n);
void getPlayerInput(char board[N][N], int n, char playerChar);

int main() {
    char playerChar = 'X';
    char board[N][N];
    int n;
    
    do {
        cout << "How big do you want the board?" << endl;
        cin >> n;
    } while (n < 3 || n > N);
    
    initBoard(board, n);
    printBoard(board, n);
    while (!isGameOver(board, n))
    {
        getPlayerInput(board, n, playerChar);
        printBoard(board, n);
        
        if (playerChar == 'X') {
            playerChar = 'O';
        }
        else
        {
            playerChar = 'X';
        }
    }
    return 0;
}

void initBoard(char board[N][N], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            board[i][j] = '-';
        }
    }
}

void printBoard(char board[N][N], int n)
{
    cout << "  ";
    for (int j = 0; j < n; ++j)
    {
        cout << j << " ";
    }
    cout << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << i << " ";
        for(int j = 0; j < n; ++j)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
bool isColWin(char board[N][N], int n)
{
    int countX;
    int countO;
    for (int i = 0; i < n; ++i)
    {
        countO = 0;
        countX = 0;
        for (int j = 0; j < n; ++j)
        {
            if(board[i][j] == 'X')
            {
                ++countX;
            }
            if (board[i][j] == 'O') {
                ++countO;
            }
        }
        if (countX == n) {
            cout << "Player (X) won!" << endl;
            return true;
            break;
        }
        if (countO == n) {
            cout << "Player (O) won!" << endl;
            return true;
            break;
        }
        
    }
    return  false;
}

bool isRowWin(char board[N][N], int n)
{
    int countX;
    int countO;
    for (int j = 0; j < n; ++j)
    {
        countO = 0;
        countX = 0;
        for (int i = 0; i < n; ++i)
        {
            if(board[i][j] == 'X')
            {
                ++countX;
            }
            if (board[i][j] == 'O') {
                ++countO;
            }
        }
        if (countX == n) {
            cout << "Player (X) won!" << endl;
            return true;
            break;
        }
        if (countO == n) {
            cout << "Player (O) won!" << endl;
            return true;
            break;
        }
        
    }
    return false;
}

bool isDiagWin(char board[N][N], int n)
{
    for (int i = 0; i < n; ++i)
    {
        int countFDO = 0;
        int countBDX = 0;
        int countFDX = 0;
        int countBDO = 0;
        
        
        if(board[i][i] == 'X')
        {
            ++countFDX;
        }
        if (board[i][i] == 'O') {
            ++countFDO;
        }
        
        if(board[i][n-1-i] == 'X')
        {
            ++countBDX;
        }
        if (board[i][n-1-i] == 'O') {
            ++countBDO;
        }
        
        if (countFDX == n || countBDX == n) {
            cout << "Player (X) won!" << endl;
            return true;
            break;
        }
        if (countFDO == n || countBDO == n) {
            cout << "Player (O) won!" << endl;
            return true;
            break;
        }
        
    }
    return false;
}

bool isTie(char board[N][N], int n)
{
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 0; ++j)
        {
            if (board[i][j] == '-')
            {
                count++;
            }
        }
    }
    if (count == n*n) {
        cout << "The game is tied!" << endl;
        return true;
    }
    return false;
}

bool isGameOver(char board[N][N], int n)
{
    
    if (isColWin(board, n))
    {
        return  true;
    }
    else if (isRowWin(board, n))
    {
        return true;
    }
    else if(isDiagWin(board, n))
    {
        return true;
    }
    else if(isTie(board, n))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void getPlayerInput(char board[N][N], int n, char playerChar)
{
    int row, col;
    do {
        
        do
        {
            cout << "Please enter the row number: " << endl;
            cin >> row;
        }
        while (row > n);
        
        do
        {
            cout << "Please enter the column number: " << endl;
            cin >> col;
        }
        while (col > n);
    }
    while (board[row][col] != '-');
    board[row][col] = playerChar;
}

