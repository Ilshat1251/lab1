#include <string>

using namespace std;

class JournalData{
public:
    JournalData() = default;
    JournalData(string fname, string mname, string lname,
                string position, string degree, int influenceMade = 0);
    ~JournalData();
    JournalData& operator=(const JournalData &) = default;
    bool operator==(const JournalData &jd);

    // селекторы
    string GetFullName() const;
    string GetPosition() const;
    string GetDegree() const;
    int GetCoffeeAmount() const;

    // модификатор
    void ChangeCoffeAmount(int madeInfluence);
    void Clear();

private:
    string firstName, middleName, lastName; // Имя, Отчество, Фамилия
    string position, degree;
    int influence = 0;                      // инициализация 0
};
