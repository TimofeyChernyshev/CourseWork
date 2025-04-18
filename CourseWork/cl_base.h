#ifndef __CL_BASE__H
#define __CL_BASE__H
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class cl_base {
	string name; // имя объекта
	cl_base* head_obj = nullptr; // указатель на родительский объект
	vector<cl_base*> child; // вектор дочерних объектов
	bool status; // состояние объекта
public:
	cl_base(cl_base* head_obj, string name = "Base_object"); // конструктор
	bool redact_name(string name); // изменяет имя объекта
	string ret_name(); // возвращает имя объекта
	cl_base* ret_head_obj(); // вовзращает указатель на головной объект
	cl_base* ret_child(string chld_name); // возвращает указатель на дочерний объект
	~cl_base(); // деструктор
	cl_base* find_obj_branch(string ObjName); // метод поиска объекта от имени на ветке
	cl_base* find_obj_tree(string ObjName); // метод поиска объекта от имени на всем дереве иерархии
	void print_objects(int space = 4); // метод вывода иерархии объектов от текущего объекта
									   // имя каждого дочернего объекта выводится после 4 пробелов
	void print_objects_status(int space = 4); // метод вывода иерархии объектов и состояния готовности от текущего объекта
	void set_status(int status_num); // метод установки готовности объекта, параметр - номер состояния
};

#endif
