/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:02:01 by joklein           #+#    #+#             */
/*   Updated: 2024/11/20 11:51:49 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	cha_to_bit_send(int pid, int cha)
{
	int	i;
	int	result;

	i = 0;
	while (i < 8)
	{
		result = (cha >> (7 - i)) & 1;
		if (result == 0)
			kill(pid, SIGUSR1);
		else if (result == 1)
			kill(pid, SIGUSR2);
		usleep(200);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc != 3)
	{
		ft_printf("Wrong input\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Wrong PID\n");
		return (1);
	}
	while (argv[2][i])
	{
		cha_to_bit_send(pid, argv[2][i]);
		i++;
	}
	return (0);
}
