#include "dataBase.h"

dataBase::dataBase(string sInput, string sOutput) {
    vector<Element<double, double> > elementsVector;
    int mu = -1, m = -1, n = -1, steps = -1;
    string line;
    input.open(sInput.c_str(), ios::in);
    if (!input) {
        throw dataBaseException("ERROR: init.dat does not exist or cannot be opened\n");
    }
    output.open(sOutput.c_str(), ios:: out);
    if (!output) {
        throw dataBaseException("ERROR: output.dat does not exist or cannot be opened\n");
    }
    getline(input, line);
    stringstream firstLine(line);
    firstLine >> mu;
    firstLine >> n;
    firstLine >> m;
    firstLine >> steps;
    if (mu == -1 || n == -1 || m == -1 || steps == -1) {
        throw dataBaseException("ERROR: simulation definition in input.dat is invalid\n");
    }
    numOfElems = mu;
    vectorSize = n;
    fxSize = m;
    iterations = steps;
    int rowCounter = 0;
    double tempDouble;
    stringstream getDoubles(line);
    tempDouble = 0;
    vector<double> row;
    while (getline(input, line)) {
        //to do what kind of exception to throw if number of rows is wrong
        int j =0;
        while (getDoubles >> tempDouble) {
            if (j == 0) { row = vector<double>(); }
            if (j == n || rowCounter == mu) {
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
                rowCounter++;
            }
            row.push_back(tempDouble);
            j++;
        }
        if (rowCounter != mu){
            //throw something
        }
        if(j != n){
            stringstream convert;
            string row;
            convert << rowCounter + 1;
            convert >> row;
            throw dataBaseException("ERROR: population definition in init.dat at line " + row + " is invalid\n");
        }
        Element<double,double> temp = Element<double,double>(row);
        vector<double> target = targetVect(row);
        temp.setfX(target);
        elementsVector.push_back(temp);
        rowCounter++;
    }
}

vector<double> dataBase::targetVect(const vector<double> &x) {
    vector<double> targets;
    for(int m = 0; m < fxSize; m++){
        double res = 0;
        for(int n = 0; n < vectorSize; n++){
            res += (x[n] - (m + 1)) * (x[n] - (m + 1));
        }
        targets.push_back(res);
    }
    return targets;
}


double dataBase::generateRandNormal() {
    double x = 0;
    for(int i = 0; i < 12; i++){
        x += ((double)rand() / RAND_MAX);
    }
    x -= 6;
    return x;
}


void dataBase::addRandElements() {

    // init new random x vector for every element in the container
    for(int i = 0; i < numOfElems; i++){
        vector<double> randVect = container.getElements()[i].getX();

        // adds random number to the x vector of element[i]
        for(int j = 0; j < vectorSize; j++){
            randVect[j] += generateRandNormal();
        }

        // creates new Element with the random vector and adds it to the container.
        Element<double, double> newElem(randVect);
        vector<double> target = targetVect(randVect);
        newElem.setfX(target);
        container.addElement(newElem);

    }

}

void dataBase::run() {
    srand(time(NULL));
    for(int i = 0; i < iterations; i++){
        addRandElements();
        container.pareSorting();
        container.removeKElements(numOfElems);
    }

    string newLine = "";
    for(int j = 0; j < numOfElems; j++){
        output << newLine << container.getElements()[j];
        newLine = "\n";
    }

}



