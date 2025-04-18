#ifndef __CL_APPLICATION__H
#define __CL_APPLICATION__H
#include "cl_base.h"
#include "cl_1.h"
class cl_application : public cl_base {
public:
	cl_application(cl_base* head_obj); // конструктор, создает корневой объект
	void build_tree_objects(); // создает иерархию объектов
	int exec_app(); // запускает алгоритм программыы
};

#endif
