/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:28:36 by joklein           #+#    #+#             */
/*   Updated: 2024/11/19 19:36:24 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		g_count;

void	handler(int signum)
{
	int	cha;

	if (signum == SIGUSR1)
		cha = (cha << 1) | 0;
	else if (signum == SIGUSR2)
		cha = (cha << 1) | 1;
	g_count++;
	if (g_count == 7)
	{
		write(1, &cha, 1);
		cha = 0;
		g_count = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	printf("Server started. PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}

// signal
// sigemptyset
// sigaddset
// sigaction
// kill			1
// getpid		1
// pause		1
// sleep
// usleep
// exit