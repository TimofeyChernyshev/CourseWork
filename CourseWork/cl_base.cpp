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
void cl_base::tree() {
	if (!child.empty()) {
		cout << endl << name;
		for (int i = 0; i < child.size(); i++) {
			cout << "  " << child[i]->name;
		}
		child[child.size() - 1]->tree();
	}
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

}
