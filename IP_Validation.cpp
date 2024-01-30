#include <iostream>

using namespace std;

static bool dot_count(string text) {                                          // Метод вычисляет что допустимое кол-во                                                          // точек в тексте и что первый символ 
    int j = 0;                                                                // точек три и первый и последний 
    for (int y = 0; y < text.length(); y++) {                                 // символы не точки
        if (text[y] == '.') {
            j++;
        }
    }
    if (j != 3 || text[0] == '.' || text[text.length() - 1] == '.') {
        return false;
    }
    else {
        return true;
    }
}

static bool two_points_in_a_row(string text) {                               //Метод вычисляет две точки подряд
    for (int dt = 1; dt < text.length(); dt++) {
        if (text[dt - 1] == '.' && text[dt] == '.') {
            return false;
        }
    }
    return true;
}

static string get_address_part(string text, int n) {                        // Метод отделяет октет от общего
    int x = 0;                                                              // текста взависимости от выбранного
    string new_text;
    for (int q = 0; q < n; q++) {
        new_text = "";
        for (; text[x] != '.' && text[x] != '\0'; x++) {
            new_text += text[x];
        }
        x++;
    }
    return new_text;
}

static bool string_separator(string text) {                                // Метод проверяет наличие недопустимых
    int n = 0;                                                             // знаков в октете, допустимую величину
    int k = 1;                                                             // и наличие начальных нулей
    for (int s = text.length() - 1; s >= 0; s--, k *= 10) {
            n += (text[s] - '0') * k;

            if (text[s] < '0' || text[s]>'9') {
                return false;
                break;
            }
    }
    
    if (n > 255 || text.length() == 3 && text[0] == '0' || text.length() == 2 && text[0] == '0') {
        return false;
    }
    else {
        return true;
    }
}

static void show_result(string text) {                                    // Метод для вывода текста
    cout << text << endl;
}

int main(){
    system("color 80");                                                   // Изменяем цвет текста и терминала
    string text;                                                          // Объявляем переменную для записи IP
    string text1 = " Valid";                                              // Объявляем и инициализируем переменные 
    string text2 = " Invalid";                                            // для вывода результата

    cout << " Enter IP:\n";                                               // Запрашиваем IP адрес
    cout << " ";
    cin >> text;                                                          // записываем его в переменную

    bool dot = dot_count(text);                                           // Для удобства присваиваим возвращаемые 
    bool dot_two = two_points_in_a_row(text);                             // значения переменным
    bool a = string_separator(get_address_part(text, 1));
    bool b = string_separator(get_address_part(text, 2));
    bool c = string_separator(get_address_part(text, 3));
    bool d = string_separator(get_address_part(text, 4));

    if (dot && dot_two && a && b && c && d) show_result(text1);           // Условием определяем какой текст вывести  
    else show_result(text2);                                              // и методом show_result() выводим
    

    system("pause > nul");
    return 0;
}