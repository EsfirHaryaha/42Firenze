/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:49:33 by eharyaha          #+#    #+#             */
/*   Updated: 2025/11/05 16:49:53 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>
#include <stdio.h>

void	*ft_print_memory(void *addr, unsigned int size);

int	main(void)
{
	char	str[] = "Bonjour les aminches\n\tc'est fou\t"
		"tout ce qu'on peut faire avec.\n\tprint_memory\n\nlol.lol\n";
	ft_print_memory(str, sizeof(str) - 1);
	return (0);
}*/

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puthex(unsigned long num, int digits)
{
	char	*base;
	char	buffer[16];
	int		i;

	base = "0123456789abcdef";
	i = digits - 1;
	while (i >= 0)
	{
		buffer[i] = base[num & 0xF];
		num >>= 4;
		i--;
	}
	write(1, buffer, digits);
}

void	ft_print_hex_content(unsigned char *ptr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			ft_puthex(ptr[i], 2);
		}
		else
		{
			write(1, "  ", 2);
		}
		if (i % 2)
			ft_putchar(' ');
		i++;
	}
}

void	ft_print_ascii(unsigned char *ptr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (ptr[i] >= 32 && ptr[i] <= 126)
			ft_putchar(ptr[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		i;
	unsigned char		*ptr;
	unsigned int		line_size;

	ptr = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		if (size - i >= 16)
		{
			line_size = 16;
		}
		else
		{
			line_size = (size - i);
		}
		ft_puthex((unsigned long)(ptr + i), 16);
		write(1, ": ", 2);
		ft_print_hex_content(ptr + i, line_size);
		ft_print_ascii(ptr + i, line_size);
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}
