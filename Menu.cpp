#include "Menu.h"

void Menu::show_menu(){
    system("cls");
    std::cout << "What do you want to do?" << std::endl;
    std::cout << "1. Add student" << std::endl;
    std::cout << "2. Edit student data" << std::endl;
    std::cout << "3. Add/Edit student's session" << std::endl;
    std::cout << "4. Show students data" << std::endl;
    std::cout << "5. Remove student" << std::endl;
    std::cout << "6. Data sorting" << std::endl;
    std::cout << "7. Save data to file" << std::endl;
    std::cout << "8. Load data from file" << std::endl;
};

void Menu::menu_choice_main(){
    int value = int_protection(1,7);
    switch(value){
        case 1:
            this->menu_student->add_student();
            break;
        case 2:
            if (this->menu_student->students_count != 0){
                int chosen_id = choose_student();
                std::vector<StudentNode*> temp_students = menu_student->get_students();
                StudentNode* temp_student = temp_students[chosen_id];
                temp_student->edit_student_data();
            }
            else {std::cout << "Nothing to change!";}
            break;
        case 3:
            if (this->menu_student->students_count != 0){
                int chosen_id = choose_student();
                int chosen_action = 1;
                std::vector<StudentNode*> temp_students = this->menu_student->get_students();
                StudentNode* temp_student = temp_students[chosen_id];
                if (temp_student->session_count != 0){
                    std::cout << "[1] Add \n[2] Edit \n[3] Delete a student session?" << std::endl;
                    chosen_action = int_protection(1,3);
                }
                else {std::cout << "The student does't have sessions. Adding a session:";}
                switch (chosen_action){
                    case 1:{
                        temp_student->add_session();
                        std::cout << "How many subjects will be in the session?";
                        int count = int_protection(1,10);
                        std::vector<Session*> temp_session = temp_student->get_sessions();
                        for (int i = 0; i < count; i++){
                            temp_session[1]->add_session_object();
                        }
                        break;
                    }
                    case 2:{
                        std::cout << "Which session do you want to change? (1 - )" << temp_student->session_count << std::endl;
                        int chosen_session = int_protection(1,chosen_session);
                        std::cout << "[1] Remove subject \n[2]Edit subject?";
                        int temp_value = int_protection(1,3);
                        std::vector<Session*> temp_session = temp_student->get_sessions();
                        Session* session_objects = temp_session[chosen_session];
                        session_objects->show_session();
                        switch (temp_value){
                            case 1:
                                session_objects->remove_session_object();
                                break;
                            case 2:
                                session_objects->edit_session_object();
                                break;
                            }
                        break;
                    }
                    case 3:
                        temp_student->remove_session();
                        break;
                }
            }
            else {std::cout << "Nothing to change!";}
            break;
        case 4:
            if (this->menu_student->students_count != 0){
                std::vector<StudentNode*> temp_students = this->menu_student->get_students();
                StudentNode* temp_student;
                for (int i = 0; i < this->menu_student->students_count; i++){
                    temp_student = temp_students[i];
                    for (int j = 0; j < temp_student->session_count; j++ ){
                        std::vector<Session*> temp_session = temp_student->get_sessions();
                        temp_session[j]->show_session();
                    }
                }
            }
            else {std::cout << "Nothing to show!";}
            break;
        case 5:
            if (this->menu_student->students_count != 0){
                this->menu_student->remove_student();

            }
            else {std::cout << "Nothing to remove!";}
            break;
        case 6:
            std::cout << "6" << std::endl;
            break;
        case 7:
            std::cout << "7" << std::endl;
            break;
        case 8:
            std::cout << "8" << std::endl;
            break;
    }
    menu_main();
}

int Menu::choose_student() {
  std::cout << "which student's data do you want to change?" << std::endl;
  std::vector<StudentNode*> temp_students = this->menu_student->get_students();
  StudentNode* temp_student;
  for (int i = 0; i < temp_students.size(); i++) {
    temp_student = temp_students[i];
    std::cout << "[" << i + 1 << "]";
    temp_student->get_full_name();
  }
  int chosen_id = int_protection(1, this->menu_student->students_count);
  chosen_id--;
  return chosen_id;
}