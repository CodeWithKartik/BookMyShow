#ifndef PERSISTENTOBJECTUTILITY_H_INCLUDED
#define PERSISTENTOBJECTUTILITY_H_INCLUDED

#include <vector>

static const char FileNameSuffix[] = "PersistentObjectUtility.txt";
template <class DataType> class PersistentObjectUtility {
protected:
    const char *filename;
    DataType *database_object;
public:
    PersistentObjectUtility(DataType &obj);
    void ReadFromFile(std::vector<char> &file_array);
    void WriteToFile();
    ~PersistentObjectUtility();
};

#endif // PERSISTENTOBJECTUTILITY_H_INCLUDED
