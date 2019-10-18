//
//  Exception.hpp
//  TEHPROGA1
//
//  Created by Артем Шарапов on 12/10/2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#pragma once
#include <iostream>
using namespace std;
class Exception{
public:
    Exception(){};
    int false_id_exc(){
        cout<<"Exception: false id"<<endl;
        throw 1;
    }
    int out_of_bounds_ecx(){
        cout<<"Exception: out of bounds"<<endl;
        throw 2;
    }
    int no_comparable_size_ecx(){
        cout<<"Cannot make a copy with this sizes of arrays"<<endl;
        throw 3;
    }
};
