/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 17:18:43 by ycribier          #+#    #+#             */
/*   Updated: 2013/12/31 00:11:58 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <memory.h>
#include <unistd.h>
#include "libft.h"
#include "pipex.h"

extern char	**environ;

int		pipex(char **params1, char **params2)
{
	printf("params = %s, %s\n", *params1, *params2);
	/* create the pipe */
	int		pfd[2];
	if (pipe(pfd) == -1)
	{
		printf("pipe failed\n");
		return (1);
	}
	/* create the child */
	int		pid;
	if ((pid = fork()) < 0)
	{
		printf("fork failed\n");
		return (2);
	}
	if (pid == 0)
	{
		/* child */
		close(pfd[1]); /* close the unused write side */
		dup2(pfd[0], 0); /* connect the read side with stdin */
		close(pfd[0]); /* close the read side */
		/* execute the process (wc command) */
		if (execve("/usr/bin/grep", params2, environ) == -1)
			perror("wc err");
		//execlp("wc", "wc", (char *) 0);
		printf("wc failed\n"); /* if execlp returns, it's an error */
		return (3);
	}
	else
	{
		/* parent */
		close(pfd[0]); /* close the unused read side */
		dup2(pfd[1], 1); /* connect the write side with stdout */
		close(pfd[1]); /* close the write side */
		/* execute the process (ls command) */
		if (execve("/bin/ls", params1, environ) == -1)
			perror("ls err");
		//execlp("ls", "ls", (char *)0);
		printf("ls failed\n"); /* if execlp returns, it's an error */
		return (4);
	}
	return (0);
}

/* Send error message, passing a file path is possible */

void	error_msg(char *path, char *message)
{
	if (path)
	{
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
	}
	if (message)
		ft_putendl_fd(message, 2);
}

/* Decompose the entry returning 'command' and 'arguments' separatly */

int		split_cmd(char *entry, char **cmd, char ***args)
{
	char	**tmp;

	tmp = ft_strsplit(entry, ' ');
	if (!tmp)
		return (-1);
	*cmd = tmp[0];
	*args = tmp + 1;
	return (1);
}

/* Check if files (av[2], av[3]) exists */

int		does_file_exist(char *path)
{
	if (access(path, F_OK) == -1)
	{
		error_msg(path, "file doesn't exist.");
		_exit(-1);
	}
	return (1);
}

/* Set the pipe structure with files name, commands + arguments and environ*/

void	set_st_pipe(t_pipe *st_pipe, char **av)
{
	if (does_file_exist(av[1]))
		st_pipe->file1 = av[1];
	if (does_file_exist(av[4]))
		st_pipe->file2 = av[4];
	split_cmd(av[2], &st_pipe->cmd1, &st_pipe->args1);
	split_cmd(av[3], &st_pipe->cmd2, &st_pipe->args2);
	st_pipe->env = environ;
}

int		main(int ac, char **av)
{
	t_pipe	st_pipe;

	if (ac == 5)
	{
		set_st_pipe(&st_pipe, av);
		//dbg_chk_st_pipe(&st_pipe);
	}
	else
		ft_putendl_fd("usage: ./pipex file1 cmd1 cmd2 file2", 2);
	return (0);
}
