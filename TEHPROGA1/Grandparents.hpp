//
//  Grandparents.hpp
//  T.P.S.2.L.1
//
//  Created by Артем Шарапов on 10/10/2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#pragma once
#include "Base.hpp"
#include "Exception.hpp"
class Grandparents:public Base{
    Exception MyException;
    string type;
public:
    Grandparents();
    Grandparents(string _fio, string _parents,string _spouse,string _kids,string _birth,string _death,string _age,string _type);
    Grandparents(Grandparents& init);
    ~Grandparents();
    void setType(string *_temp){type = *_temp;}
    void setFio(string _fio){Base::setFio(_fio);}
    void setParents(string _parents){Base::setParents(_parents);}
    void setSpouse(string _spouse){Base::setSpouse(_spouse);};
    void setKids(string _kids){Base::setKids(_kids);}
    void setBirth(string _birth){Base::setBirth(_birth);}
    void setDeath(string _death){Base::setDeath(_death);}
    void setAge(string _age){Base::setAge(_age);}
    string getType(){return type;}
    string* getFio(){return Base::getFio();}
    string* getParents(){return Base::getParents();}
    string* getSpouse(){return Base::getSpouse();}
    string* getKids(){return Base::getKids();}
    string* getBirth(){return Base::getBirth();}
    string* getDeath(){return Base::getDeath();}
    string* getAge(){return Base::getAge();}
};
