#include "hls.h"

node_t *create_node(file_t *file)
{
    node_t *node = malloc(sizeof(node_t));
    if (!node)
        print_error_exit("hls: malloc error: ");
    node->file = file;
    node->next = NULL;
    return (node);
}

node_t *add_node(node_t *node, file_t *file)
{
    node_t *new_node = create_node(file);
    if (!node)
        return (new_node);
    new_node->next = node;
    return (new_node);
}

node_t *add_node_end(node_t *node, file_t *file)
{
    node_t *new_node = create_node(file);
    if (!node)
        return (new_node);
    node_t *tmp = node;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new_node;
    return (node);
}

void free_node(node_t *node)
{
    if (!node)
        return;
    free_node(node->next);
    free(node->file);
    free(node);
}

