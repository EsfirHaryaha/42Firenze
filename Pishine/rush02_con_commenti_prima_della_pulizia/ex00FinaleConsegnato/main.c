/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 11:03:59 by eharyaha          #+#    #+#             */
/*   Updated: 2025/11/02 11:04:03 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int		is_valid_number(char *str);
char	*read_dict_file(char *filename);
void	convert_number(char *str, char *dict, int *first);
char	*ft_strtrim(char *str);
int		insert_nbr(char *str);
int		is_valid_number(char *str);
char	*ft_strtrim(char *str);
char	**slice_str(char *str, char	*str_sliced[]);
char	*read_dict_file(char *filename);
char	*find_value(char *dict, char *key);
void	convert_number(char *num, char *dict, int *first);

int	handle_one_arg(char *arg)
{
	char	*dict;
	int		first;

	if (!is_valid_number(arg))
	{
		write(1, "Error! numero non valido\n", 25);
		return (1);
	}
	dict = read_dict_file("numbers.dict");
	if (!dict)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	first = 1;
	convert_number(arg, dict, &first);
	write(1, "\n", 1);
	free(dict);
	return (0);
}

void	handle_two_args(char *arg)
{
	char	*string;

	string = ft_strtrim(arg);
	free(string);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		handle_one_arg(argv[1]);
	else if (argc == 3)
		handle_two_args(argv[1]);
	else if (argc > 3)
		write(1, "Error! troppi argomenti\n", 25);
	return (0);
}
