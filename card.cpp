#include <iostream>
#include <string>
#include <cstdlib>

#include "card.h"


using namespace std;

Card::Card()
{
    myRank = 'A';
    mySuit = spades;

}

Card::Card(int rank, Suit s)
{
    myRank = rank;
    mySuit = s;
}

string Card::toString() const
{
    return rankString(myRank) + suitString(mySuit);
}

bool Card::sameSuitAs(const Card &c) const
{
    return(suitString(mySuit) == suitString(c.mySuit));
}

int Card::getRank() const
{
    return myRank;
}

string Card::suitString(Card::Suit s) const
{
    string ans = "";
    if(s == spades){
        ans = "s";
    }
    if(s == hearts){
        ans = "h";
    }
    if(s == diamonds){
        ans = "d";
    }
    if(s == clubs){
        ans = "c";
    }
    return ans;
}

string Card::rankString(int r) const
{
    string ans = "";
    if(r == 1){
        ans = "A";
    }
    if(r == 2){
        ans = "2";
    }
    if(r == 3){
        ans = "3";
    }
    if(r == 4){
        ans = "4";
    }
    if(r == 5){
        ans = "5";
    }
    if(r == 6){
        ans = "6";
    }
    if(r == 7){
        ans = "7";
    }
    if(r == 8){
        ans = "8";
    }
    if(r == 9){
        ans = "9";
    }
    if(r == 10){
        ans = "10";
    }
    if(r == 11){
        ans = "J";
    }
    if(r == 12){
        ans = "Q";
    }
    if(r == 13){
        ans = "K";
    }
    return ans;
}

bool Card::operator==(const Card &rhs) const
{
    return((getRank() == rhs.getRank()));
}

bool Card::operator!=(const Card &rhs) const
{
    return((getRank() != rhs.getRank()));

}

ostream& operator << (ostream& out, const Card& c)
{
    out << c.toString() << endl;
}

