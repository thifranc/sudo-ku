/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 09:28:27 by thifranc          #+#    #+#             */
/*   Updated: 2015/10/25 16:22:34 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_line_test(char c, char *str);

int	ft_col_test(char c, char **tab, int x);

int ft_bloc_test(char c, char **tab, int x, int y);

int	ft_sudoku(char **tab, int x, int y)
{
	char c;

	c = '1';
	if (x == 8 && y == 9)
	while (c <= '9')
	{
		if (ft_line_test(c, tab[y]) == 0
			&& ft_col_test(c, tab, x) == 0 
			&& ft_bloc_test(c, tab, x, y) == 0)
		{
			tab[y][x] = c;
			return (1);
			}
			c++;
	}
	if (tab[y][x] != '.')
	{
		if (x == 8)
		{
			if (ft_sudoku(tab, 0, y + 1) == 1)
				return (1);
		}
		else if (ft_sudoku(tab, x + 1, y) == 1)
			return (1);
	}
	while (c <= '9')
	{
		if (ft_line_test(c, tab[y]) == 0
			&& ft_col_test(c, tab, x) == 0 
			&& ft_bloc_test(c, tab, x, y) == 0)
		{
			tab[y][x] = c;
			if (x == 8)
			{
				if (ft_sudoku(tab, 0, y + 1) == 1)
					return (1);
			}
			else if (ft_sudoku(tab, x + 1, y) == 1)
				return (1);
		}
		c++;
	}
	tab[y][x] = '.';
	return (0);
}
