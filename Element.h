#ifndef EXC05_ELEMENT_H
#define EXC05_ELEMENT_H
#include <iostream>
#include <vector>

using namespace std;


template <class T,class E> class Element {
private:
    vector<T> x;
    vector<E> fx;
    int rank;

public:
    Element():x(0),fx(0),rank(0){};
    explicit Element(vector<T> xvect): x(xvect), rank(0) {};
    vector<T>& getX() const{ return x;}
    void setX(vector<T>& x) {this->x = x;}
    vector<E>& getFx() const { return fx;}
    void setfX(vector<T>& f) const{this->fx = fx;}

    void setRank(int r) { rank = r;}
    int getRank() const { return rank;}
    int findDominate(Element& other){
        int count = 0;
        int countOther=0;
        int big = 0;
        for (int i =0 ;i<fx.size(); i++){
            if (fx[i] >= other.fx[i]){
                count++;
            }
            if (fx[i] > other.fx[i]){
                big =1 ;
            }
            if (fx[i]<=other.fx[i]){
                countOther++;
            }
            if (fx[i] < other.fx[i])
            {
                big =-1;
            }
        }
        if (big == 1 && count == fx.size()){return 1;}
        if (big == -1 && countOther == fx.size()){return -1;}
        return 0;
    }
    Element operator+(const Element& e) const
    {
        return Element(x + e.getX(),0);
    }
//
//
//    // copy c'tor
//
//    Element& operator=(Element other)
//    {
//        swap(x, other.x);
//        swap(fx, other.fx);
//        swap(rank, other.rank);
//        return *this;
//    }
};





#endif
