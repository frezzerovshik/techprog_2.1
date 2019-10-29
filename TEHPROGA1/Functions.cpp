//
//  Functions.cpp
//  TEHPROGA1
//
//  Created by јртем Ўарапов on 18/10/2019.
//  Copyright © 2019 јртем Ўарапов. All rights reserved.
//

#include "Functions.hpp"
#include <string>


using namespace std;
TEMP_DATA* getDataFromKeyboard() {
    cin.ignore(1000,'\n');
    TEMP_DATA *a = new TEMP_DATA;
    cout << "¬ведите ‘»ќ:" << endl;
    getline(cin, a->fio);
    cout << "¬ведите информацию о родител€х (если она не известна или их нет в живых, введите -):" << endl;
    getline(cin, a->parents);
    cout << "¬ведите информацию о супруге:" << endl;
    getline(cin, a->spouse);
    cout << "¬ведите информацию о дет€х (если их нет, введите -):" << endl;
    getline(cin, a->kids);
    cout << "¬ведите дату рождени€:" << endl;
    getline(cin, a->birth);
    cout << "¬ведите дату смерти (если есть):" << endl;
    getline(cin, a->death);
    cout << "¬ведите возраст:" << endl;
    getline(cin, a->age);
    return a;
}
int getTypeWithTempStruct(TEMP_DATA var) {
    int flag = 0;
    string none("-");
    if(var.parents == none)
        flag = 0;
    else{
    if(var.kids == none)
        flag = 1;
    else flag = 2;
    }
    return flag;
}

