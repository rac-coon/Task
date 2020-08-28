#pragma once
#include <string>
#include <vector>
#include "Protection.h"
#include "Session.h"
#include "Menu.h"

class Session;
class StudentNode;
class Student{
friend class Menu;
    std::vector<StudentNode*> students;
public:
    std::vector<StudentNode*> get_students();
    void add_student();
    void remove_student();
    int students_count;
    ~Student(){
        for (int i = 0; i < students_count; i++){
                students[i]->sessions.clear();
        }
    }
};

class StudentNode : public Protection{
friend class Student;
private:
    std::string surname;
    std::string middle_name;
    std::string name;
    char sex;
    // Birthday
    int b_year;
    int b_month;
    int b_day;
    // Institute
    int enter_year;
    std::string faculty; // IKBSP, FTI...
    std::string department; // cafedra
    std::string group;
    std::string stud_id;
    // Education
    std::vector<Session*> sessions;
    int id;
    int get_id();
public:
    int session_count;
    std::string data[12] = {
      "surname",      "middle name",    "name",          "sex",
      "day of birth", "month of birth", "year of birth", "year of admission",
      "faculty",      "department",     "group",         "student ID number"};
    void add_session();
    void remove_session();
    void set_student_data();
    void edit_student_data();
    void __student_data_edit(int i);
    void get_student_data();
    void get_full_name();
    void edit_session();
    void add_session_object();
    std::vector<Session*> get_sessions();
};
