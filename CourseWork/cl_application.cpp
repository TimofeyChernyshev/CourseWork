#include "cl_application.h"

cl_application::cl_application(cl_base* head_obj) : cl_base(head_obj) {}

void cl_application::build_tree_objects() {
	string base_name, child_name;
	cl_base* base = this;
	cl_base* child = nullptr;
	int classNum, status;
	cin >> base_name;
	base->redact_name(base_name);
	// ���� ��� ���������� �������� � ������
	while (true) {
		cin >> base_name; // ���� ����� ������������� ������
		// ���� ����������� �������� ����� "endtree", �� ����� �� �����
		if (base_name == "endtree") { 
			break;
		}
		// ����� ������������� ������� �� ������
		cl_base* base_obj = find_obj_tree(base_name);
		cin >> child_name >> classNum; // ���� ����� ��������� ������ � ������ ��� ������
		// ���� ������ ������������ ������, � �������� ��� ������ ��������� �� ��������� ��� � ������
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
	// ���� ��� ��������� ��������� ���������� ��� �������� ������
	while (cin >> base_name) {
		cin >> status;
		cl_base* obj = find_obj_tree(base_name);
		if (obj != nullptr) { // ���� ������ ������ � ����� ������ �� ������ ��� ���������
			obj->set_status(status);
		}
	}
}
// ����� ������ �������� �������� � ��������� ����������
int cl_application::exec_app() { 
	cout << "Object tree" << endl;
	print_objects();
	cout << endl << "The tree of objects and their readiness" << endl;
	print_objects_status();
	return 0;
}
