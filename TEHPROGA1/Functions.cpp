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
TEMP_DATA getDataFromKeyboard() {
    TEMP_DATA a;
    cout << "¬ведите ‘»ќ:" << endl;
    getline(cin, a.fio);
    cout << "¬ведите информацию о родител€х (если она не известна или их нет в живых, введите -):" << endl;
    getline(cin, a.parents);
    cout << "¬ведите информацию о супруге:" << endl;
    getline(cin, a.spouse);
    cout << "¬ведите информацию о дет€х (если их нет, введите -):" << endl;
    getline(cin, a.kids);
    cout << "¬ведите дату рождени€:" << endl;
    getline(cin, a.birth);
    cout << "¬ведите дату смерти (если есть):" << endl;
    getline(cin, a.death);
    cout << "¬ведите возраст:" << endl;
    getline(cin, a.age);
    return a;
}
string getTypeWithTempStruct(TEMP_DATA var) {
    string res;
    if (var.parents.compare("-") && !var.kids.compare("-"))
        res.append("Grandparents");
    if (var.kids.compare("-") && !var.parents.compare("-"))
        res.append("Kids");
    if (!var.kids.compare("-") && !var.parents.compare("-"))
        res.append("Parents");
    return res;
}

int runtime() {
    setlocale(LC_ALL,"rus");
    try {
        Keeper a;
        string field("a");
        for (int i = 0; i < 3; ++i) {
            Grandparents temp(field, field, field, field, field, field, field, field);
            a.addGrandparentAtIndex(i, temp);
        }
        for (int i = 0; i < 4; ++i) {
            Parents temp(field, field, field, field, field, field, field, field);
            a.addParentAtIndex(i, temp);
        }
        for (int i = 0; i < 5; ++i) {
            Kids temp(field, field, field, field, field, field, field, field);
            a.addKidAtIndex(i, temp);
        }
        a.print();
        system("pause");
        return 0;
    }
    catch (...) {
        cout << "Proizoshel trolling...";
        system("pause");
        return 0;
    }
    
}
