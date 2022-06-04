#include "hls.h"

node_t *create_node(char *dirname, char *fullpath, struct stat *statbuf)
{
    node_t *node = malloc(sizeof(node_t));
    if (node == NULL)
    {
        error_handler("hls: malloc error: ");
    }
    node->dirname = dirname;
    node->fullpath = fullpath;
    node->statbuf = statbuf;
    node->next = NULL;
    return (node);d
}

