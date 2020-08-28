#pragma once
#include "Student.h"

void Student::add_student(){
    StudentNode* ptr = new StudentNode();
    students.push_back(ptr);
    students_count++;
    ptr->id = students_count;
    ptr->set_student_data();
}

std::vector<StudentNode*> Student::get_students(){
  return this->students;
}

void StudentNode::add_session(){
    Session *ptr = new Session();
    sessions.push_back(ptr);
    session_count++;
    ptr->session_id = session_count;
}

void StudentNode::remove_session(){
    if (session_count != 0){
        std::cout << "Enter the requierd session" << std::endl;
        int id = int_protection(1,session_count);
        sessions.erase(sessions.begin()+id);
    }
    else {std::cout << "Nothing to remove!" << std::endl;}
}

std::vector<Session*> StudentNode::get_sessions(){
  return this->sessions;
}

void StudentNode::set_student_data() {
  for (int i = 0; i < 12; i++) {
    std::cout << "Enter your " << this->data[i] << std::endl;
    this->__student_data_edit(i);
  }
}

void StudentNode::edit_student_data(){
    this->get_student_data();
    std::cout << "Enter [id] of new value:" << std::endl;
    int value = int_protection(1,13) - 1;
    this->__student_data_edit(value);
}

void StudentNode::get_full_name(){
  std::cout << surname << middle_name << name << std::endl;
}

void StudentNode::get_student_data(){
    std::cout << "[1] " << this->surname << " [2] " << this->middle_name << " [3] " << this->name << std::endl;         
    std::cout << "[4] " << sex << std::endl;
    std::cout << "[5].[6].[7] " << this->b_day << "." << this->b_month << "." << this->b_year << std::endl;
    std::cout << "[8] Year of admission: " << enter_year << std::endl;
    std::cout << "[10] " << faculty << std::endl << "[11] " << department << std::endl << "[12] " << group << std::endl;
    std::cout << "[13] " << stud_id << std::endl;
}

int StudentNode::get_id(){
  return this->id;;
}

void StudentNode::__student_data_edit(int i){
    switch (i) {
      case 0:
        std::cin >> this->surname;
        break;
      case 1:
        std::cin >> this->middle_name;
        break;
      case 2:
        std::cin >> this->name;
        break;
      case 3:
        std::cin >> this->sex;
        break;
      case 4:
        int temp = int_protection(1,30); 
        this->b_day = temp;
        break;
      case 5:
        int temp = int_protection(1,12);
        this->b_month = temp;
        break;
      case 6:
        int temp = int_protection(1940,2004);
        this->b_year = temp;
        break;
      case 7:
        int temp = int_protection(this->b_year,this->b_year + 16);
        std::cin >> this->enter_year;
        break;
      case 8:
        std::cin >> this->faculty;
        break;
      case 9:
        std::cin >> this->department;
        break;
      case 10:
        std::cin >> this->group;
        break;
      case 11:
        std::cin >> this->stud_id;
        break;
    }
}