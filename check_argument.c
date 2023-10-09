/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:26:30 by seoson            #+#    #+#             */
/*   Updated: 2023/10/02 15:00:02 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_argument(int argc, char *argv)
{
	int	argv_len;

	if (argc == 1)
		ft_error("Error: empty argument\n");
	else if (argc > 2)
		ft_error("Error: too many arguments\n");
	argv_len = ft_strlen(argv);
	if (argv_len == 0)
		ft_error("Error: empty argument\n");
	if (argv_len < 5 || argv[argv_len - 1] != 'f' || argv[argv_len - 2]
		!= 'd' || argv[argv_len - 3] != 'f' || argv[argv_len - 4] != '.')
		ft_error("Error: Invalid file\n");
}
