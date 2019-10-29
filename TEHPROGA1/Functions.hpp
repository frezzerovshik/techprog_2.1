//
//  Functions.hpp
//  TEHPROGA1
//
//  Created by Артем Шарапов on 18/10/2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#pragma once
#include "Keeper.hpp"

typedef struct TEMP_DATA{
    string fio;
    string parents;
    string spouse;
    string kids;
    string birth;
    string death;
    string age;
}TEMP_DATA;
TEMP_DATA* getDataFromKeyboard();
int getTypeWithTempStruct(TEMP_DATA var);
int runtime();
void printKeeper(Keeper& a);
