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
public:
	cl_base(cl_base* head_obj, string name = "Base_object"); // конструктор
	bool redact_name(string name); // изменяет имя объекта
	string ret_name(); // возвращает имя объекта
	cl_base* ret_head_obj(); // вовзращает указатель на головной объект
	void tree(); // выводит дерево иерархии
	cl_base* ret_child(string chld_name); // возвращает указатель на дочерний объект
	~cl_base();
};

#endif
