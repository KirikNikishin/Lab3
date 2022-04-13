// Лаба 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//Создать абстрактный класс «римское число». Объявить в классе следующие функции:
//ToString() : String, возвращающую строковое представление числа;
//ToDouble() : Double, возвращающую арабское представление числа.
//Унаследовать от этого класса два других : «целое римское число» и «вещественное римское число».
//В основном коде программы реализовать функцию сложения полиморфных(как целых так и вещественных) римских чисел.
//Применить функцию к массиву полиморфных римских чисел и вывести результат сложения на экран.
//Усложнение 1 (+2 балла). Определить перегруженную операцию присваивания к римскому числу строки. 
//Проверить работоспособность на массиве полиморфных адресов.
//Усложнение 2(+2 балла).Определить перегруженную операцию присваивания к римскому числу числа типа double.
//Проверить работоспособность на массиве полиморфных адресов.


#include <iostream>
#include <string>
#include <cmath>
#include "Number.h"
using namespace std;
class RimNumber {
private:
    int i = 0;
    int tens = 1;
    double number_arab;
    double number_aint = 0;
protected:
    int length;
    string number_ar;
    bool point = false;
    bool slash = false;
    string data;
public:
    RimNumber(string d) : data(d) {}
    virtual ~RimNumber() {}
    virtual string ToString(double number_arab) {
        number_ar = to_string(number_arab);
        return number_ar;
    }
    virtual double ToDouble(string number_rim) {
        length = number_rim.length();
        for (i = length - 1; i >= 0; i--) {
            if ((number_rim[i] == 'i') or (number_rim[i] == 'I')) {
                if ((number_rim[i + 1] == 'v') or (number_rim[i + 1] == 'V') or (number_rim[i + 1] == 'x') or (number_rim[i + 1] == 'X')) {
                    number_arab += 0;
                }
                else {
                    number_arab += 1;
                }
            }
            if ((number_rim[i] == 'v') or (number_rim[i] == 'V')) {
                if ((number_rim[i - 1] == 'i') or (number_rim[i - 1] == 'I')) {
                    number_arab += 4;
                }
                else {
                    number_arab += 5;
                }
            }
            if ((number_rim[i] == 'x') or (number_rim[i] == 'X')) {
                if ((number_rim[i - 1] == 'i') or (number_rim[i - 1] == 'I')) {
                    number_arab += 9;
                }
                else {
                    if ((number_rim[i + 1] == 'l') or (number_rim[i + 1] == 'L') or (number_rim[i + 1] == 'c') or (number_rim[i + 1] == 'C')) {
                        number_arab += 0;
                    }
                    else {
                        number_arab += 10;
                    }
                }
            }
            if ((number_rim[i] == 'l') or (number_rim[i] == 'L')) {
                if ((number_rim[i - 1] == 'x') or (number_rim[i - 1] == 'X')) {
                    number_arab += 40;
                }
                else {
                    number_arab += 50;
                }
            }
            if ((number_rim[i] == 'c') or (number_rim[i] == 'C')) {
                if ((number_rim[i - 1] == 'x') or (number_rim[i - 1] == 'X')) {
                    number_arab += 90;
                }
                else {
                    if ((number_rim[i + 1] == 'd') or (number_rim[i + 1] == 'D') or (number_rim[i + 1] == 'm') or (number_rim[i + 1] == 'M')) {
                        number_arab += 0;
                    }
                    else {
                        number_arab += 100;
                    }
                }
            }
            if ((number_rim[i] == 'd') or (number_rim[i] == 'D')) {
                if ((number_rim[i - 1] == 'c') or (number_rim[i - 1] == 'C')) {
                    number_arab += 400;
                }
                else {
                    number_arab += 500;
                }
            }
            if ((number_rim[i] == 'm') or (number_rim[i] == 'M')) {
                if ((number_rim[i - 1] == 'c') or (number_rim[i - 1] == 'C')) {
                    number_arab += 900;
                }
                else {
                    number_arab += 1000;
                }
            }
        }
        return number_arab;
    }
    virtual double arab_ToDouble(string number_arabic) {
        length = number_arabic.length();
        for (i = length - 1; i >= 0; i--) {
            if (number_arabic[i] == '0') {
                number_aint += 0 * tens;
                tens *= 10;
            }
            if (number_arabic[i] == '1') {
                number_aint += 1 * tens;
                tens *= 10;
            }
            if (number_arabic[i] == '2') {
                number_aint += 2 * tens;
                tens *= 10;
            }
            if (number_arabic[i] == '3') {
                number_aint += 3 * tens;
                tens *= 10;
            }
            if (number_arabic[i] == '4') {
                number_aint += 4 * tens;
                tens *= 10;
            }
            if (number_arabic[i] == '5') {
                number_aint += 5 * tens;
                tens *= 10;
            }
            if (number_arabic[i] == '6') {
                number_aint += 6 * tens;
                tens *= 10;
            }
            if (number_arabic[i] == '7') {
                number_aint += 7 * tens;
                tens *= 10;
            }
            if (number_arabic[i] == '8') {
                number_aint += 8 * tens;
                tens *= 10;
            }
            if (number_arabic[i] == '9') {
                number_aint += 9 * tens;
                tens *= 10;
            }
        }
        return number_aint;
    }
};

