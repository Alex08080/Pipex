/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:54:50 by alex              #+#    #+#             */
/*   Updated: 2025/12/04 23:50:26 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

t_data	*new_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		free(data);
		return (NULL);
	}
	data->is_neg = 0;
	data->is_zero = 0;
	data->is_null = 0;
	data->len = 0;
	data->str = NULL;
	data->is_char_null = 0;
	return (data);
}
