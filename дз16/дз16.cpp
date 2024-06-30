#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <algorithm>
#include <iomanip>
using namespace std;

//struct Student {
//    string surname;
//    string group;
//    int grades[5];
//};
//
//void add(vector<Student>& studs, const Student& stud) {
//    studs.push_back(stud);
//}
//
//void rem(vector<Student>& studs, size_t index) {
//    if (index < studs.size()) {
//        studs.erase(studs.begin() + index);
//    }
//    else {
//        cout << "Індекс поза діапазоном" << endl;
//    }
//}
//
//bool Exc(const Student& stud) {
//    int exc = 0;
//    for (int grade : stud.grades) {
//        if (grade == 5) {
//            exc++;
//        }
//    }
//    return exc > 5 * 0.75;
//}
//
//bool Und(const Student& stud) {
//    int bad = 0;
//    for (int grade : stud.grades) {
//        if (grade == 2 || grade == 3) {
//            bad++;
//        }
//    }
//    return bad > 5 * 0.5;
//}
//
//
//void printExc(const vector<Student>& studs) {
//    cout << "Список відмінників:" << endl;
//    for (const Student& stud : studs) {
//        if (Exc(stud)) {
//            cout << "Прізвище: " << stud.surname << ", Група: " << stud.group << endl;
//        }
//    }
//}
//
//
//void printUnd(const vector<Student>& studs) {
//    cout << "Список невстигаючих студентів:" << endl;
//    for (const Student& stud : studs) {
//        if (Und(stud)) {
//            cout << "Прізвище: " << stud.surname << ", Група: " << stud.group << endl;
//        }
//    }
//}

struct Man {
    string surname;
    string name;
    int age;
    struct {
        int day;
        int month;
        int year;
    } birth;
};

void add(vector<Man>& men, const Man& man) {
    men.push_back(man);
}

void rem(vector<Man>& men, size_t index) {
    if (index < men.size()) {
        men.erase(men.begin() + index);
    }
    else {
        cout << "Індекс поза діапазоном" << endl;
    }
}

void Sort(const vector<Man>& men, bool sortt) {
    vector<Man> Men = men;
    if (sortt) {
        sort(Men.begin(), Men.end(), [](const Man& a, const Man& b) {
            return a.surname < b.surname;
            });
    }
    else {
        sort(Men.begin(), Men.end(), [](const Man& a, const Man& b) {
            return a.name < b.name;
            });
    }

    for (const Man& man : Men) {
        cout << man.surname << " " << man.name << " " << man.age << " "
            << man.birth.day << "-" << man.birth.month << "-" << man.birth.year << endl;
    }
}

void Birth(const vector<Man>& men, int month) {
    cout << "Список іменинників на місяць " << month << ": " << endl;
    for (const Man& man : men) {
        if (man.birth.month == month) {
            cout << man.surname << " " << man.name << " - "
                << man.birth.day << "-" << man.birth.month << "-" << man.birth.year << endl;
        }
    }
}

void search(const vector<Man>& men, const string& surname, const string& name) {
    for (const Man& man : men) {
        if (man.surname == surname && man.name == name) {
            cout << "Знайдено: " << man.surname << " " << man.name << " " << man.age << " "
                << man.birth.day << "-" << man.birth.month << "-" << man.birth.year << endl;
            return;
        }
    }
    cout << "Не знайдено: " << surname << " " << name << endl;
}

void edit(Man& man, const string& news, const string& newn, int newa, int newd, int newm, int newy) {
    man.surname = news;
    man.name = newn;
    man.age = newa;
    man.birth.day = newd;
    man.birth.month = newm;
    man.birth.year = newy;
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //1
    /*vector<Student> stud;

   
    stud.push_back({ "Іванов", "Група1", {5, 4, 5, 5, 5} });
    stud.push_back({ "Петренко", "Група1", {2, 3, 2, 2, 4} });
    stud.push_back({ "Шевченко", "Група2", {5, 5, 5, 4, 5} });
    stud.push_back({ "Коваль", "Група2", {3, 3, 2, 3, 2} });
    stud.push_back({ "Бондаренко", "Група3", {5, 5, 5, 5, 4} });
 
    printExc(stud);

    printUnd(stud);

    Student news = { "Морозов", "Група3", {4, 4, 4, 4, 4} };
    add(stud, news);

    
    rem(stud, 1);

    
    cout << endl << "Оновлені списки після додавання та видалення учнів : " << endl;
    printExc(stud);
    printUnd(stud);*/

    //2

    vector<Man> men;

    men.push_back({ "Іванов", "Іван", 30, {15, 6, 1993} });
    men.push_back({ "Петров", "Петр", 25, {10, 12, 1998} });
    men.push_back({ "Сідоров", "Алекс", 20, {5, 6, 2003} });
    men.push_back({ "Сміт", "Джон", 28, {20, 1, 1995} });
    men.push_back({ "Дое", "Джейн", 22, {25, 6, 2001} });

    cout << "Відсортовано за прізвищем:" << endl;
    Sort(men, true);

    cout << "Відсортовані за іменами: " << endl;
    Sort(men, false);

    cout << "Список іменинників на червень:" << endl;
    Birth(men, 6);

    cout << "Шукайте 'Петров Петр':" << endl;
    search(men, "Петров", "Петр");

    cout << "Запис про редагування 'Іванов Іван':" << endl;
    edit(men[0], "Іванов", "Іван", 31, 15, 6, 1992);
    Sort(men, true);

    cout << "Додавання нового запису:" << endl;
    Man newMan = { "Браун", "Чарли", 26, {30, 7, 1997} };
    add(men, newMan);
    Sort(men, true);

    cout << "Видаляємо другий запис:" << endl;
    rem(men, 1);
    Sort(men, true);

    return 0;
}