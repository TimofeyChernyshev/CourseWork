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
	if (ObjName == ret_name()) return this;
	while (obj->ret_head_obj()) {
		obj = obj->ret_head_obj();
	}
	// ���� � ����� ��������� �������� � ���������� ��������� ������� nullptr
	if (obj->count_name(ObjName) != 1) return nullptr;
	return find_obj_branch(ObjName); // ������� ��������� �� ���� ������
}
void cl_base::print_objects(int space) {
	cout << ret_name();
	if (!child.empty()) {
		for (int i = 0; i < child.size(); i++) {
			cout << endl;
			for (int j = 0; j < space; j++) cout << " ";
			child[i]->print_objects(space + 4);
		}
	}
}
void cl_base::print_objects_status(int space) {
	if (status) {
		cout << ret_name() << " is ready";
	}
	else {
		cout << ret_name() << " is not ready";
	}
	if (!child.empty()) {
		for (int i = 0; i < child.size(); i++) {
			cout << endl;
			for (int j = 0; j < space; j++) cout << " "; // ������ ������ ��������
			child[i]->print_objects_status(space + 4);
		}
	}
}
void cl_base::set_status(int status) {
	// ���� �������� ���������� ��������� ���������� ��� ��������� ������ ����� ����������
	// ���������� ��� ��� ������������� ������, �� ���������� ��������� ���������� �������� false
	// ����� ��������� ���������� false ���� �� ���� ������� ���������� � ��� ��������� ���������� 
	// (�� ������ ����� set_status ��� ����������� �������)
	if (ret_head_obj() && (ret_head_obj()->status == false)) {
		this->status = false;
	}
	else {
		this->status = status;
	}
	// ���� ������ ������� false, �� ��������� ��� ���� ��� �������� ������� ����� �� ���������
	if (status == false) {
		for (int i = 0; i < child.size(); i++) {
			child[i]->set_status(false);
		}
	}
}
int cl_base::count_name(string name) {
	int count = 0;
	if (ret_name() == name) count++;
	for (int i = 0; i < child.size(); i++) {
		count += child[i]->count_name(name);
	}
	return count;
}