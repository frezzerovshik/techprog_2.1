//
//  Parents.hpp
//  TEHPROGA1
//
//  Created by Артем Шарапов on 12/10/2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#pragma once
#include "Base.hpp"
#include "Exception.hpp"
class Parents:public Base{
    Exception MyException;
    string type;
public:
    Parents();
    Parents(string _fio, string _parents,string _spouse,string _kids,string _birth,string _death,string _age,string _type);
    Parents(Parents& init);
    ~Parents();
    void setType(string _temp){type = _temp;}
    void setFio(string _fio){Base::setFio(_fio);}
    void setParents(string _parents){Base::setParents(_parents);}
    void setSpouse(string _spouse){Base::setSpouse(_spouse);};
    void setKids(string _kids){Base::setKids(_kids);}
    void setBirth(string _birth){Base::setBirth(_birth);}
    void setDeath(string _death){Base::setDeath(_death);}
    void setAge(string _age){Base::setAge(_age);}
    string getType(){return type;}
    string getFio(){return Base::getFio();}
    string getSpouse(){return Base::getSpouse();}
    string getKids(){return Base::getKids();}
    string getBirth(){return Base::getBirth();}
    string getP(){return Base::getParents();}
    string getDeath(){return Base::getDeath();}
    string getAge(){return Base::getAge();}
};