class IntRimNumber: public RimNumber {
private:
    int i = 0;
    int tens = 1;
    double error = 0;
    double number_arab;
    int number_aint = 0;
protected:
    string ToString(double number_arab) override {
        int number_arint = (int)number_arab;
        number_ar = to_string(number_arint);
        return number_ar;
    }
    double ToDouble(string number_rim) override {
        length = number_rim.length();
        for (i = length - 1; i >= 0; i--) {
            if (number_rim == "." or number_rim == ",") {
                point = true;
            }
            if (number_rim == "/") {
                slash = true;
            }
        }
        if ((point) or (slash)) {
            cout << "This is the fraction. Changing interface on real numbers..." << endl;
            error = 999999999;
            return error;
        }
        else {
            if ((number_rim[i] == 'i') or (number_rim[i] == 'I')) {
                if ((number_rim[i + 1] == 'v') or (number_rim[i + 1] == 'V') or (number_rim[i + 1] == 'x') or (number_rim[i + 1] == 'X')) {
                    number_arab += 0;
                }
                else {
                    number_arab += 1;
                }
            }
            if ((number_rim[i] == 'v') or (number_rim[i] == 'V')) {
                if ((number_rim[i - 1] == 'i') or (number_rim[i - 1] == 'I')) {
                    number_arab += 4;
                }
                else {
                    number_arab += 5;
                }
            }
            if ((number_rim[i] == 'x') or (number_rim[i] == 'X')) {
                if ((number_rim[i - 1] == 'i') or (number_rim[i - 1] == 'I')) {
                    number_arab += 9;
                }
                else {
                    if ((number_rim[i + 1] == 'l') or (number_rim[i + 1] == 'L') or (number_rim[i + 1] == 'c') or (number_rim[i + 1] == 'C')) {
                        number_arab += 0;
                    }
                    else {
                        number_arab += 10;
                    }
                }
            }
            if ((number_rim[i] == 'l') or (number_rim[i] == 'L')) {
                if ((number_rim[i - 1] == 'x') or (number_rim[i - 1] == 'X')) {
                    number_arab += 40;
                }
                else {
                    number_arab += 50;
                }
            }
            if ((number_rim[i] == 'c') or (number_rim[i] == 'C')) {
                if ((number_rim[i - 1] == 'x') or (number_rim[i - 1] == 'X')) {
                    number_arab += 90;
                }
                else {
                    if ((number_rim[i + 1] == 'd') or (number_rim[i + 1] == 'D') or (number_rim[i + 1] == 'm') or (number_rim[i + 1] == 'M')) {
                        number_arab += 0;
                    }
                    else {
                        number_arab += 100;
                    }
                }
            }
            if ((number_rim[i] == 'd') or (number_rim[i] == 'D')) {
                if ((number_rim[i - 1] == 'c') or (number_rim[i - 1] == 'C')) {
                    number_arab += 400;
                }
                else {
                    number_arab += 500;
                }
            }
            if ((number_rim[i] == 'm') or (number_rim[i] == 'M')) {
                if ((number_rim[i - 1] == 'c') or (number_rim[i - 1] == 'C')) {
                    number_arab += 900;
                }
                else {
                    number_arab += 1000;
                }
            }
        }
        return number_arab;
    }
    double arab_ToDouble(string number_arabic) override {
        length = number_arabic.length();
        for (i = length - 1; i >= 0; i--) {
            if (number_arabic[i] == '0') {
                number_aint += 0 * tens;
                tens *= 10;
            }
            if (number_arabic[i] == '1') {
                number_aint += 1 * tens;
                tens *= 10;
            }
            if (number_arabic[i] == '2') {
                number_aint += 2 * tens;
                tens *= 10;
            }
            if (number_arabic[i] == '3') {
                number_aint += 3 * tens;
                tens *= 10;
            }
            if (number_arabic[i] == '4') {
                number_aint += 4 * tens;
                tens *= 10;
            }
            if (number_arabic[i] == '5') {
                number_aint += 5 * tens;
                tens *= 10;
            }
            if (number_arabic[i] == '6') {
                number_aint += 6 * tens;
                tens *= 10;
            }
            if (number_arabic[i] == '7') {
                number_aint += 7 * tens;
                tens *= 10;
            }
            if (number_arabic[i] == '8') {
                number_aint += 8 * tens;
                tens *= 10;
            }
            if (number_arabic[i] == '9') {
                number_aint += 9 * tens;
                tens *= 10;
            }
    }
        return number_aint;
    }
    public: 
        IntRimNumber(string d) : RimNumber(d) {}
        virtual ~IntRimNumber() {}
    
};

