#include <iostream>
#include <vector>

void displayBoard(std::vector<int> board) {
  for(int i = 0; i < board.size(); i++) {
    if(i % 3 == 0 && i != 0) { std::cout << std::endl; }
    switch (board[i]) {
      case 1: std::cout << 'O'; break;
      case 2: std::cout << 'X'; break;
      default: std::cout << '#'; break;
    }
  }
  std::cout << std::endl;
}

void greet() {
  std::cout << "A simple game of Tic-Tac-Toe." << std::endl;
  std::cout << "Enter a number (1-9) to make a move." << std::endl;
}

bool checkBoard(std::vector<int> board) {
  for(int i = 0; i < 3; i++) {
    if(board[i]==1 && board[i+3]==1 && board[i+6]==1) { std::cout << "P1 wins!\n"; return true; }
  }

  for(int i = 0; i < 9; i+=3) {
    if(board[i]==1 && board[i+1]==1 && board[i+2]==1) { std::cout << "P1 wins!\n"; return true; }
  }

  if(board[0]==1 && board[4]==1 && board[8]==1) { std::cout << "P1 wins!\n"; return true; }

  if(board[2]==1 && board[4]==1 && board[6]==1) { std::cout << "P1 wins!\n"; return true; }

  for(int i = 0; i < 3; i++) {
    if(board[i]==2 && board[i+3]==2 && board[i+6]==2) { std::cout << "P2 wins!\n"; return true; }
  }

  for(int i = 0; i < 9; i+=3) {
    if(board[i]==2 && board[i+1]==2 && board[i+2]==2) { std::cout << "P2 wins!\n"; return true; }
  }

  if(board[0]==2 && board[4]==2 && board[8]==2) { std::cout << "P2 wins!\n"; return true; }

  if(board[2]==2 && board[4]==2 && board[6]==2) { std::cout << "P2 wins!\n"; return true; }

  return false;
}

std::vector<int> p1Turn(int input, std::vector<int> board) {
  bool turncomplete = false;
  while (turncomplete == false) {
    if (board[input-1] == 1) { std::cout << "P1 already has an O there!\n"; std::cin >> input; } 
    else if (board[input-1] == 2) { std::cout << "P2 already has an X there!\n"; std::cin >> input; }
    else { board[input-1] = 1; turncomplete = true; }
  }

  return board;
}

std::vector<int> p2Turn(int input, std::vector<int> board) {
  bool turncomplete = false;
  while (turncomplete == false) {
    if (board[input-1] == 1) { std::cout << "P1 already has an O there!\n"; std::cin >> input; } 
    else if (board[input-1] == 2) { std::cout << "P2 already has an X there!\n"; std::cin >> input; }
    else { board[input-1] = 2; turncomplete = true; }
  }

  return board;
}