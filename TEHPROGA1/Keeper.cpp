//
//  Keeper.cpp
//  T.P.S.2.L.1
//
//  Created by Артем Шарапов on 10/10/2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#include "Keeper.hpp"
Keeper::Keeper( Keeper& init){
    if(cont_k.getSize()!=init.cont_k.getSize() && cont_p.getSize()!=init.cont_p.getSize() && cont_g.getSize()!=init.cont_g.getSize()){
        throw exc.no_comparable_size_ecx();
    }
    for(int i = 0;i<cont_k.getSize();++i) cont_k.addAtIndex(i, init.cont_k.getItemFromIndex(i) );
    for(int i = 0;i<cont_p.getSize();++i) cont_p.addAtIndex(i, init.cont_p.getItemFromIndex(i) );
    for(int i = 0;i<cont_g.getSize();++i) cont_g.addAtIndex(i, init.cont_g.getItemFromIndex(i) );
}
void Keeper::editing(){
    cout<<"Объект какого класса хотите поменять?"<<endl<<"1 - Parents"<<endl<<"2 - Grandparents"<<endl<<"3 - Kids"<<endl;
    unsigned short i = cin.get();
    switch (i) {
        case 1:{
            cout<<"Какое поле хотите изменить?"<<endl<<"1 - ФИО"<<endl<<"2 - родители"<<endl<<"3 - супруги"<<endl<<"4 - дети"<<endl<<"5 дата рождения"<<endl<<"6 - дата смерти"<<endl<<"7 - возраст"<<endl;
            unsigned short j = cin.get();
            switch (j) {
                case 1:{
                    bool success = false;
                    string src;
                    cout<<"Введите искомое ФИО"<<endl;
                    getline(cin,src);
                    for(unsigned short k = 0;k<cont_p.getSize();++k){
                        if(*cont_p.getItemFromIndex(k).getFio() == src){
                            string temp;
                            cout<<"Введите новое ФИО"<<endl;
                            getline(cin,temp);
                            cont_p.getItemFromIndex(k).setFio(temp);
                            success = true;
                        }
                        else
                            continue;
                    }
                    if(success==false)
                        cout<<"Такой записи нет"<<endl;
                    break;
                }
                case 2:{
                    bool success = false;
                    string src;
                    cout<<"Введите искомые сведения в формате: Иванова А.А.,Иванов А.А."<<endl;
                    getline(cin,src);
                    for(unsigned short k = 0;k<cont_p.getSize();++k){
                        if(*cont_p.getItemFromIndex(k).getParents() == src){
                            string temp;
                            cout<<"Введите новые сведения о родителях"<<endl;
                            getline(cin,temp);
                            cont_p.getItemFromIndex(k).setParents(temp);
                            success = true;
                        }
                        else
                            continue;
                    }
                    if(success==false)
                        cout<<"Такой записи нет"<<endl;
                    break;
                }
                case 3:{
                    bool success = false;
                    string src;
                    cout<<"Введите искомые сведения в формате: Иванова А.А."<<endl;
                    getline(cin,src);
                    for(unsigned short k = 0;k<cont_p.getSize();++k){
                        if(*cont_p.getItemFromIndex(k).getSpouse() == src){
                            string temp;
                            cout<<"Введите новые сведения о супруге"<<endl;
                            getline(cin,temp);
                            cont_p.getItemFromIndex(k).setSpouse(temp);
                            success = true;
                        }
                        else
                            continue;
                    }
                    if(success==false)
                        cout<<"Такой записи нет"<<endl;
                    break;
                }
                case 4:{
                    bool success = false;
                    string src;
                    cout<<"Введите искомые сведения в формате: Иванова А.А.,Иванов А.А."<<endl;
                    getline(cin,src);
                    for(unsigned short k = 0;k<cont_p.getSize();++k){
                        if(*cont_p.getItemFromIndex(k).getKids() == src){
                            string temp;
                            cout<<"Введите новые сведения о детях"<<endl;
                            getline(cin,temp);
                            cont_p.getItemFromIndex(k).setKids(temp);
                            success = true;
                        }
                        else
                            continue;
                    }
                    if(success==false)
                        cout<<"Такой записи нет"<<endl;
                    break;
                }
                case 5:{
                    <#statements#>
                    break;
                }
                case 6:{
                    <#statements#>
                    break;
                }
                case 7:{
                    <#statements#>
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case 2:{
            cout<<"Какое поле хотите изменить?"<<endl<<"1 - ФИО"<<endl<<"2 - родители"<<endl<<"3 - супруги"<<endl<<"4 - дети"<<endl<<"5 дата рождения"<<endl<<"6 - дата смерти"<<endl<<"7 - возраст"<<endl;
            unsigned short j = cin.get();
            switch (j) {
                case 1:{
                    <#statements#>
                    break;
                }
                case 2:{
                    <#statements#>
                    break;
                }
                case 3:{
                    <#statements#>
                    break;
                }
                case 4:{
                    <#statements#>
                    break;
                }
                case 5:{
                    <#statements#>
                    break;
                }
                case 6:{
                    <#statements#>
                    break;
                }
                case 7:{
                    <#statements#>
                    break;
                }
                default:
                    break;
            break;
        }
            break;
        }
        case 3:{
            cout<<"Какое поле хотите изменить?"<<endl<<"1 - ФИО"<<endl<<"2 - родители"<<endl<<"3 - супруги"<<endl<<"4 - дети"<<endl<<"5 дата рождения"<<endl<<"6 - дата смерти"<<endl<<"7 - возраст"<<endl;
            unsigned short j = cin.get();
            switch (j) {
                case 1:{
                    <#statements#>
                    break;
                }
                case 2:{
                    <#statements#>
                    break;
                }
                case 3:{
                    <#statements#>
                    break;
                }
                case 4:{
                    <#statements#>
                    break;
                }
                case 5:{
                    <#statements#>
                    break;
                }
                case 6:{
                    <#statements#>
                    break;
                }
                case 7:{
                    <#statements#>
                    break;
                }
                default:
                    break;
        }
            break;
        }
        default:
            break;
    }
}
