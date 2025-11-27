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

int	insert_nbr(char *str);
int	is_valid_number(char *str);
char	*ft_strtrim(char *str);
char	**slice_str(char *str, char	*str_sliced[]);
char	*read_dict_file(char *filename);  // Add this function
char	*find_value(char *dict, char *key);
void	convert_number(char *num, char *dict, int *first);

char	*read_dict_file(char *filename)
{
	int		fd;
	char	buffer[4096];
	int		ret;
	char	*dict;
	int		len;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	ret = read(fd, buffer, 4095);
	if (ret < 0)
	{
		close(fd);
		return (NULL);
	}
	buffer[ret] = '\0';
	len = ret;
	dict = malloc(len + 1);
	if (!dict)
	{
		close(fd);
		return (NULL);
	}
	ret = 0;
	while (ret < len)
	{
		dict[ret] = buffer[ret];
		ret++;
	}
	dict[ret] = '\0';
	close(fd);
	return (dict);
}

int	main(int argc, char **argv)
{
	if (is_valid_number(argv[1]))
	{
		char	*dict;
		int		first;
	
		dict = read_dict_file("numbers.dict");
		if (!dict)
		{
			write(1, "Dict Error\n", 11);
			return (1);
		}
		first = 1;
		convert_number(argv[1], dict, &first);
		write(1, "\n", 1);
		free(dict);
	}
	if (argc == 2)
	{
		if (is_valid_number(argv[1]))
		{
			//caso1: converti il numero
			//insert_nbr(number, struttura);
			printf("numero valido PROSEGUI\n");
		}
		else
		{
			write(1, "Error! numero non valido\n", 25);
		}
	}
	if (argc == 3)
	{
		char	*string;
		//caso2: primo argomento: nuovo dizionario, 
		//secondo argomento: numero da convertire
		printf("nuovo dizionario\n");
		string = ft_strtrim(argv[1]);
		printf("string senza spazi:%s\n", string);
		free (string);
		//char	*str_sliced[2];
		//slice_str(argv[1], str_sliced);
	}
	else if (argc > 3)
	{
		write(1, "Error! troppi argomenti\n", 25);
	}
}
