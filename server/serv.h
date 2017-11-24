#ifndef				__SERV_H__
# define			__SERV_H__

#include			<czmq.h>
#include			<string.h>
#include			<stdio.h>
#include			<unistd.h>

typedef struct 		s_dprt t_dpt;

struct				s_dprt
{
	char			*data;
	t_dpt			*next;
};

int					my_strlen(const char *str);
void				my_putchar(const char c);
void				my_putstr(const char *str);
char				*my_strdup(const char *str);
int					my_putnbr(int nb);
t_dpt				*create_list(char	*str_dprt);
t_dpt				*add_dpt(t_dpt *list, char *elmt);
void				free_list(t_dpt *list);

#endif