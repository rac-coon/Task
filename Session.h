#pragma once
#include <stack>
#include <string>
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
    float average = 0;
public:
    std::string string_protection() override;
    void set_session_id(int value);  // EDIT: it is not recommeded to put id setters into public fields
    void add_session_object();
    std::stack<SessionNode*> get_session();
    // EDIT: bad naming. remove_session, edit_session
    void remove_session_object();
    void edit_session_object();
    void set_average();  // EDIT: setters should take arguments
    float get_average();
    void show_session();
};

class SessionNode{
private:
    int node_id;
    std::string object_name;
    int object_mark;
public:
    // EDIT: all the definitions should be moved into .cpp file
    SessionNode(){
        node_id = 0;
        object_name = "null";
        object_mark = 0;
    }
    // EDIT: bad naming. set_name, get_name, set_mark, get_mark, etc...
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
