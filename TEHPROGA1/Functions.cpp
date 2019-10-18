//
//  Functions.cpp
//  TEHPROGA1
//
//  Created by Артем Шарапов on 18/10/2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#include "Functions.hpp"
#include <string>
#include <Curses.h>

using namespace std;
TEMP_DATA getDataFromKeyboard(){
    TEMP_DATA a;
    cout<<"Введите ФИО:"<<endl;
    getline(cin, a.fio);
    cout<<"Введите информацию о родителях (если она не известна или их нет в живых, введите -):"<<endl;
    getline(cin,a.parents);
    cout<<"Введите информацию о супруге:"<<endl;
    getline(cin, a.spouse);
    cout<<"Введите информацию о детях (если их нет, введите -):"<<endl;
    getline(cin, a.kids);
    cout<<"Введите дату рождения:"<<endl;
    getline(cin, a.birth);
    cout<<"Введите дату смерти (если есть):"<<endl;
    getline(cin, a.death);
    cout<<"Введите возраст:"<<endl;
    getline(cin, a.age);
    return a;
}
string getTypeWithTempStruct(TEMP_DATA var){
    string res;
    if(var.parents.compare("-") && !var.kids.compare("-"))
        res.append("Grandparents");
    if(var.kids.compare("-") && !var.parents.compare("-"))
        res.append("Kids");
    if(!var.kids.compare("-") && !var.parents.compare("-"))
        res.append("Parents");
    return res;
}
void printKeeper(Keeper& a){
    
}
int runtime(){
    try {
        MyArray<Parents> a;
        Parents tmp;
        string fio("Sharapov A.S.");
        string age("Sharapov A.S.");
        string kids("Sharapov A.S.");
        string spouse("Sharapov A.S.");
        string parents("Sharapov A.S.");
        string birth("Sharapov A.S.");
        string death("Sharapov A.S.");
        tmp.setFio(fio);
        tmp.setAge(age);
        tmp.setKids(kids);
        tmp.setSpouse(spouse);
        tmp.setParents(parents);
        tmp.setBirth(birth);
        tmp.setDeath(death);
        a.addAtIndex(0, tmp);
        cout << "Hello from runtime func!" << endl;
         return 0;
    } catch (...) {
        cout<<"Proizoshel trolling...";
         return 0;
    }
  
}
