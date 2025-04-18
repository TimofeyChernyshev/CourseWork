#include "cl_base.h"

cl_base::cl_base(cl_base* head_obj, string name) {
	this->head_obj = head_obj;
	this->name = name;
	if (head_obj != nullptr) {
		head_obj->child.push_back(this);
	}
}
bool cl_base::redact_name(string name) {
	if ((ret_head_obj() != nullptr) && (ret_child(name) != nullptr)) {
		return false;
	}
	this->name = name;
	return true;
}
string cl_base::ret_name() {
	return name;
}
cl_base* cl_base::ret_head_obj() {
	return head_obj;
}
cl_base* cl_base::ret_child(string chld_name) {
	for (int i = 0; i < child.size(); i++) {
		if (child[i]->name == chld_name) {
			return child[i];
		}
	}
	return nullptr;
}
cl_base::~cl_base() {
	for (int i = 0; i < child.size(); i++) {
		delete child[i];
	}
}
cl_base* cl_base::find_obj_branch(string ObjName) {
	if (ret_name() == ObjName) {
		return this;
	}
	for (int i = 0; i < child.size(); i++) {
		cl_base* sub_child = child[i]->find_obj_branch(ObjName);
		if (sub_child != nullptr) {
			return sub_child;
		}
	}
	return nullptr;
}
cl_base* cl_base::find_obj_tree(string ObjName) {
	cl_base* obj = this;
	while (obj->ret_head_obj()) {
		obj = obj->ret_head_obj();
	}
	// находим количество объектов с одинаковым имененм
	int count = 0;
	if (ObjName == ret_name()) return this;
	for (int i = 0; i < child.size(); i++) {
		if (child[i]->ret_name() == ObjName) {
			count++;
		}
	}
	if (count != 1) return nullptr; // если в ветви несколько объектов с одинаковым названием выводим nullptr
	return find_obj_branch(ObjName); // находим указатель на этот объект
}
void cl_base::print_objects() {

}