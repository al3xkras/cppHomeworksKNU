#include <iostream>
#include "src/main/NumberFile.h"

void openFile(NumberFile &numberFile, const std::string &filename){
    try {
        numberFile.open(filename,std::fstream::in | std::fstream::out);
    } catch(std::exception){
        numberFile.open(filename,std::fstream::in | std::fstream::out | std::fstream::trunc);
    }
}

void task17_07(){
    NumberFile numberFile;
    try{
    openFile(numberFile,"file.txt");
    //numberFile.inputLines();
    numberFile.close();
    } catch (std::exception){
        std::cout<<"exception 1";
    }
    std::cout<<std::endl<<std::endl<<std::endl;

    try {
        openFile(numberFile,"file.txt");
        numberFile.printLines();
        numberFile.close();
    } catch (std::exception){
        std::cout<<"exception 2";
    }
    std::cout<<std::endl<<std::endl<<std::endl;

    try {
    openFile(numberFile,"file.txt");
    numberFile.removeByLineAndIndex(1,1);
    numberFile.printLines();
    numberFile.close();
    } catch (std::exception){
        std::cout<<"exception 3";
    }
    std::cout<<std::endl<<std::endl<<std::endl;

    try {
    openFile(numberFile,"file.txt");
    std::cout<<"Element with index 5: "<<numberFile.getByIndex(4);
    numberFile.close();
    } catch (std::exception){
        std::cout<<"exception 4";
    }

    try {
        std::vector<double> vector = {2.2,34.2,-7.5};
        openFile(numberFile,"file.txt");
        numberFile.appendLine(vector);
        numberFile.close();
    } catch (std::exception){
        std::cout<<"exception 5";
    }
    std::cout<<std::endl<<std::endl<<std::endl;

    try {
        openFile(numberFile,"file.txt");
        numberFile.removeByLineAndIndex(1,1);
        numberFile.printLines();
        numberFile.close();
    } catch (std::exception){
        std::cout<<"exception 6";
    }
    std::cout<<std::endl<<std::endl<<std::endl;

}

int main() {
    //11 Красовський Олександр 17.07
    task17_07();
    return 0;
}
