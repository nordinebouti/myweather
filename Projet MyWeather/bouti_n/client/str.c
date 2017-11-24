#include 				"client.h"


int                 my_strlen(const char *str)
{
  int         i;

  i = 0;
  while (str[i] != '\0')
    ++i;
  return (i);
}

void              my_putchar(const char c)
{
  write(1, &c, 1);
}

void              my_putstr(const char *str)
{
  write(1, str, my_strlen(str));
}

char			       *my_strdup(const char *str)
{
  int			       i;
  char			     *copy;
  
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

int    					my_putnbr(int nb)
{
	int    				div;
	int    				neg;

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

void          show_details(char *str_dprt)
{
  char  *info;

  info = NULL;
  info = strtok(str_dprt, ",");
  my_putstr("Zip code : ");
  my_putstr(info);
  info = strtok(NULL, ",");
  my_putstr("\nDépartement Name : ");
  my_putstr(info);
  info = strtok(NULL, ",");
  my_putstr("\nWeather : ");
  my_putstr(info);
  info = strtok(NULL, ",");
  my_putstr("\nTempérature : ");
  my_putstr(info);
  my_putstr("\n");
}