#include 				"serv.h"

int             my_putnbr(int nb)
{
  int           div;
  int           neg;

  div = 1;
  neg = 0;
  if (nb == -2147483648)
  {
    my_putstr("-2147483648");
    neg = 1;
  }
  if (neg != 1)
  {  
    if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
    while ((nb / div) >= 10)
      div = div * 10;
    while (div > 0)
    {
      my_putchar((nb / div) % 10 + 48);
      div = div / 10;
    }
  }
  return (nb);
}

void			        my_putchar(const char c)
{
  write(1, &c, 1);
}

char             *my_strdup(const char *str)
{
  int            i;
  char           *copy;
  
  i = 0;
  copy = NULL;
  if ((copy = malloc((my_strlen(str) + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      copy[i] = str[i];
      i++;
    }
  copy[i] = '\0';
  return (copy);
}

void			        my_putstr(const char *str)
{
  write(1, str, my_strlen(str));
}

char          *my_strcat(char *dest, char *src)
{
  int         i;
  int         j;

  i = 0;
  j = my_strlen(dest);
  while (src[i] != '\0')
    {
      dest[j] = src[i];
      ++i;
      ++j;
    }
  dest[j] = '\0';
  return (dest);
}

int			          	my_strlen(const char *str)
{
	int					i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}