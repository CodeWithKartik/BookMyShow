#include "PersistentObjectUtility.h"
#include "UserDatabase.h"
#include <typeinfo>
#include <cstring>
#include <fstream>

template <class DataType> PersistentObjectUtility<DataType>::PersistentObjectUtility(DataType &obj):
    filename(std::strcat((std::strcpy((new char[strlen(typeid(obj).name())+strlen(FileNameSuffix)+1]), typeid(obj).name())), FileNameSuffix)) {
    database_object = &obj;
}
template <class DataType> PersistentObjectUtility<DataType>::~PersistentObjectUtility() {
    delete[] filename;
}
template <class DataType> void PersistentObjectUtility<DataType>::ReadFromFile(std::vector<char> &file_array) {
    std::ifstream persistent_file;
    persistent_file.open(filename);
    if (persistent_file.is_open()) {
        char c;
        while (persistent_file.get(c)) {
            file_array.push_back(c);
        }
    }
    persistent_file.close();
}
template <class DataType> void PersistentObjectUtility<DataType>::WriteToFile() {
    std::ofstream persistent_file;
    persistent_file.open(filename);
    persistent_file<<*database_object;
    persistent_file.close();
}
//Template types to be used in this project
template class PersistentObjectUtility<UserDatabase>;
