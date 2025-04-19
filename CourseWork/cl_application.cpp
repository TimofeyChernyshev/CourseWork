#include "cl_application.h"

cl_application::cl_application(cl_base* head_obj) : cl_base(head_obj) {}

void cl_application::build_tree_objects() {
	string base_name, child_name;
	cl_base* base = this;
	cl_base* child = nullptr;
	int classNum, status;
	cin >> base_name;
	base->redact_name(base_name);
	// цикл для добавления объектов в дерево
	while (true) {
		cin >> base_name; // ввод имени родительского класса
		// если встретилось ключевое слово "endtree", то выход из цикла
		if (base_name == "endtree") { 
			break;
		}
		// Поиск родительского объекта на дереве
		cl_base* base_obj = find_obj_tree(base_name);
		cin >> child_name >> classNum; // Ввод имени дочернего класса и номера его класса
		// если найден родительский объект, у которого нет такого дочернего то добавляем его в дерево
		if (base_obj && !base_obj->ret_child(child_name)) {
			switch (classNum) {
				case 2: {
					new cl_2(base_obj, child_name);
					break;
				}
				case 3: {
					new cl_3(base_obj, child_name);
					break;
				}
				case 4: {
					new cl_4(base_obj, child_name);
					break;
				}
				case 5: {
					new cl_5(base_obj, child_name);
					break;
				}
				case 6: {
					new cl_6(base_obj, child_name);
					break;
				}
			}
		}
	}
	// цикл для установки состояния готовности для объектов дерева
	while (cin >> base_name) {
		cin >> status;
		cl_base* obj = find_obj_tree(base_name);
		if (obj != nullptr) { // если найден объект с таким именем то ставим ему состояние
			obj->set_status(status);
		}
	}
}
// вывод дерева иерархии объектов и состояния готовности
int cl_application::exec_app() { 
	cout << "Object tree" << endl;
	print_objects();
	cout << endl << "The tree of objects and their readiness" << endl;
	print_objects_status();
	return 0;
}
