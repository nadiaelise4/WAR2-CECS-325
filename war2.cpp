/*Nadia Suha
CECS 325
Prog 1 - War
2/14/24
I certify that this program is my own original work. I did not copy any part of this program from any other source. I further certify thay I typed each and every line of code in this program*/
#include <iostream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

class Card 
{
    private:
        char rank, suit;
        
    public:
        Card();
        Card(char, char);
        void display();
        int compare(Card);
};
Card::Card(char s, char r)
{
    rank = r;
    suit = s;
}

void Card::display()
{
    if (rank == 'T')
    {
        cout << "10" << suit;
    }
    else 
    {
        cout << rank << suit;
    }
}
int Card::compare(Card other)
{
    int card_rank1;
    int card_rank2;
    char ranks[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    
        for (int i = 0; i<13;i++)
      {
        if (rank == ranks[i]) 
            {
            card_rank1 = i;
            }
        if (other.rank == ranks[i])
        {
        card_rank2 = i;
        }
      }
        if (card_rank1 > card_rank2)
        {
        return 1;  //play1 wins
        }
        else if (card_rank1 < card_rank2) 
        {
        return -1; //play2 wins
        }
        else 
        {
        return 0;  //tie
        }
};
class Deck
{ 
    private:
        vector<Card> deck;
    public:
        Deck();
        Card deal();
        void shuffle();
        void display();
        bool isEmpty();
};

Deck::Deck()
{ 
        char rank[] {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
        char suit[] {'H', 'D', 'C', 'S'};

        for (int i = 0; i<4;i++)
        {
            for (int j = 0; j < 13; j++)
            {
                deck.push_back(Card(suit[i], rank[j]));
            }
            
        }
    }

void Deck::display()
{
    for (size_t i=1; i<deck.size()+1;++i)
    {
        deck[i-1].Card::display();
        if (i%13 !=0)
        {
            cout << ',';
        }
        else
        {
            cout << "\n";
        }
    }
    
}

void Deck::shuffle()
{
    srand(time(0));
    for (int i = deck.size() - 1; i >0; --i)
    {
        int j = rand() % (i+1);
        Card trial = deck[i];
        deck[i] = deck[j];
        deck[j] = trial;
    }
}

Card Deck::deal()
{
    Card trial = deck.back();
    deck.pop_back();
    return trial;
};
    

int main()
{
    string play1, play2;
    cout << "Enter the name of the first player: ";
    cin >> play1;
    cout << "Enter the name of the second player: ";
    cin >> play2;
    
    cout << "\n\n";
    cout << "Original Deck \n";
    Deck deck;
    deck.display();

    cout <<"\n\n";
    cout << "Shuffled Deck \n";
    deck.shuffle();
    deck.display();

    int result = 0, wins = 0, losses = 0, ties = 0;

    for(size_t gameNum = 1; gameNum <27; ++gameNum)
    {
        Card card_rank1 = deck.deal();
        Card card_rank2 = deck.deal();

        cout << " Game "<<gameNum << "\n"<< "--------\n";
        cout << "\t" << play1 << "=>";
        card_rank1.display();
        cout << "\n\t" << play2 << "=>";
        card_rank2.display();
        cout << "\n";
        result = card_rank1.compare(card_rank2);

        if (result == 1)
        {
            cout << play1 << "=> Winner"<< endl;
            ++wins;
        }
        else if (result == -1)
        {
            cout << play2 << "=> Winner" << endl;
            ++ losses;
        }
        else
        {
            cout << "Tie Game" << endl;
            ++ties;
        }
        cout << "\n";
    }
    cout << "-------Final Stats-------\n";
    cout << "\t" << play1 << " vs. " << play2 << "\n";
    cout << "Wins \t" << wins << "\t" << losses << "\n";
    cout << "Losses " << losses << "\t" << wins << "\n";
    cout << "Ties \t" << ties << "\t" << ties << endl;
    return 0;
}