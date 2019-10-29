//
//  MyArray.h
//  TEHPROGA1
//
//  Created by ¿ÚÂÏ ÿ‡‡ÔÓ‚ on 17/10/2019.
//  Copyright © 2019 ¿ÚÂÏ ÿ‡‡ÔÓ‚. All rights reserved.
//
/*TEMPLATE CLASS TO WORK WITH ARRAY*/
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Exception.hpp"
using namespace std;
template <typename T>
class MyArray {
    T *arr;
    unsigned short size;
    ifstream stream_r;
    ofstream stream_wr;
    Exception exc;
public:
    MyArray();
    MyArray(T *_arr, fstream _stream, ofstream wr_str);
    MyArray(const MyArray& _init);
    ~MyArray();
    void addAtIndex(unsigned short _index, T _object);//+
    void addAtFront(T _object);//+
    void addAtEnd(T _object);//+
    void removeFromIndex(unsigned short _index);//+
    void removeFromFront();//+
    void removeFromEnd();//+
    void saveOnFile(string way);//+
    void readFromFile(string way, unsigned short par);//+
    unsigned short getSize() { return size; }
    void setSize(unsigned short par);
    T& getItemFromIndex(unsigned short _index) { return arr[_index]; }
};
template<typename T>
void MyArray<T>::setSize(unsigned short par){
    size = par;
}
template <typename T>
MyArray<T>::MyArray() {
  
    arr = nullptr;
    size = 0;
}
template <typename T>
MyArray<T>::MyArray(T *_arr, fstream _stream, ofstream wr_str) {
    arr = _arr;
    size = _arr->getSize();
    stream_r = _stream;
    stream_wr = wr_str;
    
}
template <typename T>
MyArray<T>::MyArray(const MyArray& _init) {
    for (unsigned short i = 0; i < _init.size; ++i) arr[i] = _init.arr[i];
    size = _init.size;
    stream_r = _init.stream;
  
}
template <typename T>
MyArray<T>::~MyArray() {
    delete[] arr;
    stream_r.close();
    stream_wr.close();
}
template<typename T>
//Element will be addet at the left sideof existed element with _index
void MyArray<T>::addAtIndex(unsigned short _index, T _object) {
    if (size != 0) {
        if ( _index < 0)
            throw exc.out_of_bounds_ecx();
        T *tmp_1 = new T[_index];
        T *tmp_2 = new T[size - _index];
        for (int i = 0; i < _index; ++i) tmp_1[i] = arr[i];
        for (int i = _index; i < size; ++i) tmp_2[i] = arr[i];
        delete[] this->arr;
        arr = new T[++size];
        for (int i = 0; i < _index; ++i) arr[i] = tmp_1[i];
        arr[_index] = _object;
        for (int i = _index + 1; i < size; ++i) arr[i] = tmp_2[i];
        delete[] tmp_1;
        delete[] tmp_2;
    }
    else {
        arr = new T[1];
        arr[0] = _object;
        ++size;
    }
    
}
template <typename T>
void MyArray<T>::addAtEnd(T _object) {
    T *tmp = new T[size + 1];
    for (int i = 0; i < size; ++i) tmp[i] = arr[i];
    delete[] this->arr;
    arr = new T[++size];
    for (int i = 0; i < size - 1; ++i) arr[i] = tmp[i];
    arr[size - 1] = _object;
    delete[] tmp;
}
template <typename T>
void MyArray<T>::addAtFront(T _object) {
    this->addAtIndex(0, _object);
}
template <typename T>
void MyArray<T>::removeFromIndex(unsigned short _index) {
    if (_index >= size) exc.out_of_bounds_ecx();
    
    T* temp = new T[size];
    for (unsigned short i = 0; i < size; ++i) temp[i] = arr[i];
    
    delete[] arr;
    arr = new T[size-1];
    
    for (unsigned short i = 0, j = 0; i < size; ++i, ++j)
        if (i != _index) arr[j] = temp[i];
        else --j;
    --size;
    
    delete[] temp;
}
template <typename T>
void MyArray<T>::removeFromFront() {
    this->removeFromIndex(0);
}
template<typename T>
void MyArray<T>::removeFromEnd() {
    this->removeFromIndex(size - 1);
}
template <typename T>
void MyArray<T>::saveOnFile(string way) {
    if (stream_wr.is_open()) {
        stream_wr.close();
        stream_wr.open(way.c_str());
    }
    else
        stream_wr.open(way.c_str());
    stream_wr<< (arr[0].getType())<<endl;
    for (unsigned short i = 0; i < size; ++i) {
        stream_wr << *(arr[i].getFio()) << endl;
        stream_wr << *(arr[i].getParents()) << endl;
        stream_wr << *(arr[i].getSpouse()) << endl;
        stream_wr << *(arr[i].getKids()) << endl;
        stream_wr << *(arr[i].getBirth()) << endl;
        stream_wr << *(arr[i].getDeath()) << endl;
        stream_wr << *(arr[i].getAge()) << endl;
    }
}
template <typename T>
void MyArray<T>::readFromFile(string way,unsigned short par) {
    size = par;
    if(arr!= nullptr)
        exc.existed_file();
    if (stream_r.is_open()) {
        stream_r.close();
        stream_r.open(way.c_str());
    }
    else
        stream_r.open(way.c_str());
    string temp;
    string type;
    getline(stream_r, type);
    arr = new T[size];
    for (int i = 0; i < size; ++i) {
        arr[i].setType(&type);
        getline(stream_r, temp);
        arr[i].setFio(temp);
        getline(stream_r, temp);
        arr[i].setParents(temp);
        getline(stream_r, temp);
        arr[i].setSpouse(temp);
        getline(stream_r, temp);
        arr[i].setKids(temp);
        getline(stream_r, temp);
        arr[i].setBirth(temp);
        getline(stream_r, temp);
        arr[i].setDeath(temp);
        getline(stream_r, temp);
        arr[i].setAge(temp);
    }
}
