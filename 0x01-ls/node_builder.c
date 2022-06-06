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

node_t add_node(node_t *node)
{
    node_t *tmp, *head;

    tmp = head = get_head();
    while (tmp != NULL)
    {
        if (tmp->stat.st_mtime < node->stat.st_mtime)
        {
            break;
        }
        tmp = tmp->next;
    }
    if (tmp == NULL)
    {
        node->prev = head;
        node->next = NULL;
        head->next = node;
        head = node;
    }
    else if (tmp == head)
    {
        node->prev = NULL;
        node->next = tmp;
        tmp->prev = node;
        head = node;
    }
    else
    {
        node->prev = tmp->prev;
        node->next = tmp;
        tmp->prev->next = node;
        tmp->prev = node;
    }
    return (head);
}


node_t get_head(node_t *head)
{
    if (head == NULL)
    {
        head = malloc(sizeof(node_t));
        if (head == NULL)
        {
            print_error_exit("hls: malloc error: ");
        }
        head->next = NULL;
        head->prev = NULL;
    }
    return (head);
}

