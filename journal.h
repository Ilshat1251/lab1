#pragma once

#include <string>
#include <iostream>
#include "journaldata.h"
#include "MyVector.h"

// Коллекция Одномерный массив (Вектор)
class Journal {
public:
    Journal() = default;
    Journal(size_t size);



    void AddData(const JournalData &data);
    void DeleteData(int index);

    const JournalData &GetData(int index) const;    // константная версия ссылки на элемент
    JournalData &GetData(int index);

    void ClearAll();
    int Size() const;
    JournalData operator[](std::size_t index);
    JournalData operator[](std::size_t index) const;

    void SaveToFile(const string &filename);
    void LoadFromFile(const string &filename);

    void CheckJournal() const;
    void operator=(const Journal& jd);

private:
    MyVector<JournalData> collection;
};

ostream &operator<<(ostream &os, const Journal&J);
