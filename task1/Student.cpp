//  Создать структуру, которая будет содержать данные о 
// студентах института (фамилия, имя, группа, средний балл). С 
// помощью функции-члена класса необходимо вывести на экран 
// фамилию, имя студента и номер группы. Создать аналогичный 
// класс. 

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

// Структура для хранения данных о студенте
struct Student {
    std::string lastName; // Фамилия
    std::string firstName; // Имя
    std::string group; // Группа
    double averageGrade; // Средний балл

    // Функция-член для вывода фамилии, имени и группы
    void printBasicInfo() const {
        std::cout << "Фамилия: " << lastName
                  << ", Имя: " << firstName
                  << ", Группа: " << group << '\n';
    }
};

// Класс для хранения данных о студенте
class StudentClass {
private:
    std::string lastName; // Фамилия
    std::string firstName; // Имя
    std::string group; // Группа
    double averageGrade; // Средний балл

public:
    // Конструктор
    StudentClass(const std::string &lastName, const std::string &firstName, const std::string &group, double averageGrade)
        : lastName(lastName), firstName(firstName), group(group), averageGrade(averageGrade) {}

    // Метод для вывода фамилии, имени и группы
    void printBasicInfo() const {
        std::cout << "Фамилия: " << lastName
                  << ", Имя: " << firstName
                  << ", Группа: " << group << '\n';
    }
};

int main() {
    // Использование структуры
    Student student = {"Иванов", "Иван", "Б01-123", 4.5};
    std::cout << "Данные студента (структура):\n";
    student.printBasicInfo();

    // Использование класса
    StudentClass studentClass("Петров", "Петр", "Б02-456", 4.8);
    std::cout << "\nДанные студента (класс):\n";
    studentClass.printBasicInfo();

    return 0;
}
