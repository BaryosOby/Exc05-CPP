#ifndef EX5_DATABASE_H
#define EX5_DATABASE_H
#include <fstream>
#include <iostream>
#include <ios>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "ElementContainer.h"


using namespace std;

class dataBase {
//    class inFileNotFoundException{};
//    class outFileNotFoundException{};
//    class firstRowException{};
//    class populationException{
//        int line;
//        populationException(int line):line(line){}
//        int
    private:
    void clear();
    ElementContainer<double,double> container;
    int numOfElems;
    int vectorSize;
    int fxSize;
    int iterations;

    class dataBaseException{
    private:
        string e;
    public:
        dataBaseException(string e):e(e){}
        string& getE(){return e;}
    };

    ifstream input;
    ofstream output;

    vector<double> targetVect(const vector<double>& x);

    double generateRandNormal();


public:
    dataBase(string input , string output);
    void addRandElements();
    void run();



    };


#endif
