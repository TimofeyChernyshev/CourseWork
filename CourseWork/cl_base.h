#ifndef __CL_BASE__H
#define __CL_BASE__H
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class cl_base {
	string name; // ��� �������
	cl_base* head_obj = nullptr; // ��������� �� ������������ ������
	vector<cl_base*> child; // ������ �������� ��������
	bool status; // ��������� �������
public:
	cl_base(cl_base* head_obj, string name = "Base_object"); // �����������
	bool redact_name(string name); // �������� ��� �������
	string ret_name(); // ���������� ��� �������
	cl_base* ret_head_obj(); // ���������� ��������� �� �������� ������
	cl_base* ret_child(string chld_name); // ���������� ��������� �� �������� ������
	~cl_base(); // ����������
	cl_base* find_obj_branch(string ObjName); // ����� ������ ������� �� ����� �� �����
	cl_base* find_obj_tree(string ObjName); // ����� ������ ������� �� ����� �� ���� ������ ��������
	void print_objects(int space = 4); // ����� ������ �������� �������� �� �������� �������
									   // ��� ������� ��������� ������� ��������� ����� 4 ��������
	void print_objects_status(int space = 4); // ����� ������ �������� �������� � ��������� ���������� �� �������� �������
	void set_status(int status_num); // ����� ��������� ���������� �������, �������� - ����� ���������
};

#endif
