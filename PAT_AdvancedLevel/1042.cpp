#include <iostream>
using namespace std;

void shuffleCards(int* cardList, const int* order){
    int* newCardList = new int[55];
    for (int i = 1; i < 55; i++)
        newCardList[order[i]] = cardList[i];
    for (int i = 1; i < 55; i++)
        cardList[i] = newCardList[i];
    delete[] newCardList;
}

int main(){
    int K;
    cin >> K;
    int order[55];
    int cards[55];
    char cardKind[] = "SHCDJ";
    for (int i = 1; i < 55; i++){
        cin >> order[i];
        cards[i] = i;
    }
    for (int i = 0; i < K; i++)
        shuffleCards(cards, order);
    for (int i = 1; i < 55; i++){
        cards[i] -= 1;
        if(i > 1)
            cout << " ";
        cout << cardKind[cards[i] / 13] << (cards[i] % 13) + 1;
    }

    return 0;
}