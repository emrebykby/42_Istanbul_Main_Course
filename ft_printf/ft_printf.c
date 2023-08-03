/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebuyukba <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:46:41 by ebuyukba          #+#    #+#             */
/*   Updated: 2022/05/10 18:18:55 by ebuyukba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == 0)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
void	ft_putnbr_fd(int n, int fd)
{
	long int	n2;

	n2 = n;
	if (n2 < 0)
	{
		n2 = (n2 * -1);
		write(fd, "-", 1);
	}
	if (n2 < 10)
		ft_putchar_fd(n2 + '0', fd);
	else
	{
		ft_putnbr_fd(n2 / 10, fd);
		ft_putnbr_fd(n2 % 10, fd);
	}
}
char	check_after_percent(const char *s, int t)
{
	if (s[t] == '%')
		ft_putchar_fd('%', 1);
	else if (s[t] == 'c')
		return ('c');
	else if (s[t] == 's' || s[t] == 'x' || s[t] == 'X' || s[t] == 'p')
		return ('s');
	else if (s[t] == 'd' || s[t] == 'i' || s[t] == 'u')
		return ('i');
	return ('x');
}
int	len_str(const char *str, int nbr)
{
	int	len;

	len = 0;
	while (str[nbr + len] != '\0' && str[nbr + len] != '%')
		len++;
	return (len);
}
int	print_buff(const char *str, char *buff, int nbr, int len)
{
	int	i;

	i = 0;
	if (len == 0)
		return (nbr + 2);
	buff = malloc(sizeof(char) * (len + 1));
	if (!buff)
		return (0);
	while (str[nbr] != '\0' && str[nbr] != '%')
	{
		buff[i] = str[nbr];
		nbr++;
		i++;
	}
	buff[i] = '\0';
	ft_putstr_fd(buff, 1);
	free (buff);
	if (str[nbr] == '\0')
		return (-1);
	return (nbr + 2);
}
int	ft_printf(const char *str,...)
{
	va_list	ag;
	char	*buff;
	int	nbr;
	int	len;
	int	static_len;
	char	return_char;

	va_start (ag, str);
	buff = NULL;
	nbr = 0;
	static_len = 0;
	len = 0;
	while (str[nbr] != '\0')
	{
		if (str[static_len] == '%')
		{
			static_len++;
			return_char = check_after_percent(str, static_len);
			if (return_char == 'c')
				ft_putchar_fd(va_arg(ag, int), 1);
			else if (return_char == 's')
				ft_putstr_fd(va_arg(ag, char *), 1);
			else if (return_char == 'i')
				ft_putnbr_fd(va_arg(ag, int), 1);
			static_len++;
		}
		len = len_str(str, nbr);
        static_len += len;
        nbr = print_buff(str, buff, nbr, len);
	}
	va_end (ag);
	return (0);
}

int	main(void)
{
	int a = 10;
	int *b = &a;
	ft_printf("%p\n",b);
	printf("%p\n",b);
	ft_printf("%%12emre%dhello%cmre%s%%\n", 15, 'e',"sanırım başardım");
	printf(">%%12emre%dhello%cmre%s%%\n", 15, 'e', "sanırım başardım");
}
