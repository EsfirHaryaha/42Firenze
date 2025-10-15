/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:44:11 by eharyaha          #+#    #+#             */
/*   Updated: 2025/10/15 16:48:11 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_is_negative(int n) {
	char negativo = 'N';
	char positivo = 'P';

	if(n<0) {
		write(1, &negativo, 1);
	} else {
		write(1, &positivo, 1);
	}
}
