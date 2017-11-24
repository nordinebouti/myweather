#ifndef				__CLIENT_H__
# define			__CLIENT_H__

#include			<czmq.h>
#include			<string.h>
#include			<stdio.h>
#include			<unistd.h>

int					my_strlen(const char *str);
void				my_putchar(const char c);
void				my_putstr(const char *str);
int					my_strcmp(const char *s1, const char *s2);
char				*my_strdup(const char *str);
int					my_putnbr(int nb);
void          		show_details(char *str_dprt);

#endif