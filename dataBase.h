#ifndef EX5_DATABASE_H
#define EX5_DATABASE_H
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "ElementContainer.h"
#include <random>

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
    ifstream output;

    vector<double> targetVect(const vector<double>& x);


public:
    dataBase(string input , string output);
    void addRandElements();
    void run();



    };


#endif
