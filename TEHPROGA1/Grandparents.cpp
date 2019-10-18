//
//  Grandparents.cpp
//  T.P.S.2.L.1
//
//  Created by Артем Шарапов on 12/10/2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#include "Grandparents.hpp"
Grandparents::Grandparents(){
    cout<<"Constructor without parameters"<<endl;
    cout<<"Class Grandparents"<<endl;
    type.append("0");
}
Grandparents::Grandparents(string _fio, string _parents,string _spouse,string _kids,string _birth,string _death,string _age,string _type){
    cout<<"Constructor with paraeters"<<endl;
    cout<<"Class Grandparents"<<endl;
    setFio(_fio);
    setParents(_parents);
    setSpouse(_spouse);
    setKids(_kids);
    setBirth(_birth);
    setDeath(_death);
    setAge(_age);
    if(_type.compare("Grandparents") || _type.compare("grandparents")){
        type = _type;
    }
    else{
        throw MyException.false_id_exc();
    }
}
Grandparents::Grandparents( Grandparents& init){
    cout<<"Constructor of copying"<<endl;
    cout<<"Class Grandparents"<<endl;
    setFio(init.getFio());
    setParents(init.getParents());
    setSpouse(init.getSpouse());
    setKids(init.getKids());
    setBirth(init.getBirth());
    setDeath(init.getDeath());
    setAge(init.getAge());
    if(init.getType().compare("Grandparents") || init.getType().compare("grandparents")){
        type = init.getType();
    }
    else{
        throw MyException.false_id_exc();
    }
}
Grandparents::~Grandparents(){
    cout<<"Destructor called"<<endl<<"Class Grandparents"<<endl;
}

