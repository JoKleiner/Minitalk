/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:02:01 by joklein           #+#    #+#             */
/*   Updated: 2024/11/19 19:34:44 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int		ft_atoi(const char *str);

void	handler(int pid, int cha)
{
	int	i;
	int	result;

	i = 0;
	while (i < 7)
	{
		result = (cha >> (6 - i)) & 1;
		if (result == 0)
			kill(pid, SIGUSR1);
		else if (result == 1)
			kill(pid, SIGUSR2);
		usleep(500);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	u;
	int	pid;

	if (argc != 3)
	{
		printf("Wrong input\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		printf("Wrong PID\n");
		return (1);
	}
	i = strlen(argv[2]);
	u = 0;
	while (u < i)
	{
		handler(pid, argv[2][u]);
		u++;
	}
	return (0);
}
