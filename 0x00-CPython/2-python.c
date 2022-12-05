#include <Python.h>
#include <stdio.h>
#define PY_REP(x) (((PyObject *)(x))->ob_type)
#define DATATYPE PY_REP(((PyListObject *)(p))->ob_item[i])->tp_name
#define MAX_SIZE 15
void print_python_bytes(PyObject *p);
void print_python_float(PyObject *p);

/**
 *print_python_list - function to print about list
 *@p: pointer to refer to a list of python
 *Return: Nothing
 */
void print_python_list(PyObject *p)
{
	int i = 0, tamano = 0;

	printf("[*] Python list info\n");
	fflush(stdout);
	if (PyList_Check(p))
	{
		tamano = (int)(((PyVarObject *)(p))->ob_size);

		printf("[*] Size of the Python List = %d\n", tamano);
		fflush(stdout);
		printf("[*] Allocated = %d\n", (int)(((PyListObject *)(p))->allocated));
		fflush(stdout);
		for (i = 0; i < tamano; i++)
		{
			printf("Element %d: %s\n", i, DATATYPE);
			fflush(stdout);
			if (PyBytes_Check((((PyListObject *)(p))->ob_item[i])))
				print_python_bytes((((PyListObject *)(p))->ob_item[i]));
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
	int tamano = 0, printed = 0, i = 0;
	char *buffer, copy_arr[100];

	printf("[.] bytes object info\n");
	fflush(stdout);
	if (PyBytes_Check(p))
	{
		buffer = ((PyBytesObject *)(p))->ob_sval;
		tamano = (int)PyBytes_Size(p);
		if (tamano >= 10)
			printed = 10;
		else
			printed = tamano + 1;
		strcpy(copy_arr, buffer);
		for (i = 0; i < tamano; i++)
		{
			if (copy_arr[i] < 0)
				copy_arr[i] = '?';
		}
		printf("  size: %d\n", tamano);
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
