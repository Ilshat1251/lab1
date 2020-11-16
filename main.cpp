#include "journal.h"
#include <fstream>
#include <cassert>

void TestJournal() {
    JournalData Monday("Yakupov", "Ilshat", "Bulatovich", "Worker", "Magister");

   JournalData Tuesday(Monday);
    Journal J;
    J.AddData(Monday);
    J.AddData(Tuesday);
    J.CheckJournal();
    J.GetData(0);
    assert(J.Size() == 2);
    J.DeleteData(1);
    J.ClearAll();
    //Journal J2(J);
   // assert(J2 == J);
    cout << "OK" << endl;
}

int main() {
    setlocale(LC_ALL,"Russian");
    TestJournal();

    return 0;
}
