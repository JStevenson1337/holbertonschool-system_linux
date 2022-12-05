#include <Python.h>
#include <stdio.h>
#define PY_REP(x) (((PyObject *)(x))->ob_type)
#define DATATYPE PY_REP(((PyListObject *)(p))->ob_item[i])->tp_name
#define MAX_SIZE 15
void print_python_bytes(PyObject *p);
void print_python_float(PyObject *p);
void trim_zeros(char *x);
void print_python_float(PyObject *p);

/**
 *print_python_list - function to print about list
 *@p: pointer to refer to a list of python
 *Return: Nothing
 */
void print_python_list(PyObject *p)
{
	int i = 0, size = 0;

	if (PyList_Check(p))
	{
		printf("[*] Python list info\n");
		fflush(stdout);
		size = (int)(((PyVarObject *)(p))->ob_size);

		printf("[*] Size of the Python List = %d\n", size);
		fflush(stdout);
		printf("[*] Allocated = %d\n", (int)(((PyListObject *)(p))->allocated));
		fflush(stdout);
		for (i = 0; i < size; i++)
		{
			printf("Element %d: %s\n", i, DATATYPE);
			fflush(stdout);
			if (PyBytes_Check((((PyListObject *)(p))->ob_item[i])))
				print_python_bytes((((PyListObject *)(p))->ob_item[i]));
			else if (PyFloat_Check((((PyListObject *)(p))->ob_item[i])))
				print_python_float((((PyListObject *)(p))->ob_item[i]));
		}
	}
	else
	{
		printf("  [ERROR] Invalid List Object\n");
		fflush(stdout);
	}
}
/**
 *print_python_bytes - function to print about list
 *@p: pointer to refer to a byte object of python
 *Return: Nothing
 */
void print_python_bytes(PyObject *p)
{
	int size = 0, printed = 0, i = 0;
	char *buffer, copy_arr[100];

	printf("[.] bytes object info\n");
	fflush(stdout);
	if (PyBytes_Check(p))
	{
		buffer = ((PyBytesObject *)(p))->ob_sval;
		size = (int)PyBytes_Size(p);
		if (size >= 10)
			printed = 10;
		else
			printed = size + 1;
		strcpy(copy_arr, buffer);
		for (i = 0; i < size; i++)
		{
			if (copy_arr[i] < 0)
				copy_arr[i] = '?';
		}
		printf("  size: %d\n", size);
		fflush(stdout);
		printf("  trying string: %s\n", copy_arr);
		fflush(stdout);
		printf("  first %d bytes: ", printed);
		fflush(stdout);
		for (i = 0; i < printed; i++)
		{
			printf("%02x", (unsigned char)*(buffer + i));
			fflush(stdout);
			if (i < printed - 1)
			{
				printf(" ");
				fflush(stdout);
			}
		}
			printf("\n");
			fflush(stdout);
	}
	else
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		fflush(stdout);
	}
}
/**
 *trim_zeros - this will cut a string with the zero delimiter
 *@x: string to cut for float logic
 *Return: Nothing
 */
void trim_zeros(char *x)
{
	int i, length, flag_passed = 0;

	length = strlen(x) - 1;
	for (i = 0; i < length; i++)
	{
		if (x[i] == '.' && x[i + 1] == '0')
		{
			i = i + 2;
			x[i] = 0;
			break;
		}
		else if (x[i] == '.')
			flag_passed = 1;
		if (flag_passed == 1 && x[i] == '0')
		{
			x[i] = 0;
			break;
		}
	}
	for (; i < length; i++)
		x[i + 1] = 0;
}
/**
 *print_python_float - function to print about float objects
 *@p: pointer to refer to a list of python
 *Return: Nothing
 */
void print_python_float(PyObject *p)
{
	char *string;
	double float_value;

	printf("[.] float object info\n");
	fflush(stdout);
	if (PyFloat_Check(p))
	{
		float_value = ((PyFloatObject *)(p))->ob_fval;
		string = PyOS_double_to_string(float_value, 'g', 16, 0, NULL);
		printf("  value: %s%s\n", string, strchr(string, '.') ? "" : ".0");
		fflush(stdout);
		PyMem_Free(string);
	}
	else
	{
		printf("  [ERROR] Invalid Float Object\n");
		fflush(stdout);
	}
}
