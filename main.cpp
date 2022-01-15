#include "dataBase.h"

using namespace std;



int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "ERROR: no\n";
        exit(1);
    }
    try {
        dataBase dataO(argv[1], argv[2]);
        dataO.run();
    }
    catch (dataBase ::dataBaseException error){
        cerr<<error.getE();
        exit(1);
    }

    return 0;
}
