#pragma once
#include <string>
#include <vector>
#include "Protection.h"
#include "Session.h"
#include "Menu.h"

class Session;
class StudentNode;
class Student : public Protection{
friend class Menu;
    std::vector<StudentNode*> students;
    void delete_sessions();
public:
    int int_protection(int from, int to) override;
    std::vector<StudentNode*> get_students();
    void add_student();
    void remove_student();
    int students_count;
    ~Student(){
        delete_sessions();
    }
};

class StudentNode : public Protection{
friend class Student;
private:
    std::string surname;
    std::string middle_name;
    std::string name;
    char sex;  // EDIT: better use enum or bool for this
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
public:
    int session_count;
    std::string data[12] = {
      "surname",      "middle name",    "name",          "sex",
      "day of birth", "month of birth", "year of birth", "year of admission",
      "faculty",      "department",     "group",         "student ID number"};
    int get_id();
    void add_session();
    void remove_session();
    void set_student_data();  // EDIT: better create a separate public object for working with data: student.data.edit()  ; student.data.set();
    void edit_student_data();
    void __student_data_edit(int i);  // EDIT: bad naming. There is not obvious difference between edit_student_data and __student_data_edit
    void get_student_data();
    void get_full_name();
    void edit_session();  // EDIT: better create a separate public object for working with sessions: student.session.edit()
    void add_session_object();  // EDIT: this method takes no arguments. Bad naming, better name is add_session(Session* session);
    std::vector<Session*> get_sessions();
};
