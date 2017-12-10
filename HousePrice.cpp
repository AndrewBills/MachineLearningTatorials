// File: HousePrice
// Created by Hugo Valle on 11/22/2017.
// Copyright (c) 2017 WSU
//

#include "HousePrice.h"
HousePrice::HousePrice ()
{
    id = 0;
    number = 0;
    street = "";
    city = "";
    state = "";
    postalCode = 0;
    price = 0.0;
}
HousePrice::HousePrice(int id, int number, const string &street, const string &city, const string &state, int postalCode, double price)
{
    HousePrice::id = id;
    HousePrice::number = number;
    HousePrice::street = street;
    HousePrice::city = city;
    HousePrice::state = state;
    HousePrice::postalCode = postalCode;
    HousePrice::price = price;
}
double HousePrice::getPrice () const
{
    return price;
}
const string & HousePrice::getState () const
{
    return state;
}
ostream & operator<< (ostream &os, const HousePrice &price)
{
    os << "id: " << price.id << " number: " << price.number << " postalCode: " << price.postalCode << " street: " << price.street << " city: " << price.city << " price: " << price.price << endl;
    return os;
}

