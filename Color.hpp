#pragma once
#include<iostream>

enum Color{
    
    Black,
    Blue,
    Red,
    Yellow
};

inline const char* ToString(Color n){

    switch(n){
        case Black:
            return "Black";
        case Blue:
            return "Blue";
        case Red:
            return "Red";
        case Yellow:
            return "Yellow";
        default:
            return "no color";
    }
};

