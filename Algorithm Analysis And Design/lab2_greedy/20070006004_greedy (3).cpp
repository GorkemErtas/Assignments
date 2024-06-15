/*Görkem Ertaþ 20070006004 */
#include <iostream>

using namespace std;

#define MARKET1 true
#define MARKET2 false
#define ITEM_COUNT 5

int market1Prices[] = {5, 7, 12, 3, 4};
int market2Prices[] = {8, 4, 9, 9, 6};
bool markets[ITEM_COUNT];
int market1Point = 10;
int market2Point = 14;

int buyItems() {
    int moneySpent = 0;
    int market1Points = market1Point;
    int market2Points = market2Point;

    for (int i = 0; i < ITEM_COUNT; i++) {
        int market1Price = market1Prices[i];
        int market2Price = market2Prices[i];

        int discountedMarket1Price = market1Price - market1Points;
        int discountedMarket2Price = market2Price - market2Points;
        
        if (discountedMarket1Price < 0) {
        	discountedMarket1Price = 0;
		}
		
		if (discountedMarket2Price < 0) {
        	discountedMarket2Price = 0;
		}

        if (discountedMarket1Price < discountedMarket2Price) {
        	
            markets[i] = MARKET1;
            moneySpent += discountedMarket1Price;
            market1Points -= (market1Price - discountedMarket1Price);
            
        } else if (discountedMarket1Price > discountedMarket2Price) {
        	
            markets[i] = MARKET2;
            moneySpent += discountedMarket2Price;
            market2Points -= (market2Price - discountedMarket2Price);
            
        } else if (discountedMarket1Price == discountedMarket2Price) {
        	
        	if (market1Prices[i] <= market2Prices[i]) {
        		markets[i] = MARKET1;
            	moneySpent += discountedMarket1Price;
            	market1Points -= (market1Price - discountedMarket1Price);
            	
			} else {
				
				markets[i] = MARKET2;
            	moneySpent += discountedMarket2Price;
            	market2Points -= (market2Price - discountedMarket2Price);
            	
			}
		}
    }
	cout << "After shopping: " << endl;
	cout << "Market 1 points: " << market1Points << endl;
	cout << "Market 2 points: " << market2Points << endl;
    return moneySpent;
}

void printMarkets() {
    for (int i = 0; i < ITEM_COUNT; i++) {
        if (markets[i] == MARKET1) {
            cout << "MARKET1, ";
        } else {
            cout << "MARKET2, ";
        }
    }
    cout << endl;
}

int main() {
	cout << "Before shopping: " << endl;
	cout << "Market 1 points: " << market1Point << endl;
	cout << "Market 2 points: " << market2Point << endl;
    int moneySpent = buyItems();
    printMarkets();
	cout << "Money spent: " << moneySpent << " TL" << endl;
	return 0;
}
