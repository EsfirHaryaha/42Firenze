/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 11:03:36 by eharyaha          #+#    #+#             */
/*   Updated: 2025/11/02 11:03:42 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	**slice_str(char *str, char	*str_sliced[]);
char    *read_dict_file(char *buffer, int size);
char	*ft_strncpy(char *dest, char *src, int n);

void	slice_row(char *str, char **arr)
{
	int i;
	int j;
	int y;
	
	i = 0;
	j = i;
	y = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			ft_strncpy(arr[y], &str[j], i - j);
			j = i + 1;
			y++;
		}
		++i;
	}
}
/*typedef struct
{
	char key[];
	char value[];
} Dict;
*/
int	insert_nbr(char *str)
{
	(void) str;
	char *dizionario_str;
	char buffer[4096];
	char *str_sliced[2];
	char **sliced_str;
	char *rows[200000];
	
	dizionario_str = read_dict_file(buffer, sizeof(buffer) - 1);
	if (dizionario_str == NULL)
        	return (0);
        slice_row(dizionario_str, rows);
        //Dict dictonary;
        sliced_str = slice_str(rows[0], str_sliced);
 	printf("%s\n", sliced_str[0]);     
 	printf("%s\n tatni caratteri", sliced_str[1]);   
        
	return (1);
}
