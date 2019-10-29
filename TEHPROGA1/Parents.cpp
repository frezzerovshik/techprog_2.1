//
//  Parents.cpp
//  TEHPROGA1
//
//  Created by Артем Шарапов on 12/10/2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#include "Parents.hpp"

Parents::Parents(){

     cout<<"Constructor called, class Parents"<<endl;
    type.append("0");
}
Parents::Parents(string _fio, string _parents,string _spouse,string _kids,string _birth,string _death,string _age,string _type){
    cout<<"Constructor called, class Parents"<<endl;
    setFio(_fio);
    setParents(_parents);
    setSpouse(_spouse);
    setKids(_kids);
    setBirth(_birth);
    setDeath(_death);
    setAge(_age);
    if(_type.compare("Parents") || _type.compare("parents")){
        type = _type;
    }
    else{
        throw MyException.false_id_exc();
    }
}
Parents::Parents( Parents& init){
 cout<<"Constructor called, class Parents"<<endl;
    setFio(*init.getFio());
    setParents(*init.getParents());
    setSpouse(*init.getSpouse());
    setKids(*init.getKids());
    setBirth(*init.getBirth());
    setDeath(*init.getDeath());
    setAge(*init.getAge());
    if(init.getType().compare("Parents") || init.getType().compare("parents")){
        type = init.getType();
    }
    else{
        throw MyException.false_id_exc();
    }
}
Parents::~Parents(){

   cout<<"Destructor called, class Parents"<<endl;
}

