#include "journaldata.h"

JournalData::JournalData(string f_name, string m_name, string l_name,
                          string pos, string deg, int influenceMade)
    : firstName(f_name),
      middleName(m_name),
      lastName(l_name),
      position(pos),
      degree(deg),
      influence(influenceMade)
{}

string JournalData::GetFullName() const {
    if (firstName.empty() || middleName.empty() || lastName.empty()) {
    return "No name";
    } else return firstName + ' ' + middleName + ' ' + lastName;
} // не меняет поля имен в классе

string JournalData::GetPosition() const {
    if (position.empty())
        return "No position";
    return position;
}


string JournalData::GetDegree() const {
    if (degree.empty())
        return "No degree";
    return degree;
}

void JournalData::ChangeCoffeAmount(int madeInfluence) {
    influence += madeInfluence;
}

int JournalData::GetCoffeeAmount() const {
    return influence;
}

void JournalData::Clear() {
    firstName.clear();
    middleName.clear();
    lastName.clear();
    position.clear();
    degree.clear();
    influence = 0;
}

bool JournalData::operator==(const JournalData &jd) {
    return degree == jd.degree && position == jd.position && influence == jd.influence
    && firstName == jd.firstName && middleName == jd.middleName && lastName == jd.lastName;
}

JournalData::~JournalData() {
    firstName.clear();
    middleName.clear();
    lastName.clear();
    degree.clear();
    position.clear();
    influence = 0;
}
