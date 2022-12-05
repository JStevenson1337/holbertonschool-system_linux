#include <Python.h>
/**
 * print_python_list_info - this prints the data type inside lists
 * @p: - Python data type that's a list
 * Returns: Nothing
 */
void print_python_list(PyObject *p)
{
	int i = 0;
	PyListObject *ptr;

	ptr = (PyListObject *)p;
	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %d\n", (int)(PyList_Size(p)));
	printf("[*] Allocated = %d\n", (int)ptr->allocated);
	for (i = 0; i < (int)(PyList_Size(p)); i++)
		printf("Element %d: %s\n", i, Py_TYPE(ptr->ob_item[i])->tp_name);
}
