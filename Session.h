#pragma once
#include <stack>
#include <iostream>
#include <vector>
#include "Protection.h"
#include "Menu.h"

class SessionNode;
class Session : public Protection{
friend class StudentNode;
friend class Menu;
private:
    int session_id;
    std::stack<SessionNode*> session;
    int int_protection() override;
    std::string string_protection() override;
    int int_protection(int from, int to) override;
    float average = 0;
public:
    std::stack<SessionNode*> get_session();
    void set_session_id(int value);
    void add_session_object();
    std::stack<SessionNode*> get_session();
    void remove_session_object();
    void edit_session_object();
    void set_average();
    float get_average();
    void show_session();
};

class SessionNode{
    int node_id;
    std::string object_name;
    int object_mark;
public:
    SessionNode(){
        node_id = 0;
        object_name = "null";
        object_mark = 0;
    }
    void set_object_name(std::string name){
        this->object_name = name;
    }
    std::string get_object_name(){
        return this->object_name;
    }
    void set_object_mark(int mark){
        this->object_mark = mark;
    }
    int get_object_mark(){
        return this->object_mark;
    }
    void set_node_id(int id){
        this->node_id = id;
    }
    int get_node_id(){
        return this->node_id;
    }
};
