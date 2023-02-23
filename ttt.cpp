#include <iostream>
#include <vector>
#include <conio.h>
#include "ttt.h"

int main() {
  int p1, p2;
  std::vector<int> mainboard = {0,0,0,0,0,0,0,0,0};
  greet();
  displayBoard(mainboard);
  bool winStatus = false;
  int turns = 0;
  
  while (winStatus == false && turns < 9) {
    std::cout << "P1: ";
    std::cin >> p1;
    mainboard = p1Turn(p1, mainboard);
    displayBoard(mainboard);
    winStatus = checkBoard(mainboard);
    turns++;
    if (winStatus == true || turns == 9) { break; }
    std::cout << "P2: ";
    std::cin >> p2;
    mainboard = p2Turn(p2, mainboard);
    displayBoard(mainboard);
    winStatus = checkBoard(mainboard);
    turns++;
  }

  std::cout << "Game Over.\n";
  getch();

  return 0;
}