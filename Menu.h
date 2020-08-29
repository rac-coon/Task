#pragma once
#include <iostream>
#include "Protection.h"
#include "Student.h"

class Student;
class Menu : public Protection{
    Student* menu_student;
public:
    Menu(){
        menu_main();
    }
    void show_menu();
    void menu_choice_main();
    int choose_student();
    void menu_main(){
        show_menu();
        menu_choice_main();
    }
};
