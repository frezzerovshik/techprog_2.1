//
//  Keeper.cpp
//  T.P.S.2.L.1
//
//  Created by ¿ÚÂÏ ÿ‡‡ÔÓ‚ on 10/10/2019.
//  Copyright © 2019 ¿ÚÂÏ ÿ‡‡ÔÓ‚. All rights reserved.
//
#include "Keeper.hpp"
#include <iomanip>
#include <stdio.h>
Keeper::Keeper(Keeper& init) {
    if (cont_k.getSize() != init.cont_k.getSize() && cont_p.getSize() != init.cont_p.getSize() && cont_g.getSize() != init.cont_g.getSize()) {
        throw exc.no_comparable_size_ecx();
    }
    if(!log.is_open()){
        log.open("/Users/frez2zerovshik/Documents/Универ/Третий курс/Проекты xCode/TEHPROGA1/TEHPROGA1/CONSTRUCTOR_DESTRUCTOR_LOG_FILE.txt");
    }
    log<<"Constructor of copying called, class Keeper"<<endl;
    for (int i = 0; i < cont_k.getSize(); ++i) cont_k.addAtIndex(i, init.cont_k.getItemFromIndex(i));
    for (int i = 0; i < cont_p.getSize(); ++i) cont_p.addAtIndex(i, init.cont_p.getItemFromIndex(i));
    for (int i = 0; i < cont_g.getSize(); ++i) cont_g.addAtIndex(i, init.cont_g.getItemFromIndex(i));
}
void Keeper::print() {
    cout<<"GRANDPARENTS"<<endl;
    for(unsigned short i=0;i<cont_g.getSize();i++)
    {
        printf("\tФИО %5s\t\n",cont_g.getItemFromIndex(i).getFio()->c_str());
        printf("\tParents %5s\t\n",cont_g.getItemFromIndex(i).getParents()->c_str() );
        printf("\tSpouse %5s\t\n",cont_g.getItemFromIndex(i).getSpouse()->c_str());
        printf("\tKids %5s\t\n", cont_g.getItemFromIndex(i).getKids()->c_str());
        printf("\tBirth %5s\t\n", cont_g.getItemFromIndex(i).getBirth()->c_str());
        printf("\tDeath %5s\t\n", cont_g.getItemFromIndex(i).getDeath()->c_str());
        printf("\tAge %5s\t\n", cont_g.getItemFromIndex(i).getAge()->c_str());
        printf("\n\n\n");
    }
    cout<<"PARENTS"<<endl;
    for(unsigned short i=0;i<cont_p.getSize();i++)
    {
        printf("\tФИО %5s\t\n",cont_p.getItemFromIndex(i).getFio()->c_str());
        printf("\tParents %5s\t\n",cont_p.getItemFromIndex(i).getParents()->c_str() );
        printf("\tSpouse %5s\t\n",cont_p.getItemFromIndex(i).getSpouse()->c_str());
        printf("\tKids %5s\t\n", cont_p.getItemFromIndex(i).getKids()->c_str());
        printf("\tBirth %5s\t\n", cont_p.getItemFromIndex(i).getBirth()->c_str());
        printf("\tDeath %5s\t\n", cont_p.getItemFromIndex(i).getDeath()->c_str());
        printf("\tAge %5s\t\n", cont_p.getItemFromIndex(i).getAge()->c_str());
        printf("\n\n");
    }
    cout<<"KIDS"<<endl;
    for(unsigned short i=0;i<cont_k.getSize();i++)
    {
        printf("\tФИО %5s\t\n",cont_k.getItemFromIndex(i).getFio()->c_str());
        printf("\tParents %5s\t\n",cont_k.getItemFromIndex(i).getParents()->c_str() );
        printf("\tSpouse %5s\t\n",cont_k.getItemFromIndex(i).getSpouse()->c_str());
        printf("\tKids %5s\t\n", cont_k.getItemFromIndex(i).getKids()->c_str());
        printf("\tBirth %5s\t\n", cont_k.getItemFromIndex(i).getBirth()->c_str());
        printf("\tDeath %5s\t\n", cont_k.getItemFromIndex(i).getDeath()->c_str());
        printf("\tAge %5s\t\n", cont_k.getItemFromIndex(i).getAge()->c_str());
        printf("\n\n");
    }
}
