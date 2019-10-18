//
//  Functions.cpp
//  TEHPROGA1
//
//  Created by Артем Шарапов on 18/10/2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#include "Functions.hpp"

TEMP_DATA getDataFromKeyboard(){
    TEMP_DATA a;
    cout<<"Введите ФИО:"<<endl;
    cin>>a.fio;
    cout<<"Введите информацию о родителях (если она не известна или их нет в живых, введите -):"<<endl;
    cin>>a.parents;
    cout<<"Введите информацию о супруге:"<<endl;
    cin>>a.spouse;
    cout<<"Введите информацию о детях (если их нет, введите -):"<<endl;
    cin>>a.kids;
    cout<<"Введите дату рождения:"<<endl;
    cin>>a.birth;
    cout<<"Введите дату смерти (если есть):"<<endl;
    cin>>a.death;
    cout<<"Введите возраст:"<<endl;
    cin>>a.age;
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
    Keeper main_keeper;
    unsigned short swc;
    do{
        cout<<"Меню:"<<endl<<"1 - считать фамильное дерево из файла"<<endl<<"2 - добавить в дерево"<<endl<<"3 - вывести дерево на экран"<<endl<<"4 - редактирование"<<"5 - сохранение в файл"<<endl<<"6 - выход"<<endl;
        
    }while(true);
    return 0;
}
