// Создать класс для хранения информации о студентах 
// института (фамилия, имя, группа, средний балл). Необходимо 
// вывести на экран фамилию, имя студента и средний балл 
// студентов одной группы, отсортированных по алфавиту

#include <iostream>
#include <vector>
#include <algorithm>  // Для сортировки
#include <string>
using namespace std;

class Student {
private:
    string lastName;  // Фамилия студента
    string firstName; // Имя студента
    string group;     // Группа студента
    double averageGrade; // Средний балл студента

public:
    // Конструктор для инициализации студента
    Student(string lastName, string firstName, string group, double averageGrade)
        : lastName(lastName), firstName(firstName), group(group), averageGrade(averageGrade) {}

    // Геттеры для доступа к данным студента
    string getLastName() const { return lastName; }
    string getFirstName() const { return firstName; }
    string getGroup() const { return group; }
    double getAverageGrade() const { return averageGrade; }

    // Метод для вывода информации о студенте
    void display() const {
        cout << "Фамилия: " << lastName << ", Имя: " << firstName << ", Средний балл: " << averageGrade << endl;
    }

    // Статическая функция для сортировки студентов по фамилии
    static bool compareByLastName(const Student& a, const Student& b) {
        return a.getLastName() < b.getLastName();  // Сортировка по фамилии в алфавитном порядке
    }
};

int main() {
    // Создаем несколько студентов
    vector<Student> students = {
        Student("Иванов", "Иван", "Группа1", 4.5),
        Student("Петров", "Петр", "Группа2", 4.8),
        Student("Смирнов", "Алексей", "Группа1", 3.9),
        Student("Кузнецова", "Елена", "Группа1", 4.2),
        Student("Лебедев", "Максим", "Группа2", 4.7)
    };

    // Группа, для которой нужно вывести студентов
    string groupToDisplay = "Группа1";

    // Фильтруем студентов по группе
    vector<Student> groupStudents;
    for (const auto& student : students) {
        if (student.getGroup() == groupToDisplay) {
            groupStudents.push_back(student);
        }
    }

    // Сортируем студентов по фамилии
    sort(groupStudents.begin(), groupStudents.end(), Student::compareByLastName);

    // Выводим информацию о студентах из выбранной группы
    cout << "Студенты группы " << groupToDisplay << ", отсортированные по фамилии:\n";
    for (const auto& student : groupStudents) {
        student.display();
    }

    return 0;
}