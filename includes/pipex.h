/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 23:22:01 by ycribier          #+#    #+#             */
/*   Updated: 2013/12/31 00:06:37 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PIPEX_H
# define	PIPEX_H

typedef struct		s_pipe
{
	char	*file1;
	char	*file2;
	char	*cmd1;
	char	*cmd2;
	char	**args1;
	char	**args2;
	char	**env;
}					t_pipe;


/* DEBUG */
void	dbg_chk_st_pipe(t_pipe *st_pipe);

#endif	/* !PIPEX_H */
