#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <regex>



class DataStore{

private: 
    static DataStore *instance;
    std::string data;
    bool firstTime;
    

    DataStore(){
        data = "";
        firstTime = true;
    }

public:
   

    static DataStore *getInstance(){
        if(!instance){
            instance = new DataStore;
        }
        return instance;
    }


    std::string getData(){
        return data;
    }

    void setData(std::string newData){
        data = newData;
    }

    bool getFirstTime(){
        return firstTime;
    }

    void setfirstTime(){
        firstTime = false;
    }

    std::string checkRegex(std::string fileName, std::string regexPattern){
   
    std::string line;
    
    std::ifstream example_file;
    example_file.open(fileName);
    

    if(example_file.is_open()){
        
         while ( getline(example_file, line) ) {
            std::regex reg(regexPattern);
            std::smatch matches;  

            std::regex_search(line, matches, reg);
            /* std::cout << matches.str(1);   */
            bool isMatch = regex_search(line, reg);
           if (isMatch){
           return matches.str(1);
           }
        }
        example_file.close();

    }

    return "No Results";

    }


    void writeToFile(std::string fileName, std::string Error){
    std::ofstream example_file;

    if(getFirstTime()){
    example_file.open(fileName);
    setfirstTime();
   }
   else {
    example_file.open(fileName, std::ofstream::out | std::ofstream::app);
   }

    if(example_file.is_open()){
        
        example_file << Error + "\n";

        example_file.close();
    } else {
        std::cerr << "Unable to open Output File";
    }
}




};

DataStore *DataStore::instance = nullptr;

int main(){


    DataStore *s = s->getInstance();
    

  
    std::string pattern1 = s->checkRegex("test.txt", "(\\d{3}-\\d{3}-\\d{4})");
    s->writeToFile("writtenTo", pattern1);


  
    
    DataStore *t = t->getInstance();
    std::string pattern2 = t->checkRegex("test.txt", "(Cat)");
    t->writeToFile("writtenTo", pattern2);




  return 0;  
}
