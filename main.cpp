#include <iostream>
#include <string>
#include <vector>
using namespace std;

int menu{};

// Функция для вывода меню
void Menu () {
    cout << "\n1 New Task "        // Создание новой задачи
            "\n2 Search by Importance "  // Поиск по приоритету
            "\n3 Search by Status "      // Поиск по статусу
            "\n4 View All Tasks "        // Просмотр всех задач
            "\n5 Change Status "         // Изменение статуса задачи
            "\n6 Change Priority "       // Изменение приоритета задачи
            "\n7 Search by Project Number "  // Поиск по номеру проекта
            "\n0 Exit" << endl;           // Выход из программы
    cout << "Enter menu: ";  // Запрос выбора действия от пользователя
    cin >> menu;
}

// Перечисление для статуса задачи
enum Status {
    New = 1,        // Новая задача
    InProgress,     // Задача в процессе выполнения
    Completed       // Задача выполнена
};

// Перечисление для приоритета задачи
enum Priority {
    Low  = 1,       // Низкий приоритет
    Medium,         // Средний приоритет
    High            // Высокий приоритет
};

// Структура Task для описания задачи
struct Task {

    int projectNumber;      // Номер проекта
    string title;           // Название задачи
    string description;     // Описание задачи
    Status status;          // Статус задачи (новая, в процессе выполнения, выполнена)
    Priority priority;      // Приоритет задачи (низкий, средний, высокий)

    // Ввод данных для новой задачи
    void input () {
        cout << "Please enter the project number for the task: ";  // Ввод номера проекта
        cin >> projectNumber;
        cout << "Enter title: ";  // Ввод названия задачи
        cin >> title;
        cout << "Enter description: ";  // Ввод описания задачи
        cin >> description;

        // Ввод статуса задачи
        cout << "Status:\n1 New\n2 InProgress\n3 Completed\n";
        int statusMenuStatus;
        cin >> statusMenuStatus;
        status = static_cast<Status>(statusMenuStatus);

        // Ввод приоритета задачи
        cout << "Priority:\n1 Low\n2 Medium\n3 High\n";
        int statusMenuPriority;
        cin >> statusMenuPriority;
        priority = static_cast<Priority>(statusMenuPriority);

        cout << "Task successfully created.\n";  // Сообщение об успешном создании задачи
    }

    // Функция для отображения всех задач
    static void display (vector<Task>& tasks) {
        for (const auto& task : tasks) {
            cout << "\nProject Number: " << task.projectNumber << endl;
            cout << "Title: " << task.title << endl;
            cout << "Description: " << task.description << endl;
            cout << "Status: " << (task.status == New ? "New" : task.status == InProgress ? "In Progress" : "Completed") << endl;
            cout << "Priority: " << (task.priority == Low ? "Low" : task.priority == Medium ? "Medium" : "High") << endl;
        }
    }

    // Функция для поиска задачи по номеру проекта
    static Task* findTaskByProjectNumber (vector<Task>& tasks, const int& projectNumber) {
        for (auto& task : tasks) {
            if (task.projectNumber == projectNumber) {
                return &task;  // Возвращаем указатель на найденную задачу
            }
        }
        return nullptr;  // Если задача не найдена, возвращаем nullptr
    }

    // Функция для изменения статуса задачи
    static void changeStatus (vector<Task>& tasks) {
        int findNumber;
        cout << "Please enter the project number: ";  // Ввод номера проекта
        cin >> findNumber;

        Task* task = findTaskByProjectNumber(tasks, findNumber);  // Поиск задачи по номеру проекта
        if (task) {
            int changeStatus;
            cout << "New status:\n1 New\n2 InProgress\n3 Completed\n";  // Ввод нового статуса
            cin >> changeStatus;
            task->status = static_cast<Status>(changeStatus);  // Обновляем статус задачи
            cout << "Status successfully updated.\n";
        } else {
            cout << "Project number not found.\n";  // Если проект не найден
        }
    }

