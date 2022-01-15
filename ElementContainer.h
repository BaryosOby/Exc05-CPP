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
                int dominanceRes = elements[i].findDominate(elements[j]);
                if(dominanceRes > 0){
                    elements[j]++;
                }
                if(dominanceRes < 0){
                    elements[i]++;
                }
            }
        }
    }

    void merge(int start, int mid, int end){
        vector<Element<T, E>> temp;
        int i = start, j = mid + 1;
        while(i <= mid && j <= end){
            if(elements[i].getRank() <= elements[j].getRank()){
                temp.push_back(elements[i]);
                i++;
            }
            else{
                temp.push_back(elements[j]);
                j++;
            }
        }
        while(i <= mid){
            temp.push_back(elements[i]);
            i++;
        }
        while(j <= end){
            temp.push_back(elements[j]);
            j++;
        }
        for(int k = start; k <= end; k++){
            elements[k] = temp[k - start];
        }

    }

    void ElementsReordering(int start, int end){
        // using Merge sort by rank
        if(start < end){
            int mid = (start+end) / 2;
            ElementsReordering(start, mid);
            ElementsReordering(mid+1, end);
            merge(start, mid, end);
        }
    }

public:
    ElementContainer(): elements(0), size(0), vectorSize(0), fxSize(0){}
    ElementContainer(vector<Element<T, E>>& elems, int mu, int n, int m) : elements(elems), size(mu), vectorSize(n), fxSize(m){}

    void addElement(Element<T, E>& elem){
        elements.push_back(elem);
    }

    void removeKElements(int k){
        elements.erase(elements.begin()+k,elements.end());
    }

    void pareSorting(){
        paretoRanking();
        ElementsReordering(0, size-1);
    }

    vector<Element<T,E>>& getElements() const{
        return elements;
    }


};


#endif
