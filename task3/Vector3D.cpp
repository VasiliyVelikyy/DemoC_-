// Составить описание класса для объектов-векторов, 
// задаваемых координатами концов в трехмерном пространстве. 
// Обеспечить операции сложения и вычитания векторов с 
// получением нового вектора (суммы или разности), вычисления 
// скалярного произведения двух векторов, длины вектора,  
// косинуса угла между векторами. Операции реализовать через 
// перегрузку операторов.

#include <iostream>
#include <cmath>
using namespace std;

// Класс для объектов-векторов в трехмерном пространстве
class Vector3D {
private:
    double x, y, z;  // Координаты вектора

public:
    // Конструктор для инициализации координат вектора
    Vector3D(double x0 = 0.0, double y0 = 0.0, double z0 = 0.0) : x(x0), y(y0), z(z0) {}

    // Метод для вывода вектора
    void display() const {
        cout << "Вектор: (" << x << ", " << y << ", " << z << ")\n";
    }

    // Перегрузка оператора сложения
    Vector3D operator + (const Vector3D& other) const {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }

    // Перегрузка оператора вычитания
    Vector3D operator - (const Vector3D& other) const {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }

    // Перегрузка оператора скалярного произведения
    double operator * (const Vector3D& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    // Метод для вычисления длины вектора
    double length() const {
        return sqrt(x * x + y * y + z * z);
    }

    // Метод для вычисления косинуса угла между двумя векторами
    double cosine(const Vector3D& other) const {
        double dotProduct = *this * other;  // Скалярное произведение
        double lengthsProduct = this->length() * other.length();  // Произведение длин векторов
        if (lengthsProduct == 0) {
            return 0;  // Защита от деления на 0
        }
        return dotProduct / lengthsProduct;
    }

    // Перегрузка оператора вывода для вектора
    friend ostream& operator<<(ostream& out, const Vector3D& vec) {
        out << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
        return out;
    }
};

int main() {
    // Создаем два вектора
    Vector3D v1(3.0, 4.0, 5.0);
    Vector3D v2(1.0, 2.0, 3.0);

    // Выводим векторы
    cout << "Вектор 1: " << v1 << endl;
    cout << "Вектор 2: " << v2 << endl;

    // Операция сложения векторов
    Vector3D sum = v1 + v2;
    cout << "Сумма векторов: " << sum << endl;

    // Операция вычитания векторов
    Vector3D diff = v1 - v2;
    cout << "Разность векторов: " << diff << endl;

    // Вычисление скалярного произведения
    double scalarProduct = v1 * v2;
    cout << "Скалярное произведение: " << scalarProduct << endl;

    // Вычисление длины вектора
    cout << "Длина вектора 1: " << v1.length() << endl;
    cout << "Длина вектора 2: " << v2.length() << endl;

    // Вычисление косинуса угла между векторами
    cout << "Косинус угла между векторами: " << v1.cosine(v2) << endl;

    return 0;
}