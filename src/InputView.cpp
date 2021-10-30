#include "InputView.h"
#include <iostream>

unsigned int InputView::discardChoice(unsigned int handSize) {
  int cardValue;
  std::cout << "pick a card to discard from hand 1-" << handSize;
  std::cout << std::endl;
  std::cin >> cardValue;
  return cardValue;
}

unsigned int InputView::discardPile() {
  unsigned int pilenum;
  std::cout << "pick a discard pile (6-9)" << std::endl;
  std::cin >> pilenum;
  return pilenum;
}

void InputView::exitGame() {
  std::cout << "\n \nThanks for playing \nEnter any character to exit ";
  std::cout << "the game" << std::endl;
  char c;
  std::cin >> c;
  exit(EXIT_SUCCESS);
}

unsigned int InputView::options(unsigned int handSize) {
  unsigned int input;
  std::cout << "\n\nPick a option to play: \n 1-" << handSize;
  std::cout << " hand cards \n 6-9 discard pile \n 10 stock pile";
  std::cout << " \n 11 End turn \n 12 Help\n 13 Exit\n" << std::endl;
  std::cin >> input;
  return input;
}

unsigned int InputView::selectBuildPile() {
  unsigned int input;
  std::cout << "\npick a pile (1-4)" << std::endl;
  std::cin >> input;
  return input;
}
