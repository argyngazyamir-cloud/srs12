#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void workingTime() {
    int days;
    double rate;
    double hours;

    cout << "\n=====================================\n";
    cout << "       УЧЕТ РАБОЧЕГО ВРЕМЕНИ\n";
    cout << "=====================================\n";

    cout << "Введите количество рабочих дней в неделю: ";
    cin >> days;

    while (cin.fail() || days <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка! Введите корректное количество дней: ";
        cin >> days;
    }

    cout << "Введите ставку (например, 0.5): ";
    cin >> rate;

    while (cin.fail() || rate <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка! Введите корректную ставку: ";
        cin >> rate;
    }

    double normHours = 40 * rate;

    cout << "\nНорма рабочего времени: "
         << normHours << " часов в неделю.\n";

    do {
        cout << "Введите количество часов работы в день: ";
        cin >> hours;

        while (cin.fail() || hours <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Ошибка! Введите корректное количество часов: ";
            cin >> hours;
        }

        double weeklyHours = days * hours;
        double deficit = normHours - weeklyHours;

        if (weeklyHours < normHours) {
            double percent = (deficit / normHours) * 100;
            cout << "\nДефицит рабочего времени: "
                 << deficit << " часов (" << percent
                 << "% от нормы).\n";
            cout << "Для продолжения подтвердите норму в 4 часа в день.\n";
        }
    } while (hours != 4);

    cout << "\nНорма подтверждена: 4 часа в день.\n";
    cout << "Модуль рабочего времени завершен.\n";
}
void disciplinaryModule() {
    int laptopNumber;

    cout << "\n=====================================\n";
    cout << "       ДИСЦИПЛИНАРНЫЕ ВЗЫСКАНИЯ\n";
    cout << "=====================================\n";

    cout << "Введите номер ноутбука: ";
    cin >> laptopNumber;

    while (cin.fail() || laptopNumber <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка! Введите номер ноутбука: ";
        cin >> laptopNumber;
    }

    cout << "\nСообщение об инциденте:\n";
    cout << "Проверьте, был ли ноутбук №" << laptopNumber
         << " вынесен за пределы учебного кабинета.\n";

    cout << "\nВозможные вопросы для проверки:\n";
    cout << "1. Соблюдался ли порядок работы?\n";
    cout << "2. Сохранно ли имущество кабинета?\n";
    cout << "3. Повлияло ли событие на учебный процесс?\n";

    cout << "\nВозможные дальнейшие действия:\n";
    cout << "- зафиксировать сообщение;\n";
    cout << "- провести служебную проверку;\n";
    cout << "- передать информацию ответственному руководителю.\n";
}
void sabotageProtocol() {
    int laptopNumber;

    cout << "\n=====================================\n";
    cout << "     ПРОТОКОЛ РЕАГИРОВАНИЯ\n";
    cout << "=====================================\n";
    cout << "Введите номер ноутбука: ";
    cin >> laptopNumber;

    while (cin.fail() || laptopNumber <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка! Введите номер ноутбука: ";
        cin >> laptopNumber;
    }

    using namespace chrono_literals;

    cout << "\n[1] Фиксация сообщения об инциденте...\n";
    this_thread::sleep_for(1s);

    cout << "Проверяется сообщение о возможном выносе ноутбука №"
         << laptopNumber << " и сопутствующих обстоятельствах.\n";
    this_thread::sleep_for(2s);

    cout << "\n[2] Уведомление ответственного лица...\n";
    this_thread::sleep_for(1s);
    cout << "Передайте информацию ответственному за кабинет ИКТ.\n";
    this_thread::sleep_for(2s);

    cout << "\n[3] Проверка обстоятельств...\n";
    this_thread::sleep_for(1s);
    cout << "Сопоставьте доступные записи и сведения об имуществе.\n";
    this_thread::sleep_for(2s);

    cout << "\n[4] Подготовка служебной записки...\n";
    this_thread::sleep_for(1s);
    cout << "Зафиксируйте дату, место и источник сообщения.\n";
    this_thread::sleep_for(2s);

    cout << "\n[5] Передача информации руководству...\n";
    this_thread::sleep_for(1s);
    cout << "Дальнейшие меры принимаются после проверки фактов.\n";
    cout << "\nПротокол завершен.\n";
}
int main() {
    int choice;
    int answer;

    cout << "=====================================\n";
    cout << "      ИНФОРМАЦИОННЫЙ БОТ ЛАБОРАНТА\n";
    cout << "=====================================\n";

    do {
        cout << "\nМеню:\n";
        cout << "1. Рабочее время\n";
        cout << "2. Обязанности лаборанта\n";
        cout << "3. Материальная ответственность\n";
        cout << "4. Учет рабочего времени\n";
        cout << "5. Дисциплинарные взыскания\n";
        cout << "6. Протокол реагирования\n";
        cout << "7. Завершить работу\n";
        cout << "Выберите пункт: ";

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n--- Рабочее время ---\n";
            cout << "Лаборант на 0,5 ставки обязан отрабатывать ";
            cout << "20 часов в неделю.\n";
            break;

        case 2:
            cout << "\n--- Обязанности лаборанта ---\n";
            cout << "Лаборант обязан ежедневно проверять ";
            cout << "работоспособность программного обеспечения ";
            cout << "на всех ноутбуках кабинета до начала занятий.\n";
            break;

        case 3:
            cout << "\n--- Материальная ответственность ---\n";
            cout << "Лаборант несет ответственность за сохранность ";
            cout << "имущества компьютерного класса.\n";
            break;

        case 4:
        workingTime();
        break;


        case 5:
        disciplinaryModule();
        break;
        
        case 6:
        sabotageProtocol();
        break;
        default:
            cout << "Ошибка! Такого пункта меню нет.\n";
        }

    } while (choice != 7);

    do {
        cout << "\nСколько часов в неделю обязан отрабатывать ";
        cout << "лаборант на 0,5 ставки? ";
        cin >> answer;

        if (answer != 20) {
            cout << "Неверный ответ! Попробуйте еще раз.\n";
        }

    } while (answer != 20);

    cout << "\nПравильно! Лаборант обязан отрабатывать ";
    cout << "20 часов в неделю.\n";
    cout << "Работа завершена.\n";

    return 0;
}