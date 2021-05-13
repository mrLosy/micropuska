/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:22:51 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/29 09:59:17 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdint.h>
# include <wchar.h>
# include <stdlib.h>
# include <ctype.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <termios.h>
# include <errno.h>
# include <term.h>
# include <termcap.h>
# include <curses.h>
# include <signal.h>
# include <stdbool.h>
# include <string.h>
# include "minishelldenis.h"
# include "../ultralibx/ft_printf.h"
# define STD_IN 0
# define STD_OUT 1
# define STD_ERROR 2

extern int	g_status;

typedef struct s_history
{
	int			len_array;
	int			current_order_id;
	char		*save_pointer;
	char		**history_array;
	int			count;
	int			up;
}				t_history;

typedef struct s_env
{
	char		**env;
	short int	count;
	char		**exp;
	char		**ex;
}				t_env;

typedef struct s_echo
{
	char		*s_q;
	char		*e_v;
	short int	space;
	short int	space_s;
}				t_echo;

typedef struct s_argumnet
{
	char		*str;
	char		*dst;
	char		*doll;
	char		*file;
	char		**exp;
	char		**dell;
	char		**ac;
	int			out;
	int			in;
	short int	i;
}				t_argument;

typedef struct s_commands
{
	short int		echo;
	short int		n;
	short int		cd;
	short int		pwd;
	short int		exp;
	short int		exp_add;
	short int		env_add;
	short int		unset;
	short int		exit;
	short int		env;
	short int		a_c;
}				t_commands;

typedef struct s_flags
{
	short int		pipe;
	short int		s_l;
	short int		s_m;
	short int		d_l;
	short int		end;
}				t_flags;

typedef struct s_all
{
	char			**paths;
	char			*line;
	short int		i;
	short int		error;
	short int		con;
	short int		kostily;
	int				oldfd_stdin;
	int				oldfd_stdout;
	int				parser_complete;
	int				g_status;
	int				pipe_num;
	int				i_pipe;
	int				**fd;
	int				*pid;
	int				status;
	char *valuefromarr;
	char *keyfromstr;
	char *valuefromstr;
	int check_eq;
	int check_eqarra;
	int str_inarr;
	t_echo			ec;
	t_argument		*argv;
	t_commands		*com;
	t_flags			*flag;
	t_env			m;
	t_history		*history;
	struct termios	term;
}				t_all;

void		ft_parser(t_all *all, char *line);
void		ft_parsing(t_all *all);
void		parser_echo(t_all *all);
void		ft_parser_cd(t_all *all, char **env);
void		ft_parser_env(t_all *all, char **env);
int			ft_isprint_s(int c);
char		*ft_strdup_n(const char *s1, short int h);
int			ft_error(char *line, char *str, char *error, int err);
void		ft_skipspace(char *line, short int *i);
int			ft_strcmp(char *s1, char *s2);
int			ft_putchar(int c);
void		ft_sec_argv(t_all *all, char s);
char		*pwdstr(t_all *all);
void		check_space(t_all *all);
void		flag_n(t_all *all);
void		slash_dol(t_all *all, short int h);
void		rewrite_argv(t_all *all, short int h, char *tmp);
void		ft_parser_export(t_all *all, char **env);
void		rewrite_s_q(t_all *all, short int h, char *tmp);
int			ft_isenv(int c);
void		ft_pars_dol(t_all *all, char **env, short int h);
void		ft_pars_new_com(t_all *all, char **env);
void		ft_pars(t_all *all, char **env);
void		pars_echo(t_all *all, char **env);
void		struct_null(t_all *all);
void		struct_free(t_all *all);
void		struct_zero(t_all *all);
void		ft_pars_pipe(t_all *all, char **env);
void		ft_parser_env_add(t_all *all, char **env);
void		ft_add_env(t_all *all, char **env, char s, char **tmp);
void		ft_parser_unset(t_all *all, char **env);
void		pars_s_l(t_all *all);
void		pars_s_m(t_all *all);
void		pars_d_l(t_all *all);
void		ft_pars_pwd(t_all *all, char **env);
void		ft_checker(t_all *all, char **env);
void		ft_add_char(t_all *all, char s, short int h);
void		ft_pars_d_q(t_all *all, char **env, short int h);
void		ft_pars_s_q(t_all *all, short int h);
void		ft_another_com(t_all *all, char **env);
void		parser_exit(t_all *all);
void		ft_parser_slash(t_all *all, unsigned int k, unsigned int l);
void		check_slash(t_all *all);
void		get_next_command(t_all *data);
void		redirect(t_all *all, char *f);
void		get_previos_command(t_all *data);
void		add_history(t_all *data);
int			count_array(t_all *data);
int			pp_count_array(char **data);
void		error_exit(t_all *all, char **ex);
int			ft_check_export(char *str);
int			findch(char *str, char c);
int			get_paths(t_all *all);
char		*get_path(t_all *all, char *str);
void		Run(t_all *all, int i);
void 		all_denis_work(t_all *all);
int			checkwithstncmp(char *str, char *key);
void		finish_free(t_all *all);
int			run_pipes2(t_all *all);
void		canon_term_on(t_all *all);
void		canon_term_off(t_all *all);
int			what_run(t_all *all, int i);
void		builtin_runner(t_all *all, int i);
void		close_fds(int i, int **fd, int last);
char		**add_arrayelem(char **array, char *str);
char		**delete_arrayelem(char **array, int order);
void		sort_by_ascii(char **array);
void		free_array(char **array);
char		**arr_dup(char **array);
void		ft_export(t_all *all);
char		*get_key_from_str(char *str);
char		*get_value_by_key(char **array, char *key);
int  		find_order_by_key(char **array, char *value);
int			boolarrvalue(char **array, char *key);
char		*get_key(char **array, char *str);
int			rewrite_array(t_all *all, char *str);
void		set_edit(t_all *all, char *str);
void		unset_edit(t_all *all, char *str);
int			only_delete_key(t_all *all, char *str);
void		print_array_export2(char **arr);
char		*get_value_from_str(char *str);
int			find_equal(char *str, char c);
void		print_env(char **arr);
void		incshlvl(t_all *all);
void		ft_termcap(t_all *all);
void		op_red(t_all *all, int i);
int			is_unprint(char *str);
void		close_redirections(t_all *all, int i);
int 		command_call(t_all *all, int i);
void		command_call2(t_all *all, int i);
bool		can_exec(char *path);
bool		is_directory(char *path);
bool		fl_exist(char *path);
bool		execpathtest(char *path, int i);
int			is_path(char *path);
int			findchar(char *str, char c);
int			puterror_three(char *s1, char *s2, char *s3, int code);
void		handle_signals(int signal_code);
t_all		*mini_start(char **env);
int			ctrl_c(void);
void		ctrl_d(void);
#endif
