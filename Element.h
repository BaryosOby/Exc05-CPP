#ifndef EXC05_ELEMENT_H
#define EXC05_ELEMENT_H
#include <iostream>
#include <vector>

using namespace std;


template <typename T, typename E> class Element;
template <typename T, typename E> std::ostream& operator<< (std::ostream& o, const Element<T, E>& element);

template <typename T,typename E> class Element {
private:
    vector<T> x;
    vector<E> fx;
    int rank;

public:
    Element():x(0),fx(0),rank(0){};
    explicit Element(vector<T> xvect): x(xvect), rank(0) {};
    Element(vector<T> xvect, vector<E> f): x(xvect), fx(f), rank(0) {}; //TODO DELETE
    vector<T> getX() const { return x;}
    void setX(vector<T>& x) {this->x = x;}
    vector<E>& getFx() const { return fx;}
    void setfX(vector<T>& f) const{this->fx = fx;}

    Element& operator++(){
        rank++;
        return *this;
    }

    Element& operator++(int){
        rank++;
        return *this;
    }

    void setRank(int r) { rank = r;}
    int getRank() const { return rank;}

    int findDominate(Element& other){
        int count = 0;
        int countOther=0;
        int big = 0;
        for (int i =0 ;i<fx.size(); i++){
            if (fx[i] <= other.fx[i]){
                count++;
            }
            if (fx[i] < other.fx[i]){
                big =1 ;
            }
            if (fx[i] >= other.fx[i]){
                countOther++;
            }
            if (fx[i] > other.fx[i])
            {
                big =-1;
            }
        }
        if (big == 1 && count == fx.size()){return 1;}
        if (big == -1 && countOther == fx.size()){return -1;}
        return 0;
    }

};


template <typename T, typename E>
ostream& operator<<(ostream& out, const Element<T,E>& elem )
{
    vector<T> x = elem.getX();
    for(int i=0; i<x.size(); ++i)
        out<<fixed << setprecision(6) << x[i];
    return out;
}



#endif
