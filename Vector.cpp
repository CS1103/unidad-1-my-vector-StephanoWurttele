//
// Created by rudri on 3/29/2019.
//

#include "Vector.h"
namespace UTEC {
    void vector::push_back(const int value) {
        _size+=1;
        if (_arr==nullptr){
            _arr=new int[_size];
            _arr[0]=value;
        }
        else{
            int* p=new int[_size];
            for(int i = 0;i<_size-1;i++){
                p[i] = _arr[i];
            }
            p[_size-1]=value;
            delete _arr;
            _arr=p;
        }
    }
    void vector::insert(int pos, const int value){
        int* p=new int[_size+1];
        for (int i=0;i<_size;i++){
            if (i<pos){
                _arr[i]=p[i];
            }
            else{
                _arr[i]=p[i+1];
            }
        }
        p[pos]=p[value];
        delete _arr;
        _arr=p;
    };

    void vector::pop_back() {
        _size-=1;
        int* p=new int[_size];
        for(int i = 0;i<_size-2;i++){
            p[i] = _arr[i];
        }
        delete _arr;
        _arr=p;
    }

    vector::vector() : _arr{nullptr}, _size(0) {}
    vector::~vector() {
        delete [] _arr;
        }

    int vector::size() {return _size;}

    int vector::get_item(int i) {return _arr[i];}
}
