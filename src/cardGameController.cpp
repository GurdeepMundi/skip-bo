
#include "cardGameController.h"
#include "Player.h"
#include "DeckModel.h"
#include "ArrPileModel.h"
#include "DisplayView.h"
#include "arrPileView.h"
#include <iostream>


CardGameController::CardGameController(InputView* iv) : userInput(iv) { }

CardGameController::~CardGameController() {
  delete userInput;
}

void CardGameController::gameStart() {
  Player* p1 = new Player;
  Player* p2 = new Player;
  DeckModel* deck = new DeckModel;
  ArrPileModel* building = new ArrPileModel;

  deckSetup(deck);
  playerSetup(p1, deck);
  playerSetup(p2, deck);
  help(12);
  do {
    playCards(p1, p2, deck, building);
    opponentTurn(p2, p1, deck, building);
  } while (p1->stocksize() != 0 || p2->stocksize() != 0);

  if (p1->stocksize() == 0) {
    std::cout << "Player 1 won" << std::endl;
  } else {
    std::cout << "Player 2 won" << std::endl;
  }
}

void CardGameController::deckSetup(DeckModel* deck) {
  deck->buildDeck();
  deck->shuffleDeck();
}

void CardGameController::playerSetup(Player* p, DeckModel* deck) {
  p->addToStock(deck);
}

void CardGameController::displayBoard(Player* p, Player* p2,
DeckModel* deck, ArrPileModel* build) {
  arrPileView a;
  std::cout << "\n    Oppenents Discard piles" << std::endl;
  //bool computer specifies whose discard pile is shown,
  //false for the player, true for computer
  p2->displayDiscard(true);
  std::cout << "\n         Build piles" << std::endl;
  //If pileType is 0 then the ArrPile is the players discard piles
  //If pileType is 1 then the ArrPile is the build piles
  //If pileType is 2 then the ArrPile is the opponents discard piles
  a.DisplayarrPileView(build, 1);
  std::cout << "\n       Discard piles" << std::endl;
  //bool computer specifies whose discard pile is shown,
  //false for the player, true for computer
  p->displayDiscard(false);
  p->displayStock();
  std::cout << " 10" << std::endl;
  std::cout << "\n         Hand" << std::endl;
  p->displayHand();
}

void CardGameController::opponentTurn(Player* p, Player* p2,
DeckModel* deck, ArrPileModel* build) {
  deck->checkSize();
  dealHand(p, deck);
  checkBuildSize(build, deck);
  std::cout << "\n\n************************ Opponent Turn " <<
  "********************* \n\n";
  std::cout << "\nPlaying Stock Cards \n\n";
  bool a = false;
  // plays stock
    CardModel* card = p->useStock();
    //picks one of the piles
  for (int i = 0; i < 4; i++) {
    a = addingToPiles(build, card, i);
    if (a == true) {
      p->deleteStockCard();
      a = false;
    }
  }

  std::cout << "\n\nPlaying Cards from Hand \n\n";
  //PLays cards from hand
  a = false;
  for (int i = 0; i < 4; i++) {
    card = p->useCard(i);
    //picks one of the piles
    a = addingToPiles(build, card, i);
    if (a == true) {
      p->removeCard(i);
    }
  }

  std::cout << "\n\nDiscarding Card into Discard Pile \n\n";
  //discards a card and ends turn
  card = p->useCard(0);
  discardPilesPick(p, card, 6);
  p->removeCard(0);

  std::cout << "\n\n************************ Player Turn " <<
  "********************* \n\n";
}

void CardGameController::playCards(Player* p, Player* p2,
DeckModel* deck, ArrPileModel* build) {
  bool gate = false;
  deck->checkSize();
  dealHand(p, deck);
  do {
    checkBuildSize(build, deck);
    displayBoard(p, p2, deck, build);
    int input = userInput->options(p->handsize());
    gate = discardingCard(p, input);
    handPlay(p, build, input);
    discardPlay(p, build, input);
    stockPlay(p, build, input);
    help(input);
    leave(input);
  } while (gate == false);
}

void CardGameController::dealHand(Player* p, DeckModel* deck) {
  for (int i = p->handsize(); i < 5; i++) {
    p->addCard(deck->getTopCard());
  }
}

void CardGameController::handPlay(Player* p, ArrPileModel* build, int input) {
  DisplayView display;

  int b = input - 1;
  if (input <= p->handsize() && input > 0) {
    input = input - 1;
    CardModel* card = p->useCard(input);
    //picks one of the piles
    int input2 = userInput->selectBuildPile();
    bool a = addingToPiles(build, card, input2);
    if (a == true) {
      p->removeCard(b);
    }
  }
}

void CardGameController::discardPlay(Player* p,
ArrPileModel* build, int input) {
  DisplayView display;
  if (input <= 9 && input >= 6) {
    bool a = false;
    int cardvalue = input - 6;
    CardModel* card = p->usediscard(cardvalue);
    //picks one of the piles
    if (card->getNumber() != 20) {
      int pilenum = userInput->selectBuildPile();
      a = addingToPiles(build, card, pilenum);
    }
    if (a == true) {
      p->deleteDiscardCard(cardvalue);
    }
  }
}

