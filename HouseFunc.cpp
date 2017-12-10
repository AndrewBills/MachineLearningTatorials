// File: HouseFunc
// Created by Hugo Valle on 11/22/2017.
// Copyright (c) 2017 WSU

#include <iostream>
#include <vector>
#include <map>
#include "HouseFunc.h"
#include "HousePrice.h"
#include "csv.h" // library to read csv files
#include <algorithm>
#include <fstream>
#include <string.h>
#define strcasecmp _stricmp
#include <cstring>
using namespace std;

/*!
 * Read CSV Mock Data. Parses each record in the file to
 * an object of HousePrice house. Then, populate a vector
 * of HousePrice objects with all the records.
 * It uses special library to parse CSV file "csv.h"
 * @param fileIn File name <string>
 * @param hp Reference to Vector of HousePrice Objects
 */
void readCSV(const string fileIn,vector<HousePrice>& hp)
{
    int id, postalCode, number;
    string street, city, state;
    double price;
    io::CSVReader<7> in(fileIn);
    in.read_header(io::ignore_extra_column, "id", "number", "street", "city","state","postalCode", "price");
    ///the next line builds the vector array of all of all 1000 houses
    while(in.read_row(id, number, street, city, state, postalCode, price))
    {
        HousePrice temp(id, number, street, city, state, postalCode, price);
        hp.push_back(temp);
    }
    ///prints out all 1000 houses
    for(int i=0; i<1000; i++)
        cout << hp[i];
    cout << endl;
}


/*!
 * Sort the Vector of HousePrice Objects by price. Display the most affordable
 * and the most expensive house from the vector.
 * @param hp Reference to vector<HousePrice>
 */
void houseMarketValues(vector<HousePrice> &hp)
{
    ///reorders the houses according to price from least to greatest
    for(int i=0;i<1000;i++)
        for (int j=0; j<1000;j++)
			if(hp[j].getPrice()<hp[i].getPrice())
				swap(hp[i], hp[j]);
    ///prints out the most affordable home
    cout << "The most affordable home: ";
    for(int i=0; i<1000; i++)
        if(hp[999].getPrice() == hp[i].getPrice())
			cout << hp[i];
    ///prints out the most expansive home
    cout << "The most expansive home: ";
    for(int i=0; i<1000; i++)
		if(hp[0].getPrice() == hp[i].getPrice())
			cout << hp[i];
    cout << endl;
}
/*!
 * Sort the Vector of HousePrice Objects by state. Display the
 * number of houses per state.
 * It uses a map to count instances per state.
 * @param hp Reference to vector<HousePrice>
 */
void houseMarketPerState(vector<HousePrice> &hp)
{
    string statesString[50] = {{"AK"}, {"AL"}, {"AR"}, {"AZ"}, {"CA"}, {"CO"}, {"CT"}, {"DE"}, {"FL"}, {"GA"},
                               {"HI"}, {"IA"}, {"ID"}, {"IL"}, {"IN"}, {"KS"}, {"KY"}, {"LA"}, {"MA"}, {"MD"},
                               {"ME"}, {"MI"}, {"MN"}, {"MO"}, {"MS"}, {"MT"}, {"NC"}, {"ND"}, {"NE"}, {"NH"},
                               {"NJ"}, {"NM"}, {"NV"}, {"NY"}, {"OH"}, {"OK"}, {"OR"}, {"PA"}, {"RI"}, {"SC"},
                               {"SD"}, {"TN"}, {"TX"}, {"UT"}, {"VA"}, {"VT"}, {"WA"}, {"WI"}, {"WV"}, {"WY"}};
    ///fills a new vector will all 1000 states
    vector<string> stringarray;
    for (int i = 0; i < 1000; i++)
        stringarray.push_back(hp[i].getState());
    ///sorts the states in alphabetical order
    sort(stringarray.begin(), stringarray.end());
    cout << "Home per state:" << endl;
    ///counts all the amount of each state and prints them out in matrix form
    for(int i=0, n = 0; i<50; i++)
    {
        /// this if statement stops any states with 0 houses for sale from showing up on the console
        if(count(stringarray.begin(), stringarray.end(), statesString[i])!=0)
        {
            cout << " " << statesString[i] << " ";
            if(count(stringarray.begin(), stringarray.end(), statesString[i])<100) cout << " ";
            if(count(stringarray.begin(), stringarray.end(), statesString[i])<10) cout << " ";
            cout << count(stringarray.begin(), stringarray.end(), statesString[i]) << " ";
            if ((n+1)%10==0) cout << endl;
            n++;
        }

    }
}
