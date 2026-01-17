/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:51:07 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/17 13:53:18 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size != 0 && nmemb > ((size_t) - 1) / size)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("=== Test ft_calloc ===\n\n");

    int *a = ft_calloc(5, sizeof(int));
    int *b = calloc(5, sizeof(int));

    printf("ft_calloc : ");
    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("calloc    : ");
    for (int i = 0; i < 5; i++)
        printf("%d ", b[i]);
    printf("\n");

    free(a);
    free(b);

    return 0;
}
*/
