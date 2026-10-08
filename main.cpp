#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>
#include <sstream>
#include <string>

using namespace std;

bool readInt(const string& prompt, int& value) {
    while (true) {
        cout << prompt;
        string line;
        if (!getline(cin, line)) return false;

        istringstream input(line);
        char extra;
        if ((input >> value) && !(input >> extra)) return true;

        cout << "Ошибка! Введите целое число.\n";
    }
}

bool readDouble(const string& prompt, double& value) {
    while (true) {
        cout << prompt;
        string line;
        if (!getline(cin, line)) return false;

        istringstream input(line);
        char extra;
        if ((input >> value) && !(input >> extra) && isfinite(value)) return true;

        cout << "Ошибка! Введите корректное число.\n";
    }
}

bool workingTime() {
    int days;
    double rate;

    cout << "\n=====================================\n";
    cout << "       УЧЕТ РАБОЧЕГО ВРЕМЕНИ\n";
    cout << "=====================================\n";

    while (true) {
        if (!readInt("Введите количество рабочих дней в неделю (1-7): ", days)) return false;
        if (days >= 1 && days <= 7) break;
        cout << "Ошибка! Число рабочих дней должно быть от 1 до 7.\n";
    }

    while (true) {
        if (!readDouble("Введите ставку (например, 0.5): ", rate)) return false;
        if (rate > 0.0 && rate <= 1.0) break;
        cout << "Ошибка! Ставка должна быть больше 0 и не больше 1.\n";
    }

    const double normHours = 40.0 * rate;
    cout << "\nНорма рабочего времени: " << normHours << " часов в неделю.\n";

    while (true) {
        double hours;
        if (!readDouble("Введите количество часов работы в день (до 24): ", hours)) return false;
        if (hours <= 0.0 || hours > 24.0) {
            cout << "Ошибка! Часы должны быть больше 0 и не больше 24.\n";
            continue;
        }

        const double weeklyHours = days * hours;
        const double deficit = normHours - weeklyHours;
        if (weeklyHours + 1e-9 >= normHours) {
            cout << "\nНорма рабочего времени подтверждена: "
                 << weeklyHours << " часов в неделю.\n";
            break;
        }

        const double percent = (deficit / normHours) * 100.0;
        cout << "\nНедостаточно часов: " << weeklyHours
             << " из " << normHours << " часов в неделю.\n";
        cout << "Дефицит рабочего времени: " << deficit << " часов ("
             << percent << "% от нормы).\n";
        cout << "Налицо факт предоставления заведомо ложных сведений работодателю.\n";
        cout << "Введите график, который соответствует недельной норме.\n";
    }

    cout << "Модуль рабочего времени завершен.\n";
    return true;
}

bool disciplinaryModule() {
    int laptopNumber;

    cout << "\n=====================================\n";
    cout << "       ДИСЦИПЛИНАРНЫЕ ВЗЫСКАНИЯ\n";
    cout << "=====================================\n";

    while (true) {
        if (!readInt("Введите номер ноутбука: ", laptopNumber)) return false;
        if (laptopNumber > 0) break;
        cout << "Ошибка! Номер ноутбука должен быть положительным.\n";
    }

    cout << "\nИнцидент для проверки:\n";
    cout << "Сообщение о возможном выносе учебного ноутбука №"
         << laptopNumber << " за пределы кабинета.\n";
    cout << "\nВыписка из Устава ВУЗа:\n";
    cout << "Пункт 3.3.6 Устава АО «Академия гражданской авиации»: участие в организации и проведении фундаментальных и прикладных научных исследований и иных научно-технических и опытно-конструкторских работ по проблемам гражданской авиации, в том числе по проблемам образования, совершенствования учебно-воспитательного процесса в Обществе.\n";
    cout << "\nПосле установления обстоятельств проверяются:\n";
    cout << "1. Соблюдение трудовой дисциплины.\n";
    cout << "2. Соблюдение установленного порядка работы.\n";
    cout << "3. Сохранность имущества компьютерного класса.\n";
    cout << "4. Влияние события на учебный процесс.\n";
    cout << "\nВозможные дисциплинарные меры рассматриваются "
         << "только после служебной проверки.\n";
    return true;
}

