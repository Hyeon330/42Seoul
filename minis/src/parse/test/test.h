#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

enum e_redir_type {
	IN_REDIR = 0,
	OUT_REDIR,
	APPEND,
	HEREDOC
};

typedef struct s_redir {
	struct s_redir	*next;
	char			*file;
	int				type;
}	t_redir;

typedef struct s_cmd {
	struct s_cmd	*next;
	t_redir			*red;
	char			*cmd;
	char			**av;
	int				ac;
}	t_cmd;

typedef struct s_node_env {
	struct s_node_env	*left;
	struct s_node_env	*right;
	char				*key;
	char				*val;
}	t_node_env;

typedef struct s_env {
	t_node_env	*root;
	int			size;
}	t_env;

typedef struct s_token {
	t_cmd	*cmd;
	int		size;
}	t_token;

typedef struct s_vars {
	t_env	env;
	t_token	token;
}	t_vars;

typedef struct s_eof {
	char			*str;
	struct s_eor	*next;
} t_eof;

typedef struct s_heredoc {
	char	**av;
	char	*cmd;
	char	*outfile;
	char	*infile;
	t_eof	*eof;
	int		heredoc_cnt;
} t_heredoc;

//test_split
char	**ft_split(char const *s, char c);
int	fill_ppc(char **ppc, char const *s, char c);
void	fill_pc_split(char **ppc, char const *s, int ppc_i, int pc_size);
int	count_c(char const *s, char c);
int	count_s(char const *s, char c);

//test_count_token
void	error(char *msg);
int		count_redir(char *s, int i);
int		count_quote(char *s, int i);
int		count_token(char *s, char c);
void	free_splited_token(char **s);

//test_split_token
char	*when_redir(char **s);
char	*when_charset(char **s, char c);
char	*splite_quote(char *s);
char	*when_quote(char **s);
char	**do_split_token(char *s, char **splited, char c);
char	**split_token_main(char *str);

//test_utils
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
void	input_pc(char *pc, int n, int n_size, int sign);

//test_syntax_check
void	syntax_check(char **splited, int order);
void	syntax_word(char **splited, int i);
void	syntax_redirection(char **splited, int i);
int		check_redirection(char *str);

//test_tokenize
void	init_vars(t_vars *vars);
t_cmd	*init_cmd();
t_redir	*init_redir();
t_cmd	*tokenize(t_cmd *cmd, char **splited);
char	*tokenize_cmd(t_cmd *cmd, char *str);
t_redir	*tokenize_redir(t_cmd *cmd, char *redir, char *file);

#endif
