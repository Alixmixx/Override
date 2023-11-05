#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void clear_stdin(void)
{
	int inputChar;

	do
	{
		inputChar = getchar();
		if ((char)inputChar == '\n')
		{
			return;
		}
	} while ((char)inputChar != -1);
	return;
}

char get_unum(void)
{
	char local_10[3];

	local_10[0] = 0;
	fflush(stdout);
	__isoc99_scanf(%u, local_10);
	clear_stdin();
	return local_10[0];
}

void prog_timeout(void)
{
	code *pcVar1;

	pcVar1 = (code *)swi(0x80);
	(*pcVar1)();
	return;
}

void enable_timeout_cons(void)
{
	signal(SIGALRM, prog_timeout);
	alarm(60);
	return;
}

int main(void)
{
	int iVar1;
	char *puVar2;
	byte bVar3;
	uint status;
	char buffer[32];
	uint siginfo;
	uint local_1c;
	long local_18;
	__pid_t child_pid;

	bVar3 = 0;
	child_pid = fork();
	puVar2 = buffer;
	bzero(buffer, 32);
	local_18 = 0;
	status = 0;
	if (child_pid == 0)
	{
		prctl(PR_SET_DUMPABLE, SUID_DUMP_USER);
		ptrace(PTRACE_TRACEME, 0, 0, 0);
		puts("Give me some shellcode, k");
		gets(buffer);
	}
	else
	{
		do
		{
			wait(&status);
			siginfo = status;
			if (((status & 0x7f) == 0) ||
				(local_1c = status, '\0' < status & 0x7f + 1) >> 1)
			{
				puts("child is exiting...");
				return 0;
			}
			local_18 = ptrace(PTRACE_PEEKUSER, child_pid, 0x2c, 0);
		} while (local_18 != 0xb);
		puts("no exec() for you");
		kill(child_pid, 9);
	}
	return 0;
}
