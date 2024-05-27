#include <iostream>
#include <string>
#include <list>

using namespace std;

struct flat {
    int rooms;
    int floor;
    double area;
    string address;
};
int main() {
    list<flat> catalog;
    list<flat> queue;
    
    // Начальное формирование картотеки
    catalog.push_back({2, 3, 60.5, "Ул. Ленина, 10"});
    catalog.push_back({3, 5, 80.0, "Проспект Победы, 25"});
    catalog.push_back({1, 1, 40.0, "Площадь Свободы, 5"});
    cout << "Список доступных квартир:" << endl;
    for (const auto& apt : catalog) {
        cout << "Количество комнат: " << apt.rooms << ", Площадь: " << apt.area << ", Адрес: " << apt.address << endl;
    }
    
    // Ввод заявки на обмен
    cout << "Введите заявку на обмен квартиры:" << endl;
    flat request;
    cout << "Количество комнат: ";
    cin >> request.rooms;
    cout << "Этаж: ";
    cin >> request.floor;
    cout << "Площадь: ";
    cin >> request.area;
    cout << "Адрес: ";
    cin.ignore();
    getline(cin, request.address);
    
    // Поиск в картотеке подходящего варианта
    bool found = false;
    for (auto it = catalog.begin(); it != catalog.end(); ++it) {
        if (it->rooms == request.rooms && it->floor == request.floor) {
            cout << "Найден подходящий вариант:" << endl;
            cout << "Количество комнат: " << it->rooms << endl;
            cout << "Этаж: " << it->floor << endl;
            cout << "Площадь: " << it->area << endl;
            cout << "Адрес: " << it->address << endl;
            catalog.erase(it);
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "Подходящего варианта не найдено. Заявка включена в очередь." << endl;
        queue.push_back(request);
    }
    
    
   
}