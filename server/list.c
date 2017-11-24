#include	"serv.h"

t_dpt		*create_list(char	*str_dprt)
{
	t_dpt	*list;
	char	*tok;

	list = NULL;
	list = malloc(sizeof(t_dpt));
	list->data = NULL;
	list->next = NULL;
	tok = NULL;
	tok = strtok(str_dprt, "\n");
	while (tok != NULL)
	{
		list = add_dpt(list, tok);
		tok = strtok(NULL, "\n");
	}
	return(list);
}

t_dpt		*add_dpt(t_dpt *list, char *elmt)
{
	t_dpt	*new_dprt;

	new_dprt = malloc(sizeof(t_dpt));
	new_dprt->data = my_strdup(elmt);
    new_dprt->next = list;
    return (new_dprt);

}
