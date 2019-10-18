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
#include "Exception.hpp"
using namespace std;
template <typename T>
class MyArray {
    T *arr;
    unsigned short size;
    fstream stream;
    Exception exc;
public:
    MyArray();
    MyArray(T *_arr , fstream _stream);
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
MyArray<T>::MyArray(T *_arr, fstream _stream){
    arr = _arr;
    size = _arr->getSize();
    stream = _stream;
}
template <typename T>
MyArray<T>::MyArray(const MyArray& _init){
    arr = _init.arr;
    size = _init.size;
    stream = _init.stream;
}
template <typename T>
MyArray<T>::~MyArray(){
    delete[] arr;
    stream.close();
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
    while(arr[i]!=temp){
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
    if(stream.is_open()){
        stream.close();
        stream.open(way.c_str());
    }
    else
        stream.open(way.c_str());
    for(int i = 0;i<size;++i) stream<<arr[i];
}
template <typename T>
void MyArray<T>::readFromFile(string way){
    if(stream.is_open()){
        stream.close();
        stream.open(way.c_str());
    }
    else
        stream.open(way.c_str());
    for(int i = 0;i<size;++i) stream>>arr[i];
}