    // Функция для изменения приоритета задачи
    static void changePriority (vector<Task>& tasks) {
        int findNumber;
        cout << "Please enter the project number: ";  // Ввод номера проекта
        cin >> findNumber;

        Task* task = findTaskByProjectNumber(tasks, findNumber);  // Поиск задачи по номеру проекта
        if (task) {
            int changePriority;
            cout << "New priority:\n1 Low\n2 Medium\n3 High\n";  // Ввод нового приоритета
            cin >> changePriority;
            task->priority = static_cast<Priority>(changePriority);  // Обновляем приоритет задачи
            cout << "Priority successfully updated.\n";
        } else {
            cout << "Project number not found.\n";  // Если проект не найден
        }
    }

    // Функция для поиска задачи по номеру проекта
    void findProjectByNumber (vector<Task>& tasks) {
        int findNumber;
        cout << "Please enter the project number: ";  // Ввод номера проекта
        cin >> findNumber;

        Task* task = findTaskByProjectNumber(tasks, findNumber);  // Поиск задачи по номеру проекта
        if (task) {
            cout << "\nProject Number: " << task->projectNumber << endl;
            cout << "Title: " << task->title << endl;
            cout << "Description: " << task->description << endl;
            cout << "Status: " << (task->status == New ? "New" : task->status == InProgress ? "In Progress" : "Completed") << endl;
            cout << "Priority: " << (task->priority == Low ? "Low" : task->priority == Medium ? "Medium" : "High") << endl;
        } else {
            cout << "Project number not found.\n";  // Если проект не найден
        }
    }

    // Функция для поиска задач по статусу
    static void findByStatus (vector<Task>& tasks) {
        int findStatus;
        cout << "Please enter the status of the task:\n1 New\n2 InProgress\n3 Completed\n";  // Ввод статуса для поиска
        cin >> findStatus;
        Status status = static_cast<Status>(findStatus);
        bool found = false;

        for (const auto& task : tasks) {
            if (task.status == status) {
                cout << "\nProject Number: " << task.projectNumber << endl;
                cout << "Title: " << task.title << endl;
                cout << "Description: " << task.description << endl;
                cout << "Status: " << (task.status == New ? "New" : task.status == InProgress ? "In Progress" : "Completed") << endl;
                cout << "Priority: " << (task.priority == Low ? "Low" : task.priority == Medium ? "Medium" : "High") << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No tasks found with the specified status.\n";  // Если задачи с указанным статусом не найдены
        }
    }

    // Функция для поиска задач по приоритету
    static void findByPriority (vector<Task>& tasks) {
        int findPriority;
        cout << "Please enter the priority of the task:\n1 Low\n2 Medium\n3 High\n";  // Ввод приоритета для поиска
        cin >> findPriority;
        Priority priority = static_cast<Priority>(findPriority);
        bool found = false;

        for (const auto& task : tasks) {
            if (task.priority == priority) {
                cout << "\nProject Number: " << task.projectNumber << endl;
                cout << "Title: " << task.title << endl;
                cout << "Description: " << task.description << endl;
                cout << "Status: " << (task.status == New ? "New" : task.status == InProgress ? "In Progress" : "Completed") << endl;
                cout << "Priority: " << (task.priority == Low ? "Low" : task.priority == Medium ? "Medium" : "High") << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No tasks found with the specified priority.\n";  // Если задачи с указанным приоритетом не найдены
        }
    }
};

// Главная функция
int main() {
    vector<Task> tasks;  // Вектор для хранения задач
    Task task;           // Переменная для работы с задачей
    while (true) {
        Menu();  // Вывод меню
        switch (menu) {
            case 1: {
                task.input();  // Ввод данных новой задачи
                tasks.push_back(task);  // Добавление задачи в список
                break;
            }
            case 2: {
                task.findByPriority(tasks);  // Поиск задач по приоритету
                break;
            }
            case 3: {
                task.findByStatus(tasks);  // Поиск задач по статусу
                break;
            }
            case 4: {
                task.display(tasks);  // Вывод всех задач
                break;
            }
            case 5: {
                task.changeStatus(tasks);  // Изменение статуса задачи
                break;
            }
            case 6: {
                task.changePriority(tasks);  // Изменение приоритета задачи
                break;
            }
            case 7: {
                task.findProjectByNumber(tasks);  // Поиск задачи по номеру проекта
                break;
            }
            case 0: {
                return 0;  // Выход из программы
            }
            default:
                cout << "Invalid option, try again.\n";  // Обработка неверного ввода
                break;
        }
    }
    return 0;
}