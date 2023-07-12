#include "minishell.h"
//실행전 <<가 있는지 검사하고 <<를 만나면 해당 cmd구조체를 heredoc함수로 넘겨준다.
//>>과 <<를 구분해야돼서 e_redir_type에 HEREDOC을 추가함

void	init_heredoc_eof(t_heredoc *heredoc, t_cmd target)
{
	t_redir *temp;

	temp = target.red;
	while (temp != NULL)
	{
		if (temp->type == HEREDOC)
		{
			heredoc->eof = (t_eof *)malloc(sizeof(t_eof) * 1);
			if (!heredoc->eof)
				error("malloc error");
		}
		heredoc->eof->str = temp->file;
		heredoc->eof->next = NULL;
		heredoc->heredoc_cnt++;
		temp = temp->next;
	}
}

void	init_heredoc(t_heredoc *heredoc, t_cmd target)
{
	t_redir	*temp;

	temp = target.red;
	heredoc->cmd = target.cmd;
	heredoc->av = target.av;
	heredoc->heredoc_cnt = 0;
	init_heredoc_eof(heredoc, target);
	while (temp != NULL)
	{
		if (temp->type == OUT_REDIR || temp->type == APPEND)
			heredoc->outfile = temp->file;
		else if (temp->type == IN_REDIR)
			heredoc->infile = temp->file;
		else
			heredoc->infile = ft_strdup("heredoc_tempfile");
		temp = temp->next;
	}
}

void	do_heredoc(t_eof *eof)
{
	t_eof	*temp;
	char	*str;
	int		fd;

	temp = eof;
	while (temp != NULL)
	{
		fd = open("heredoc_tempfile",  O_WRONLY|O_CREAT|O_EXCL|O_TRUNC, 0600);
		if (fd == -1)
			error("open error");
		dup2(fd, STDIN_FILENO);
		str = get_next_line(0);
		while (ft_strncmp(str, eof->str, ft_strlen(eof->str)) != 0)
		{
			free(str);
			str = get_next_line(0);
		}
		free(str);
		close(fd);
		temp = temp->next;
	}
}

void	execve_heredoc(t_heredoc heredoc)
{
	int	infile_fd;
	int	outfile_fd;

	if (heredoc.infile != NULL)
	{
		infile_fd = open(heredoc.infile, O_RDONLY);
		dup2(infile_fd, STDIN_FILENO);
		close (infile_fd);
	}
	if (infile_fd == -1)
		error("open error");
	if (heredoc.outfile != NULL)
	{
		outfile_fd = open(heredoc.outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
		dup2(outfile_fd, STDOUT_FILENO);
		close(outfile_fd);
	}
	if (outfile_fd == -1)
		error("open error");
	if (execve(heredoc.cmd, heredoc.av, NULL) == -1)
		error("execve error");
}

void	heredoc(t_cmd target)
{
	t_heredoc	heredoc;
	pid_t		pid;

	init_heredoc(&heredoc, target);
	do_heredoc(heredoc.eof);//현재 pid에서 해도 되는 것?
	pid = fork();
	if (pid == -1)
		error("fork error");
	if (pid == 0)
		execve_heredoc(heredoc);//새 프로세스에서 해야하는것?
	waitpid(pid, 0, 0);
	unlink("heredoc_tempfile"); //부모 프로세스에서만 해도 되는 것?
}
