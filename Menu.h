#pragma once
#include <iostream>
#include "Protection.h"
#include "Student.h"

class Student;
class Menu : public Protection{
    Student* menu_student;
public:
    void show_menu();
    void menu_choice_main();
    int choose_student();
    void menu_main();
};
