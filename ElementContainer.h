#ifndef EXC05_ELEMENTCONTAINER_H
#define EXC05_ELEMENTCONTAINER_H
#include "Element.h"


template <class T, class E>class ElementContainer {
private:
    vector<Element<T, E>> elements;
    int size;
    int vectorSize;
    int fxSize;



    void paretoRanking(){
        for(int i = 0 ; i< size; i++){
            for (int j= i+1 ; j<size; j++){

            }
        }
    }

public:
    ElementContainer(vector<Element<T, E>>& elems, int mu, int n, int m) : elements(elems), size(mu), vectorSize(n), fxSize(m){}

    void addElements(vector<Element<T, E>>& vect){
        elements.insert( elements.end(), vect.begin(), vect.end());
    }

    void removeKElements(int k){
        elements.erase(elements.begin()+k,elements.end());
    }

};


#endif
