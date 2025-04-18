#include "cl_application.h"

cl_application::cl_application(cl_base* head_obj) : cl_base(head_obj) {}

void cl_application::build_tree_objects() {
	string base_name, child_name;
	cl_base* base = this;
	cl_base* child = nullptr;
	cin >> base_name;
	base->redact_name(base_name);
	while (true) {
		cin >> base_name >> child_name;
		if (base_name == child_name) {
			break;
		}
		if ((child != nullptr) && (base_name == child->ret_name())) {
			base = child;
		}
		if ((base->ret_child(child_name) == nullptr) && (base_name == base->ret_name())) {
			child = new cl_1(base, child_name);
		}
	}
}

int cl_application::exec_app() {
	cout << ret_name();
	tree();
	return 0;
}
