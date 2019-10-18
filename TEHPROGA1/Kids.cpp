//
//  Kids.cpp
//  TEHPROGA1
//
//  Created by Артем Шарапов on 12/10/2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#include "Kids.hpp"

Kids::Kids(){
    cout<<"Constructor without parameters"<<endl;
    cout<<"Class Kids"<<endl;
    type.append("0");
}
Kids::Kids(string _fio, string _parents,string _spouse,string _kids,string _birth,string _death,string _age,string _type){
    cout<<"Constructor with paraeters"<<endl;
    cout<<"Class Kids"<<endl;
    setFio(_fio);
    setParents(_parents);
    setSpouse(_spouse);
    setKids(_kids);
    setBirth(_birth);
    setDeath(_death);
    setAge(_age);
    if(_type.compare("Kids") || _type.compare("kids")){
        type = _type;
    }
    else{
        throw MyException.false_id_exc();
    }
}
Kids::Kids( Kids& init){
    cout<<"Constructor of copying"<<endl;
    cout<<"Class Kids"<<endl;
    setFio(*init.getFio());
    setParents(*init.getParents());
    setSpouse(*init.getSpouse());
    setKids(*init.getKids());
    setBirth(*init.getBirth());
    setDeath(*init.getDeath());
    setAge(*init.getAge());
    if(init.getType().compare("Kids") || init.getType().compare("kids")){
        type = init.getType();
    }
    else{
        throw MyException.false_id_exc();
    }
}
Kids::~Kids(){
    cout<<"Destructor called"<<endl<<"Class Kids"<<endl;
}

