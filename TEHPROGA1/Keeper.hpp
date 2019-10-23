//
//  Keeper.hpp
//  T.P.S.2.L.1
//
//  Created by ¿ÚÂÏ ÿ‡‡ÔÓ‚ on 10/10/2019.
//  Copyright © 2019 ¿ÚÂÏ ÿ‡‡ÔÓ‚. All rights reserved.
//

#include "Parents.hpp"
#include "Grandparents.hpp"
#include "Kids.hpp"
#include "MyArray.h"
#include "Exception.hpp"
class Keeper {
    MyArray<Parents> cont_p;
    MyArray<Grandparents> cont_g;
    MyArray<Kids> cont_k;
    Exception exc;
public:
    Keeper() {};
    Keeper(Keeper& init);
    Keeper(string way_p, string way_g, string way_k) { cont_p.readFromFile(way_p); cont_g.readFromFile(way_g); cont_k.readFromFile(way_k); }
    ~Keeper() {};
    
    void print();
    void editing();
    void save(string way_p, string way_g, string way_k) { cont_p.saveOnFile(way_p); cont_g.saveOnFile(way_g); cont_k.saveOnFile(way_k); }
    void read(string way_p, string way_g, string way_k) { cont_p.readFromFile(way_p); cont_g.readFromFile(way_g); cont_k.readFromFile(way_k); }
    void addGrandparentAtIndex(int i, Grandparents obj) { cont_g.addAtIndex(i, obj); }
    void addParentAtIndex(int i, Parents obj) { cont_p.addAtIndex(i, obj); }
    void addKidAtIndex(int i, Kids obj) { cont_k.addAtIndex(i, obj); }
    void removeGrandparentAtIndex(int i) { cont_g.removeFromIndex(i); }
    void removeParentAtIndex(int i) { cont_p.removeFromIndex(i); }
    void removeKidAtIndex(int i) { cont_k.removeFromIndex(i); }
    bool operator!() { if (cont_k.getSize() == 0 && cont_p.getSize() == 0 && cont_g.getSize() == 0)return false; else return true; }
    Parents* buildParentObj() { Parents *a = new Parents; return a; }
    Grandparents* buildGrandparentObj() { Grandparents *a = new Grandparents; return a; }
    Kids* buildKidObj() { Kids *a = new Kids; return a; }
    unsigned short getSizeParents() { return cont_p.getSize(); }
    unsigned short getSizeGrandparents() { return cont_g.getSize(); }
    unsigned short getSizeKids() { return cont_k.getSize(); }
};
