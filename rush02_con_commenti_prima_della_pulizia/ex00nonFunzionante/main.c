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

int	insert_nbr(char *str);
int	is_valid_number(char *str);
char	*ft_strtrim(char *str);
char	**slice_str(char *str, char	*str_sliced[]);

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (is_valid_number(argv[1]))
		{
			//caso1: converti il numero
			insert_nbr(argv[1]);
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
		//printf("nuovo dizionario\n");
		string = ft_strtrim(argv[1]);
		//printf("string senza spazi:%s\n", string);
		free (string);
		//char	*str_sliced[2];
		//slice_str(argv[1], str_sliced);
	}
	else if (argc > 3)
	{
		write(1, "Error! troppi argomenti\n", 25);
	}
}
