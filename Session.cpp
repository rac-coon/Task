#include "Session.h"

void Session::add_session_object(){
    SessionNode* node;
    std::cout << "enter the object name" << std::endl;
    node->set_object_name(string_protection());
    std::cout << "enter the object mark" << std::endl;
    node->set_object_mark(int_protection(2,5));
    node->set_node_id(session.size() + 1);
    this->session.push(node);
}

std::stack<SessionNode*> Session::get_session(){
    return this->session;
}

std::string Session::string_protection(){
    std::string name;
    while (name.size() < 5){
        std::cin.clear();
        std::cin >> name;
        std::cout << "Incorrect value, try again" << std::endl;
    }
    return name;
}

void Session::set_average(){
    std::stack<SessionNode*> temp_stack = this->session;
    SessionNode* temp_element;
    int count = 0;
    float value = 0;
    while(!temp_stack.empty()){
        temp_element = temp_stack.top();
        value = value + temp_element->get_object_mark();
        count++;
        temp_stack.pop();
    }
    this->average = value / count;
}

float Session::get_average(){
    return this->average;
}

void Session::remove_session_object(){
    int id = int_protection(1,session.size());
    std::vector<SessionNode*> temp_vector;
    SessionNode* temp_element;
    while(!session.empty()){
        temp_element = this->session.top();
        if (temp_element->get_node_id() != id){
            temp_vector.push_back(temp_element);
        }
        session.top();
    }
    for (int i = temp_vector.size() - 1; i >= 0; --i){
        session.push(temp_vector[i]);
    } 
}

void Session::show_session(){
    SessionNode* temp;
    for (int i = 0; i < session.size(); i++){
        temp = session.top();
        std::cout << "[" << i+1 << "] " << temp->get_object_name() << " " << temp->get_object_mark() << std::endl;
    }
}

void Session::edit_session_object(){
    if (session.size() == 0){std::cout << "Nothing to change!" << std::endl;}
    else{
        int id = int_protection(1, session.size());
        std::stack<SessionNode*> temp_stack;
        temp_stack = this->session;
        SessionNode* temp_element;
        do{
            temp_element = temp_stack.top();
            if (id == temp_element->get_node_id()){
                std::cout << "What you want to change?" << std::endl;
                std::cout << "1. Subject's name" << std::endl;
                std::cout << "2. Subject's mark" << std::endl;
                std::cout << "3. All of this" << std::endl;
                int value = int_protection(1,3);
                switch (value){
                    case 1:
                    {
                        std::cout << "Subject's name now: " << temp_element->get_object_name() << std::endl;
                        std::cout << "Enter the new name" << std::endl;
                        std::string new_name = string_protection();
                        temp_element->set_object_name(new_name);
                        break;
                    }
                    case 2:
                    {
                        std::cout << "Subject's mark now: " << temp_element->get_object_name() << std::endl;
                        std::cout << "Enter the new mark" << std::endl;
                        int new_mark = int_protection(2,5);
                        temp_element->set_object_mark(new_mark);
                        break;
                    }
                    case 3:
                    {
                        std::cout << "Subject's name now: " << temp_element->get_object_name() << std::endl;
                        std::cout << "Enter the new name" << std::endl;
                        std::string new_name = string_protection();
                        temp_element->set_object_name(new_name);
                        std::cout << "Subject's mark now: " << temp_element->get_object_name() << std::endl;
                        std::cout << "Enter the new mark" << std::endl;
                        int new_mark = int_protection(2,5);
                        temp_element->set_object_mark(new_mark);
                        break;
                    }
                }
            }
            temp_stack.pop();        
        }
        while(!temp_stack.empty());
    }
}

void Session::set_session_id(int value){
    this->session_id = value;
}
