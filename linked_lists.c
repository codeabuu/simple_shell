#include "shell.h"

/**
* add_node - adds a node to the start of the list
* @head: address of pointer to head node
* @str: string field of node
* @num: node index used by history
*
* Return: size of list
*/
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_setmem((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
* add_node_end - adds a node to the end of the list
* @head: address of pointer to head node
* @str: string field of node
* @num: node index used by history
*
* Return: size of list
*/
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_setmem((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
	for (; node->next; node = node->next)
		;
	node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
* print_ls_string - prints only the string element of a list_t linked list
* @h: pointer to first node
*
* Return: size of list
*/
size_t print_ls_string(const list_t *h)
{
	size_t i;

	for (i = 0; h; h = h->next)
	{
	_puts(h->str ? h->str : "(nil)");
	_puts("\n");
	i++;
	}
	return (i);
}

/**
* delete_node_at_index - deletes node at given index
* @head: address of pointer to first node
* @index: index of node to delete
*
* Return: 1 on success, 0 on failure
*/
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	for (i = 0, node = *head; node; i++, prev_node = node, node = node->next)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
	}
	return (0);
}
/**
* free_list - this frees all nodes of a list
* @head_ptr: the address of pointer to head node
*
* Return: void
*/
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head = *head_ptr;

	if (!head_ptr || !*head_ptr)
		return;
	for (node = head; node; node = next_node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
	}
	*head_ptr = NULL;
}