void CardGameController::stockPlay(Player* p, ArrPileModel* build, int input) {
  bool a = false;
  DisplayView display;
  if (input == 10) {
    CardModel* card = p->useStock();
    //picks one of the piles
    unsigned int pilenum = userInput->selectBuildPile();
    a = addingToPiles(build, card, pilenum);
  }
  if (a == true) {
    p->deleteStockCard();
  }
}

bool CardGameController::discardingCard(Player* p, int input) {
  if (input == 11) {
    if (p->handsize() == 0) {
      return true;
    } else {
      int cardvalue = userInput->discardChoice(p->handsize());
      if (cardvalue <= p->handsize() && cardvalue > 0) {
        int carddelete = cardvalue - 1;
        CardModel* card = p->useCard(carddelete);
        //picks one of the piles
        int pilenum = userInput->discardPile();
        discardPilesPick(p, card, pilenum);
        p->removeCard(carddelete);
        return true;
      }
    }
  }
  return false;
}

bool CardGameController::addingToPiles(ArrPileModel* build,
CardModel* card, int input) {
  bool gate = false;
  switch (input) {
    case 1:
      gate = build->insertCard(card, input);
      break;
    case 2:
      gate = build->insertCard(card, input);
      break;
    case 3:
      gate = build->insertCard(card, input);
      break;
    case 4:
      gate = build->insertCard(card, input);
      break;
    default:
      std::cout << "Wrong number for pile" << std::endl;
  }
  return gate;
}

void CardGameController::discardPilesPick(Player* p,
CardModel* card, int input) {
  switch (input) {
    case 6:
      p->usingDiscard(card, input-6);
      break;
    case 7:
      p->usingDiscard(card, input-6);
      break;
    case 8:
      p->usingDiscard(card, input-6);
      break;
    case 9:
      p->usingDiscard(card, input-6);
      break;
    default:
      std::cout << "Wrong number for pile" << std::endl;
  }
}

void CardGameController::checkBuildSize(ArrPileModel* build, DeckModel* deck) {
  build->checkBuildSize(deck);
}

void CardGameController::help(int input) {
    if (input == 12) {
        std::cout << "Skip-Bo Help:" << std::endl;
        std::cout << std::endl;
        std::cout << "Objective:" << std::endl;
        std::cout << "   Be the first player to play all the cards " <<
        "in your STOCK pile." << std::endl;
        std::cout << std::endl;
        std::cout << "CARDS:" << std::endl;
        std::cout << "   There are cards numbered from 1 through 12, " <<
        "and Skip-Bo cards." << std::endl;
        std::cout << "   Skip-Bo cards are denoted by an 'S'." << std::endl;
        std::cout << std::endl;
        std::cout << "How to use the various PILES:" << std::endl;
        std::cout << std::endl;
        std::cout << "STOCK pile:" << std::endl;
        std::cout << "   You will get rid of your stock pile by playing " <<
        "the top card, when you can, on the BUILD piles." << std::endl;
        std::cout << "   When you play the top card of your STOCK pile the " <<
        "next card will be revealed." << std::endl;
        std::cout << "   On your turn you may keep playing the top card as " <<
        "long as there are valid plays." << std::endl;
        std::cout << std::endl;
        std::cout << "DISCARD piles:" << std::endl;
        std::cout << "   There are 4 DISCARD piles available to you and " <<
        "4 available to your opponent." << std::endl;
        std::cout << "   At the start of the game, the DISCARD " <<
        "piles are empty." << std::endl;
        std::cout << "   To end your turn, you must discard any card " <<
        "from your hand onto any of your DISCARD piles." << std::endl;
        std::cout << "   The DISCARD piles do not have to be in " <<
        "sequential order." << std::endl;
        std::cout << "   On your turn you may play the top cards " <<
        "from any of your DISCARD piles onto the BUILD piles, " <<
        "if the play is valid" << std::endl;
        std::cout << std::endl;
        std::cout << "BUILD piles:" << std::endl;
        std::cout << "   There 4 BUILD piles available to you " <<
        "and your opponent." << std::endl;
        std::cout << "   At the start of the game, the BUILD " <<
        "piles are empty." << std::endl;
        std::cout << "   A 1 or a Skip-Bo card is required to begin " <<
        "any of the 4 BUILD piles." << std::endl;
        std::cout << "   Cards must be added to the BUILD piles " <<
        "sequentially." << std::endl;
        std::cout << "   Skip-Bo cards are wild and may be played " <<
        "at any time." << std::endl;
        std::cout << "   Once played Skip-Bo cards inherit the value of the " <<
        "card that would have been needed to make the play." << std::endl;
        std::cout << "   A BUILD pile is completed when a 12 is played onto " <<
        "it, it will be shuffled and re-used." << std::endl;
    }
}

void CardGameController::leave(int input) {
  if (input == 13) {
    userInput->exitGame();
  }
}
