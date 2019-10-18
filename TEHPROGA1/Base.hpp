//
//  Base.hpp
//  T.P.S.2.L.1
//
//  Created by Артем Шарапов on 10/10/2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//
#pragma once
#include <iostream>
using  namespace std;
class Base{
    string fio;
    string parents;
    string spouse;
    string kids;
    string birth;
    string death;
    string age;
public:
    Base(){};
    Base (const Base& init){};
    Base(string _fio, string _parents,string _spouse,string _kids,string _birth,string _death,string _age){};
    virtual ~Base() {};
    virtual void setType(string _temp) = 0;
    virtual void setFio(string _fio){fio = _fio;}
    virtual void setParents(string _parents){parents = _parents;}
    virtual void setSpouse(string _spouse){spouse = _spouse;};
    virtual void setKids(string _kids){kids = _kids;}
    virtual void setBirth(string _birth){birth = _birth;}
    virtual void setDeath(string _death){death = _death;}
    virtual  void setAge(string _age){age = _age;}
    virtual string* getFio(){return &fio;}
    virtual string* getSpouse(){return &spouse;}
    virtual string* getKids(){return &kids;}
    virtual string* getBirth(){return &birth;}
    virtual string* getParents(){return &parents;}
    virtual string* getDeath(){return &death;}
    virtual string* getAge(){return &age;}
};
