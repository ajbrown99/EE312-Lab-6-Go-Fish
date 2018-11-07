#include <iostream>
#include <cstdlib>
#include <string>
#include "card.h"
#include "deck.h"

Deck::Deck()
{
    myIndex = 0;


    int myCardsIndex = 0;

    for (int i = 0; i < 13; i ++)
    {
        myCards [myCardsIndex] = Card ((i+1), Card::spades);
        myCardsIndex ++;
        myCards [myCardsIndex] = Card ((i +1), Card::hearts);
        myCardsIndex++;
        myCards [myCardsIndex] = Card ((i + 1), Card::diamonds);
        myCardsIndex++;
        myCards [myCardsIndex] = Card ((i + 1), Card:: clubs);
        myCardsIndex++;

    }

    /*

    for(int i = 1; i < 14; i++){

        myCards[i-1] = Card(i,Card::spades);
    }
    for(int i = 14; i < 28; i++){

        myCards[i-1] = Card(i % 14,Card::hearts);
    }
    for(int i = 28; i < 42; i++){

        myCards[i-1] = Card(i % 14,Card::diamonds);
    }
    for(int i = 42; i < 53; i++){

        myCards[i-1] = Card(i % 14,Card::clubs);
    }
     */
}

void Deck::shuffle()
{
    int totalCards = size();

    if(totalCards == 0 || totalCards == 1)
    {
        return;
    }

    srand((unsigned)time(0));

    int shuffleLoop = 0;
    for(shuffleLoop = 0; shuffleLoop < totalCards; shuffleLoop++)
    {
        int rand1 = 0;
        int rand2 = 0;

        while(rand1 == rand2)
        {
            rand1 = rand() % totalCards;
            rand2 = rand() % totalCards;
        }
        Card temp = myCards[rand1];
        myCards[rand1] = myCards[rand2];
        myCards[rand2] = temp;
    }



}

Card Deck::dealCard()
{
    if(myIndex < 52){

        Card currentCard = myCards[myIndex];
        myIndex++;
        return currentCard;

    }

}

int Deck::size() const
{
    return SIZE - myIndex;
}