class RealRimNumber: public RimNumber {
private:
    int i = 0;
    int integer = 0;
    int enter = 0;
    int tens = 1;
    double error = 0;
    double number_arab;
    double number_adouble = 0;
protected:
    string ToString(double number_arab) override {
        number_ar = to_string(number_arab);
        return number_ar;
    }
    double ToDouble(string number_rim) override {
        length = number_rim.length();
        for (i = 0; i < length; i++) {
            if (number_rim == "." or number_rim == ",") {
                point = true;
                enter = i;
            }
            if (number_rim == "/") {
                slash = true;
                enter = i;
            }
            
        }
        if ((point) and (slash)) {
            cout << "Incorrect enter" << endl;
            exit(1);
        }
        if (!(point) and !(slash)) {
            cout << "This is not the fraction. Changing interface on real numbers..." << endl;
            error = 999999;
            return error;
        }
        if (point) {
            string _integer_1 = "";
            string _integer_2 = "";
            for (i = 0; i < enter; i++) {
                _integer_1 += number_rim[i];
            }
            for (i = enter + 1; i < length; i++) {
                _integer_2 += number_rim[i];
            }
            double _final_1 = Translate(_integer_1);
            double _final_2 = Translate(_integer_2);
            _final_2 /= pow(10, _integer_2.length());
            double final = _final_1 + _final_2;
            return final;
        }
        if (slash) {
            string _integer_1 = "";
            string _integer_2 = "";
            for (i = 0; i < enter; i++) {
                _integer_1 += number_rim[i];
            }
            for (i = enter + 1; i < length; i++) {
                _integer_2 += number_rim[i];
            }
            double _final_1 = Translate(_integer_1);
            double _final_2 = Translate(_integer_2);
            //_final_2 /= pow(10, _integer_2.length());
            //double final = _final_1 + _final_2;
            cout << _final_1 << "/" << _final_2 << endl;
        }
    }
    double Translate(string number_rim) {
        length = number_rim.length();
        for (i = length - 1; i >= 0; i--) {
            if (number_rim == "." or number_rim == ",") {
                point = true;
            }
            if (number_rim == "/") {
                slash = true;
            }
        }
        if ((point) or (slash)) {
            cout << "This is the fraction. Changing interface on real numbers..." << endl;
            error = 999999999;
            return error;
        }
        else {
            if ((number_rim[i] == 'i') or (number_rim[i] == 'I')) {
                if ((number_rim[i + 1] == 'v') or (number_rim[i + 1] == 'V') or (number_rim[i + 1] == 'x') or (number_rim[i + 1] == 'X')) {
                    number_arab += 0;
                }
                else {
                    number_arab += 1;
                }
            }
            if ((number_rim[i] == 'v') or (number_rim[i] == 'V')) {
                if ((number_rim[i - 1] == 'i') or (number_rim[i - 1] == 'I')) {
                    number_arab += 4;
                }
                else {
                    number_arab += 5;
                }
            }
            if ((number_rim[i] == 'x') or (number_rim[i] == 'X')) {
                if ((number_rim[i - 1] == 'i') or (number_rim[i - 1] == 'I')) {
                    number_arab += 9;
                }
                else {
                    if ((number_rim[i + 1] == 'l') or (number_rim[i + 1] == 'L') or (number_rim[i + 1] == 'c') or (number_rim[i + 1] == 'C')) {
                        number_arab += 0;
                    }
                    else {
                        number_arab += 10;
                    }
                }
            }
            if ((number_rim[i] == 'l') or (number_rim[i] == 'L')) {
                if ((number_rim[i - 1] == 'x') or (number_rim[i - 1] == 'X')) {
                    number_arab += 40;
                }
                else {
                    number_arab += 50;
                }
            }
            if ((number_rim[i] == 'c') or (number_rim[i] == 'C')) {
                if ((number_rim[i - 1] == 'x') or (number_rim[i - 1] == 'X')) {
                    number_arab += 90;
                }
                else {
                    if ((number_rim[i + 1] == 'd') or (number_rim[i + 1] == 'D') or (number_rim[i + 1] == 'm') or (number_rim[i + 1] == 'M')) {
                        number_arab += 0;
                    }
                    else {
                        number_arab += 100;
                    }
                }
            }
            if ((number_rim[i] == 'd') or (number_rim[i] == 'D')) {
                if ((number_rim[i - 1] == 'c') or (number_rim[i - 1] == 'C')) {
                    number_arab += 400;
                }
                else {
                    number_arab += 500;
                }
            }
            if ((number_rim[i] == 'm') or (number_rim[i] == 'M')) {
                if ((number_rim[i - 1] == 'c') or (number_rim[i - 1] == 'C')) {
                    number_arab += 900;
                }
                else {
                    number_arab += 1000;
                }
            }
        }
        return number_arab;
    }
    double arab_ToDouble(string number_arabic) override {
        length = number_arabic.length();
        for (i = length - 1; i >= 0; i--) {
            if (number_arabic[i] == '0') {
                number_adouble += 0 * tens;
                tens *= 10;
            }
            if (number_arabic[i] == '1') {
                number_adouble += 1 * tens;
                tens *= 10;
            }
            if (number_arabic[i] == '2') {
                number_adouble += 2 * tens;
                tens *= 10;
            }
            if (number_arabic[i] == '3') {
                number_adouble += 3 * tens;
                tens *= 10;
            }
            if (number_arabic[i] == '4') {
                number_adouble += 4 * tens;
                tens *= 10;
            }
            if (number_arabic[i] == '5') {
                number_adouble += 5 * tens;
                tens *= 10;
            }
            if (number_arabic[i] == '6') {
                number_adouble += 6 * tens;
                tens *= 10;
            }
            if (number_arabic[i] == '7') {
                number_adouble += 7 * tens;
                tens *= 10;
            }
            if (number_arabic[i] == '8') {
                number_adouble += 8 * tens;
                tens *= 10;
            }
            if (number_arabic[i] == '9') {
                number_adouble += 9 * tens;
                tens *= 10;
            }
        }
    }
    public:
        RealRimNumber(string d) : RimNumber(d) {}
        virtual ~RealRimNumber() {}
};

int main()
{
    int choise;
    const size_t i = 0;
    int choise_1;
    int choise_2;
    string roman;
    string arab;
    cout << "What numbers do you want to work with?" << endl;
    cout << "Enter 1 if you want to work with numerals in string format" << endl;
    cout << "Enter 2 if you want to work with numerals in double format" << endl;
    cin >> choise;
    if (choise == 1) {
        cout << "Enter 1 if you want to work with roman numerals" << endl;
        cout << "Enter 2 if you want to work with arabic numerals" << endl;
        cin >> choise_1;
        if (choise_1 == 1) {
            cout << "Enter 1 if you want to work with integer numbers" << endl;
            cout << "Enter 2 if you want to work with real numbers" << endl;
            cin >> choise_2;
            if (choise_2 == 1) {
                cout << "Enter your numbers" << endl;
                RimNumber *list[4];
                for (size_t i = 0; i < 4; i++) {
                    cin >> roman;
                    list[i] = new IntRimNumber(roman);
                    
                }
                }
                cout << "Your answer is ..." << endl;
                //Roman_integer(list);
                for (size_t i = 0; i < 4; i++) {
                    IntRimNumber a(roman);
                    a.ToDouble(list[i]);
                }
            }
        }
    }

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

