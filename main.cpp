
#include "ElementContainer.h"

using namespace std;



int main() {
    vector<int> v1 ={1,2,3};
    vector<int> v2 ={1,2,4};
    vector<int> v3 ={1,1,4};
    vector<int> v4 ={2,5,6};
    vector<int> v5 ={1,1,1};

    Element<int, int> e1(v1, v1);
    Element<int, int> e2(v2, v2);
    Element<int, int> e3(v3, v3);
    Element<int, int> e4(v4, v4);
    Element<int, int> e5(v5, v5);

    vector<Element<int, int>> vect;
    vect.push_back(e1);
    vect.push_back(e2);
    vect.push_back(e3);
    vect.push_back(e4);
    vect.push_back(e5);

    ElementContainer<int, int> cont(vect, 5, 3, 3);
    cont.pareSorting();
    int x;

    return 0;
}
