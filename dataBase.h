#ifndef EX5_DATABASE_H
#define EX5_DATABASE_H
#include <fstream>
#include <iostream>
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
    class dataBaseException{
    private:
        string e;
    public:
        dataBaseException(string e):e(e){}
        string& getE(){return e;}
    };
        ifstream input;
        ifstream output;
public:
    dataBase(string input , string output);



    };


#endif //EX5_DATABASE_H