bool sabotageProtocol() {
    int laptopNumber;

    cout << "\n=====================================\n";
    cout << "     ПРОТОКОЛ РЕАГИРОВАНИЯ\n";
    cout << "=====================================\n";
    while (true) {
        if (!readInt("Введите номер ноутбука: ", laptopNumber)) return false;
        if (laptopNumber > 0) break;
        cout << "Ошибка! Номер ноутбука должен быть положительным.\n";
    }

    using namespace chrono_literals;

    cout << "\n[1] Фиксация сообщения об инциденте...\n";
    this_thread::sleep_for(1s);
    cout << "Проверяется сообщение о возможном выносе ноутбука №"
         << laptopNumber << ", возможной утере блока питания и отказе от подготовки/тестирования ПО кабинета ИКТ.\n";
    cout << "Все перечисленное является сообщением и требует отдельного подтверждения.\n";
    this_thread::sleep_for(2s);

    cout << "\n[2] Уведомление руководства...\n";
    this_thread::sleep_for(1s);
    cout << "Уведомить ответственное лицо, закрепленное за кабинетом ИКТ.\n";
    this_thread::sleep_for(2s);

    cout << "\n[3] Проверка доказательной базы...\n";
    this_thread::sleep_for(1s);
    cout << "Запросить аудит записей камер видеонаблюдения и "
         << "сопоставить его с журналом посещения кабинета.\n";
    this_thread::sleep_for(2s);

    cout << "\n[4] Подача служебной записки...\n";
    this_thread::sleep_for(1s);
    cout << "Направить записку заведующему кафедрой, руководителю "
         << "конструкторского отдела и декану факультета.\n";
    this_thread::sleep_for(2s);

    cout << "\n[5] Административные последствия...\n";
    this_thread::sleep_for(1s);
    cout << "Рассмотреть создание дисциплинарной комиссии и передачу "
         << "материалов в органы материального учета ВУЗа.\n";
    cout << "\nПротокол завершен.\n";
    return true;
}

int main() {
    int choice;

    cout << "=====================================\n";
    cout << "      ИНФОРМАЦИОННЫЙ БОТ ЛАБОРАНТА\n";
    cout << "=====================================\n";

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Рабочее время\n";
        cout << "2. Обязанности лаборанта\n";
        cout << "3. Материальная ответственность\n";
        cout << "4. Учет рабочего времени\n";
        cout << "5. Дисциплинарные взыскания\n";
        cout << "6. Протокол реагирования\n";
        cout << "7. Завершить работу\n";

        if (!readInt("Выберите пункт: ", choice)) return 0;

        switch (choice) {
        case 1:
            cout << "\n--- Рабочее время ---\n";
            cout << "Лаборант на 0,5 ставки обязан отрабатывать "
                 << "20 часов в неделю.\n";
            break;
        case 2:
            cout << "\n--- Обязанности лаборанта ---\n";
            cout << "Лаборант обязан ежедневно проверять "
                 << "работоспособность программного обеспечения "
                 << "на всех ноутбуках кабинета до начала занятий.\n";
            break;
        case 3:
            cout << "\n--- Материальная ответственность ---\n";
            cout << "Лаборант несет ответственность за сохранность "
                 << "имущества компьютерного класса.\n";
            break;
        case 4:
            if (!workingTime()) return 0;
            break;
        case 5:
            if (!disciplinaryModule()) return 0;
            break;
        case 6:
            if (!sabotageProtocol()) return 0;
            break;
        case 7: {
            cout << "\nПереходим к контрольному вопросу.\n";
            int answer;
            while (true) {
                if (!readInt("Сколько часов в неделю обязан отрабатывать "
                             "лаборант на 0,5 ставки? ", answer)) return 0;
                if (answer == 20) break;
                cout << "Неверный ответ! Попробуйте еще раз.\n";
            }
            cout << "\nПравильно! Лаборант обязан отрабатывать "
                 << "20 часов в неделю.\n";
            cout << "Работа завершена.\n";
            return 0;
        }
        default:
            cout << "Ошибка! Выберите пункт от 1 до 7.\n";
        }
    }
}
