//
//  MyArray.h
//  TEHPROGA1
//
//  Created by Артем Шарапов on 17/10/2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
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
    fstream stream_r;
    ofstream stream_wr;
    Exception exc;
public:
    MyArray();
    MyArray(T *_arr , fstream _stream,ofstream wr_str);
    MyArray(const MyArray& _init);
    ~MyArray();
    void addAtIndex(unsigned short _index, T _object);//+
    void addAtFront(T _object);//+
    void addAtEnd(T _object);//+
    void removeFromIndex(unsigned short _index);//+
    void removeFromFront();//+
    void removeFromEnd();//+
    void saveOnFile(string way);//+
    void readFromFile(string way);//+
    unsigned short getSize(){return size;}
    T& getItemFromIndex(unsigned short _index){return arr[_index];}
};
template <typename T>
MyArray<T>::MyArray(){
    arr = nullptr;
    size = 0;
}
template <typename T>
MyArray<T>::MyArray(T *_arr, fstream _stream, ofstream wr_str){
    arr = _arr;
    size = _arr->getSize();
    stream_r = _stream;
    stream_wr = wr_str;
}
template <typename T>
MyArray<T>::MyArray(const MyArray& _init){
    arr = _init.arr;
    size = _init.size;
    stream_r = _init.stream;
}
template <typename T>
MyArray<T>::~MyArray(){
    delete[] arr;
    stream_r.close();
    stream_wr.close();
}
template<typename T>
//Element will be addet at the left sideof existed element with _index
void MyArray<T>::addAtIndex(unsigned short _index, T _object){
    if(_index>size-1 || _index<0)
        throw exc.out_of_bounds_ecx();
    T *tmp_1 = new T[_index];
    T *tmp_2 = new T[size - _index];
    for (int i = 0;i<_index;++i) tmp_1[i] = arr[i];
    for (int i = _index;i<size;++i) tmp_2[i] = arr[i];
    delete[] this->arr;
    arr = new T[++size];
    for(int i = 0;i<_index;++i) arr[i] = tmp_1[i];
    arr[_index] = _object;
    for(int i = _index+1;i<size;++i) arr[i] = tmp_2[i];
    delete[] tmp_1;
    delete[] tmp_2;
}
template <typename T>
void MyArray<T>:: addAtEnd(T _object){
    T *tmp = new T[size+1];
    for(int i = 0;i<size;++i) tmp[i] = arr[i];
    delete[] this->arr;
    arr = new T[++size];
    for(int i = 0;i<size-1;++i) arr[i] = tmp[i];
    arr[size-1] = _object;
    delete[] tmp;
}
template <typename T>
void MyArray<T>::addAtFront(T _object){
    this->addAtIndex(0,_object);
}
template <typename T>
void MyArray<T>::removeFromIndex(unsigned short _index){
    T temp = arr[_index];
    T *tmp_1 = new T[_index];
    T *tmp_2 = new T[size-_index-1];
    int i = 0;
    while(arr[i].getFio() != temp.getFio() && arr[i].getSpouse() != temp.getSpouse() && arr[i].getKids() != temp.getKids() && arr[i].getBirth() != temp.getBirth() && arr[i].getParents() != temp.getParents() && arr[i].getDeath() != temp.getDeath() && arr[i].getAge() != temp.getAge()){
        tmp_1[i] = arr[i];
        ++i;
    }
    for(i =_index+1;i<size;++i) tmp_2[i] = arr[i];
    delete[] arr;
    arr = new T[--size];
    for( i =0;i<_index;++i)  arr[i] = tmp_1[i];
    for( i = _index;i < size;++i)    arr[i] = tmp_2[i];
    delete[] tmp_1;
    delete[] tmp_2;
}
template <typename T>
void MyArray<T>::removeFromFront(){
    this->removeFromIndex(0);
}
template<typename T>
void MyArray<T>::removeFromEnd(){
    this->removeFromIndex(size-1);
}
template <typename T>
void MyArray<T>::saveOnFile(string way){
    if(stream_wr.is_open()){
        stream_wr.close();
        stream_wr.open(way.c_str());
    }
    else
        stream_wr.open(way.c_str());
    for (int i = 0; i < size; ++i) {
        stream_wr << *(arr[i].getFio())<<endl;
        stream_wr << *(arr[i].getSpouse())<<endl;
        stream_wr << *(arr[i].getKids()) << endl;
        stream_wr << *(arr[i].getBirth()) << endl;
        stream_wr << *(arr[i].getParents()) << endl;
        stream_wr << *(arr[i].getDeath()) << endl;
        stream_wr << *(arr[i].getAge()) << endl;
    }
}
template <typename T>
void MyArray<T>::readFromFile(string way){
    if(stream_r.is_open()){
        stream_r.close();
        stream_r.open(way.c_str());
    }
    else
        stream_r.open(way.c_str());
    string temp;
    for (int i = 0; i < size; ++i) {
        getline(stream_r, temp);
        arr[i].setType(temp);
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
        arr[i].setDeath( temp);
        getline(stream_r, temp);
        arr[i].setAge( temp);
    }
}
