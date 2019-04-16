#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//Card Values
//2,3,4,5,6,7,8,9,10, J = 10, Q = 10, K = 10, A = 1 || 11

//Print Card that was drawn
void PrintCard(int num, int &AceCounter){
  if(num == 2)
    cout << "A 2 was drawn" << endl;
  if(num == 3)
    cout << "A 3 was drawn" << endl;
  if(num == 4)
    cout << "A 4 was drawn" << endl;
  if(num == 5)
    cout << "A 5 was drawn" << endl;
  if(num == 6)
    cout << "A 6 was drawn" << endl;
  if(num == 7)
    cout << "A 7 was drawn" << endl;
  if(num == 8)
    cout << "An 8 was drawn" << endl;
  if(num == 9)
    cout << "A 9 was drawn" << endl;
  if(num == 10){
    srand(time(NULL));
    int minnew = 1;
    int maxnew = 3;
    int numnew (minnew + (rand() % (int)(maxnew - minnew + 1)));
    if(numnew == 1)
      cout << "A Jack was drawn" << endl;
    if(numnew == 2)
      cout << "A Queen was drawn" << endl;
    if(numnew == 3)
      cout << "A King was drawn" << endl;
  }
  if(num == 11){
    cout << "An Ace was drawn" << endl;
    AceCounter++;
  }
}

//Give the player a card
int AddCard(int Value,int &AceCounter){
  srand(time(NULL));
  int min = 2;
  int max = 11;
  int num = (min + rand() % (int)(max-min+1));
  PrintCard(num, AceCounter);
  Value = Value + num;
  return Value;
}

//Main Function
int main(){
  cout << "Welcome to Black Jack" << endl;
  cout << "Program Developed By: Alexander Bix" << endl;
  int PlayerValue = 0;
  int AceCounter = 0;
  string YesOrNo, PlayAgain = "y";

  //Gambling
  int Money = 100;
  int Bet;
  cout << "You currently have $" << Money << endl;
  cout << "How much do you want to bet: ";
  cin >> Bet;
  while(Bet > Money || Bet <= 0){
    cout << "You can't bet that amount " << endl;
    cout << "How much do you want to bet: ";
    cin >> Bet;
  }


  while(PlayAgain == "y"){

    if(Money <= 0){
      cout << "You don't have any more money!" << endl;
      return 0;
    }

    while(PlayerValue <= 21){
      cout << "Your total is currently: " << PlayerValue << endl;
      cout << "Would you like to draw a card [enter to continue, n to stop] :";
      getline(cin,YesOrNo);
      cout << endl;

      //Player doesn't want any more cards
      if(YesOrNo == "n")
        break;

      PlayerValue = AddCard(PlayerValue, AceCounter);

      //When value goes above 21 but player has an ace
      if(AceCounter > 0 && PlayerValue > 21){
        PlayerValue = PlayerValue - 10;
        AceCounter--;
      }

    }

    cout << "Your final total is: " << PlayerValue << endl;

    //Losing for going above 21
    if(PlayerValue > 21){
      cout << "You lost due to going above 21" << endl;
      Money = Money - Bet;
    }

    else{
      //Calculate value of dealer
      srand(time(NULL));
      int DealerMin = 14;
      int DealerMax = 21;
      int Dealer = (DealerMin + rand() % (int)(DealerMax-DealerMin+1));
      cout << "The dealer's card value is: " << Dealer << endl;

      //Determine if player value is better than Dealer
      if(PlayerValue > Dealer){
        cout << "You win due to having a larger card value" << endl;
        Money = Money + Bet;
      }

      else if(PlayerValue == Dealer){
        cout << "It is a tie due to both parties having the card value" << endl;
      }

      else{
        cout << "You lose due to having a lower card value than the dealer" << endl;
        Money = Money - Bet;
      }

    }

    cout << "Would you like to play again [y/n]: ";
    cin >> PlayAgain;

    //Gambling
    if(PlayAgain == "y" && Money > 0){
      cout << "You currently have $" << Money << endl;
      cout << "How much do you want to bet: ";
      cin >> Bet;
      while(Bet > Money || Bet <= 0){
        cout << "You can't bet that amount " << endl;
        cout << "How much do you want to bet: ";
        cin >> Bet;
      }
    }

    cout << endl;
    PlayerValue = 0;
    AceCounter = 0;
    system("clear");
  }
  return 0;
}