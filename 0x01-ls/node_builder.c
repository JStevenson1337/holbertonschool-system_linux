#include "hls.h"

node_t *create_node(char *dirname, char *fullpath, struct stat *statbuf)
{
    node_t *node;

    node = malloc(sizeof(node_t));
    if (node == NULL)
    {
        print_error_exit("hls: malloc error: ");
    }
    node->dirname = dirname;
    node->fullpath = fullpath;
    node->stat = *statbuf;
    node->next = NULL;
    node->prev = NULL;
    return (node);
}

