#include <iostream>
#include <vector>
#include "HousePrice.h"
#include "HouseFunc.h"
using namespace std;

/*!
 * Main Function
 * @return 0 no error, error otherwise
 */
int main(int argc, char*argv[])
{
	// Part I
	HousePrice test(2, 123, "Weber St", "Ogden", "UT", 84408, 257000.00);
	cout << test << endl;

	// Part II
	vector<HousePrice> hp;
	readCSV("../MOCK_DATA.csv",hp);

	// Part III
	cout<<"This is your House Analysis"<<endl;
	houseMarketValues(hp);
//
	// Part IV
	houseMarketPerState(hp);

    return 0;
}
