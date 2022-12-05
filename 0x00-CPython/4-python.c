#include <Python.h>

/**
 *print_python_string - function to print about list
 *@p: pointer to refer to a byte object of python
 *Return: Nothing
 */
void print_python_string(PyObject *p)
{
	int size = 0;
	char *buffer;

	printf("[.] string object info\n");
	fflush(stdout);
	if (PyUnicode_Check(p) && PyUnicode_READY(p) == 0)
	{
		buffer = (char *)PyUnicode_AsUTF8(p);
		size = (int) PyUnicode_GET_LENGTH(p);
		if (PyUnicode_IS_COMPACT_ASCII(p))
		{
			printf("  type: compact ascii\n");
		}
		else
		{
			printf("  type: compact unicode object\n");
		}
		fflush(stdout);
		printf("  length: %d\n", size);
		fflush(stdout);
		printf("  value: %s\n", buffer);
		fflush(stdout);
	}
	else
	{
		printf("  [ERROR] Invalid String Object\n");
		fflush(stdout);
	}
}
