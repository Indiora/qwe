#include <iostream>
#include <string>
#include <cctype>
#include <typeinfo>
#include <fstream>
using namespace std;

struct BinKor;
BinKor* CreateNewBinKor (string& user_input);

//Плечо ::= (Длина Груз(Гирька | БинКор))
struct Side {
    short length;// Длинна плеча
    bool isWeight;// Груз или БинКор
    union {
        int weight;//Масса груза
        BinKor* bin_kor;//БинКор
    } data;
};

//БинКор ::= (Плечо Плечо)
struct BinKor {
    Side* right;//Правое плечо
    Side* left;// Левое плечо
};

void right_result_print(int indent, int result){
    for(int i = 0; i < indent; i++){//выводим нужное количество отступов
        std::cout << ("\t");
    }
    std::cout << "right shoulder length: " << result;//Выводим результат рекурсии
    std::cout << '\n' << '\n';
}

void left_result_print(int indent, int result){
    for(int i = 0; i < indent; i++){//выводим нужное количество отступов
        std::cout << ("\t");
    }
    std::cout << "left shoulder length: " << result;//Выводим результат рекурсии
    std::cout << '\n' << '\n';
}

void right_left_result_print(int indent, int result){
    for(int i = 0; i < indent; i++){//выводим нужное количество отступов
        std::cout << ("\t");
    }
    std::cout << "right + left shoulders length: " << result;;//Выводим результат рекурсии
    std::cout << '\n' << '\n';
}

short SumLength (const BinKor bin_kor, int indentr, int indentl) {//Функция для поиска длины
    short result = 0;
    if (bin_kor.right) {//Если есть правое плечо
        result += bin_kor.right->length;
        right_result_print(indentr, result);// Выводим результат
        if (!bin_kor.right->isWeight)//Если груз
            result += SumLength(*bin_kor.right->data.bin_kor, indentr + 1, indentl + 1);
    }
    if (bin_kor.left) {//Если есть левое плечо
        result += bin_kor.left->length;
        left_result_print(indentl, bin_kor.left->length);

        if (!bin_kor.left->isWeight)//Если груз
            result += SumLength(*bin_kor.left->data.bin_kor, indentr + 1, indentl + 1);
            right_left_result_print(indentl, result);// Выводим результат
    }
    return result;//Возвращает результат
}


void Drop (std::string& str, int n) {
    if (str.length() >= n) {//Если длинна больше или равно
        str = str.substr(n);//Отрезаем лишнии символы
    }
}


short ReadNumber (string& str) {
    string number = "";
    if (isalpha(str[0])){
        std::cout << "Wrong input !" << '\n';
        exit(0);
    }
    while (isdigit(str[0])) {//Пока цифры сохраняем в строчку
        number += str[0];
        Drop(str, 1);// Отрезаем не нужный символ
    }
    return stoi(number);//Возвращаем число
}


Side* CreateNewSide (string& user_input) {// Создаем сторону
    Side* side = new Side;
    Drop(user_input, 1);// Отрезаем не нужный символ
    side->length = ReadNumber(user_input);
    Drop(user_input, 1);// Отрезаем не нужный символ
    side->isWeight = user_input[0] != '(';
    if (side->isWeight) {
        side->data.weight = ReadNumber(user_input);
    }
    else {
        side->data.bin_kor = CreateNewBinKor(user_input);
    }
    Drop(user_input, 1);// Отрезаем не нужный символ
    return side;
}

// (Side Side)
BinKor* CreateNewBinKor (string& user_input) {
    BinKor* bin_kor = new BinKor;
    Drop(user_input, 1);// Отрезаем не нужный символ
    bin_kor->left = CreateNewSide(user_input);
    Drop(user_input, 1);// Отрезаем не нужный символ
    bin_kor->right = CreateNewSide(user_input);
    Drop(user_input, 1);// Отрезаем не нужный символ
    return bin_kor;
}

void FreeBinKor(BinKor* bin_kor) {
    if (bin_kor != nullptr){// Если указывает на  BinKor
        if(bin_kor->right->isWeight == 0){// Если не груз
            FreeBinKor(bin_kor->right->data.bin_kor);// Вызываем рекурсивную функцию
            delete bin_kor->right;// Освобождаем сторону
        }
        else{
            delete bin_kor->right;// Освобождаем сторону
        }
        if(bin_kor->left->isWeight == 0){// Если не груз
            FreeBinKor(bin_kor->left->data.bin_kor);// Вызываем рекурсивную функцию
            delete bin_kor->left;// Освобождаем сторону
        }
        else{
            delete bin_kor->left;// Освобождаем сторону
        }
        delete bin_kor;// Освобождаем BinKor
    }
    else{
        std::cout << "delete" << '\n';
    }
}

int main () {

    std::string user_input;
    std::ifstream in("/home/indiora/C++/Aisd/readmepls.txt"); // окрываем файл для чтения
    if (in.is_open()){
        while (getline(in, user_input)){
            int indentr = 0;// Левый отступ
            int indentl = 0;// Правый отступ
            if(user_input.length() == 0){// Если файл  пуст
                std::cout << "File is empty" << '\n';
                exit(0);
            }
            std::cout << '\n' << "You entered:" << user_input << '\n' << '\n';
            BinKor* bin_kor = new BinKor;// Создаем указатель на BinKor
            bin_kor = CreateNewBinKor(user_input);
            int res = SumLength(*bin_kor, indentr, indentl);
            std::cout << '\n' << "Length of all shoulders: " << res << '\n';
            FreeBinKor(bin_kor);// Особождаем память
        }
    }
    in.close();
    return 0;
}