int runtime() {
    try {
        unsigned short size_g;
        unsigned short size_p;
        unsigned short size_k;
        ifstream config("/Users/frez2zerovshik/Documents/Универ/Третий курс/Проекты xCode/TEHPROGA1/TEHPROGA1/config.txt");
        config>>size_g;
        config>>size_p;
        config>>size_k;
        config.close();
        ofstream config_o("/Users/frez2zerovshik/Documents/Универ/Третий курс/Проекты xCode/TEHPROGA1/TEHPROGA1/config.txt");
        setlocale(LC_ALL,"rus");
        Keeper a;
        unsigned short c;
        bool work = true;
        string way_p("/Users/frez2zerovshik/Documents/Универ/Третий курс/Проекты xCode/TEHPROGA1/TEHPROGA1/Parents.txt");
        string way_g("/Users/frez2zerovshik/Documents/Универ/Третий курс/Проекты xCode/TEHPROGA1/TEHPROGA1/Grandparents.txt");
        string way_k("/Users/frez2zerovshik/Documents/Универ/Третий курс/Проекты xCode/TEHPROGA1/TEHPROGA1/Kids.txt");
        string way_p_t("/Users/frez2zerovshik/Documents/Универ/Третий курс/Проекты xCode/TEHPROGA1/TEHPROGA1/Parents_test_output.txt");
        string way_g_t("/Users/frez2zerovshik/Documents/Универ/Третий курс/Проекты xCode/TEHPROGA1/TEHPROGA1/Grandparents_test_output.txt");
        string way_k_t("/Users/frez2zerovshik/Documents/Универ/Третий курс/Проекты xCode/TEHPROGA1/TEHPROGA1/Kids_test_output.txt");
        fstream temp;
        while(work){
            cout<<"1 - считать из файла"<<endl<<"2 - записать в файл"<<endl<<"3 -  добавить запись"<<endl<<"4 - удалить запись"<<endl<<"5 - вывести на экран"<<endl<<"6 - выход"<<endl;
            cin>>c;
            switch (c) {
                case 1:{
                    bool is_let = false;
                    temp.open(way_p);
                    if(temp.eof()) {cout<<"Невозможно считать Parents, т.к. файл пуст"<<endl;is_let = false;}else is_let = true;
                    temp.close();
                    temp.open(way_g);
                    if(temp.eof()) {cout<<"Невозможно считать Grandparents т.к. файл пуст"<<endl;is_let = false;}else is_let = true;
                    temp.close();
                    temp.open(way_k);
                    if(temp.eof()) {cout<<"Невозможно считать Kids, т.к. файл пуст"<<endl;is_let = false;}else is_let = true;
                    temp.close();
                    if(is_let == true){
                       
                        a.read(way_p, way_g, way_k,size_g,size_p,size_k);
                        cout<<"Размер Kids: "<<a.getSizeKids()<<endl<<"Размер Parents: "<<a.getSizeParents()<<endl<<"Размер Grandparents: "<<a.getSizeGrandparents()<<endl;
                    }
                    break;
                }
                case 2:{
                    if(!a){
                        a.saveConfiguration(config_o);
                        a.save(way_p_t, way_g_t, way_k_t);
                    }
                    else cout<<"Keeper пуст, заполните его!"<<endl;
                    break;
                }
                case 3:{
                    TEMP_DATA *temp;
                    temp = getDataFromKeyboard();
                    int type = getTypeWithTempStruct(*temp);
                    switch(type){
                case 1:{
                        string _type("Kids");
                        Kids *ptr = a.buildKidObj();
                        ptr->setType(&_type);
                        ptr->setFio(temp->fio);
                        ptr->setSpouse(temp->spouse);
                        ptr->setParents(temp->parents);
                        ptr->setKids(temp->kids);
                        ptr->setBirth(temp->birth);
                        ptr->setDeath(temp->death);
                        ptr->setAge(temp->age);
                        a.addKidAtIndex(a.getSizeKids(), *ptr);
                    break;
                    }
                case 2:{
                        string _type("Parents");
                        Parents *ptr = a.buildParentObj();
                        ptr->setType(&_type);
                        ptr->setFio(temp->fio);
                        ptr->setSpouse(temp->spouse);
                        ptr->setParents(temp->parents);
                        ptr->setKids(temp->kids);
                        ptr->setBirth(temp->birth);
                        ptr->setDeath(temp->death);
                        ptr->setAge(temp->age);
                        a.addParentAtIndex(a.getSizeParents(), *ptr);
                        break;
                    }
                        case 0:{
                            string _type("Grandparents");
                        Grandparents *ptr = a.buildGrandparentObj();
                        ptr->setType(&_type);
                        ptr->setFio(temp->fio);
                        ptr->setSpouse(temp->spouse);
                        ptr->setParents(temp->parents);
                        ptr->setKids(temp->kids);
                        ptr->setBirth(temp->birth);
                        ptr->setDeath(temp->death);
                        ptr->setAge(temp->age);
                        a.addGrandparentAtIndex(a.getSizeGrandparents(), *ptr);
                            break;
                    }
                            default:
                            break;
                    }
                    break;
                }
                case 4:
                    if(!a){
                        cout<<"Какого типа объект удалить?"<<endl<<"1 - Parents"<<endl<<"2 - Grandparents"<<endl<<"3 - Kids"<<endl;
                        unsigned short sw;
                        cin>>sw;
                        switch (sw) {
                            case 1:{
                                a.print();
                                unsigned short i;
                                cout<<"Введите номер записи"<<endl;
                                cin >> i;
                                a.removeParentAtIndex(i);
                                break;
                            }
                            case 2:{
                                a.print();
                                int i;
                                cout<<"Введите номер записи"<<endl;
                                cin >> i;
                                a.removeGrandparentAtIndex(i);
                                break;
                            }
                            case 3:{
                                a.print();
                                int i;
                                cout<<"Введите номер записи"<<endl;
                               cin >> i;
                                a.removeKidAtIndex(i);
                                break;
                            }
                            default:
                                break;
                        }
                    }
                    break;
                case 5:
                    if(!a)
                        a.print();
                    break;
                case 6:{
                    a.saveConfiguration(config_o);
                    a.save(way_p_t, way_g_t, way_k_t);
                    work = false;
                }
                    break;
                default:
                    break;
            }
        }
        
        system("pause");
        return 0;
    }
    catch (...) {
        cout<<"Check the error below"<<endl;
        system("pause");
        return 0;
    }
    
}
