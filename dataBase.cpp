//
// Created by elyas on 14/01/2022.
//

#include "dataBase.h"

dataBase::dataBase(string sInput, string sOutput) {
    vector<Element<double, double>> elementsVector;
    int mu, m, n, steps;
    string line;
    input.open(sInput.c_str());
    if (!input) {
        throw dataBaseException("ERROR: init.dat does not exist or cannot be opened\\n");
    }
    output.open(sOutput.c_str());
    if (!output) {
        throw dataBaseException("ERROR: output.dat does not exist or cannot be opened\\n");
    }
    getline(input, line);
    stringstream firstLine(line);
    firstLine >> mu;
    firstLine >> n;
    firstLine >> m;
    firstLine >> steps;
    if (mu == -1 || n == -1 || m == -1 | steps == -1) {
        throw dataBaseException("ERROR: simulation definition in input.dat is invalid\n");
    }
    int j = 0,rowCOunter=0;
    double tempDouble;
    stringstream getDoubles(line);
    tempDouble = 0;
    vector<double> row;
    while (getline(input, line)) {
        //to do what kind of exception to throw if number of rows is wrong
        j =0;
        while (getDoubles >> tempDouble) {
            if (j == 0) { row = vector<double>(); }
            if (j == n || rowCOunter == mu) {
                if (getDoubles >> tempDouble) {
                    /*means there are to many numbers in current line*/
                    /*clear already allocated memory before throwing an exception*/
                    clear();
                    stringstream convert;
                    string row;
                    convert << j + 1;
                    convert >> row;
                    throw dataBaseException("ERROR: population definition in init.dat at line " + row + "is invalid\n");
                }
                elementsVector.push_back(Element<double,double>(row));
                rowCOunter++;
            }
            row.push_back(tempDouble);
            j++;
        }
        if (rowCOunter != mu){
            //throw something
        }
    }
}

