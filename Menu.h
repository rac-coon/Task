#pragma once
#include <iostream>
#include "Protection.h"
#include "Student.h"
#include "Session.h"

class Menu : public Protection{
    Student* menu_student;
    Session* menu_session;
public:
    void show_menu();
    void menu_choice_main();
    int choose_student();
    void menu(){
        show_menu();
        menu_choice_main();
    }
};
