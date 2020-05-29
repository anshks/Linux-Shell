#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void main()
{
	printf("			Welcome To This Custom Shell				\n");
	printf("			.... Press Enter To Continue				\n");
	char start;
	scanf("%c", &start);
	printf("\e[1;1H\e[2J");
	char hostname[1024];
	hostname[1023] = '\0';
	gethostname(hostname, 1023);
	FILE *fptr;
	fptr = fopen("history.txt", "a+");
	
	char hist_list[1000][1000];
	int id = 0;
	while (1)
	{
		char buf[1024];
		buf[1023] = '\0';
		getcwd(buf, 1023);
		printf("%s@%s:%s$ ", getenv("USER"), hostname, buf);
		char cmd[1000];
		scanf("%[^\n]%*c", cmd);
		for(int akkk=0;cmd[akkk]!='\0';akkk++)
		{
			hist_list[id][akkk]=cmd[akkk];
		}
		// printf(hist_list[id]);
		id++;
		if (cmd[1] == '\0' || cmd[1] == '\n')
		{
			printf("Learn Unix Commands\n");
			cmd[1] = 'a';
		}
		else
		{
			char cmdsplit[100][100];
			char *command;
			int j, ctr;
			j = 0;
			ctr = 0;
			for (int i = 0; i <= (strlen(cmd)); i++)
			{
				if (cmd[i] == ' ' || cmd[i] == '\0')
				{
					cmdsplit[ctr][j] = '\0';
					ctr++;
					j = 0;
				}
				else
				{
					cmdsplit[ctr][j] = cmd[i];
					j++;
				}
			}
			int tmp = 0;
			for (int k = 0; k < ctr; k++)
			{
				if (cmdsplit[k][0] != '\0')
				{
					command = cmdsplit[k];
					tmp = k + 1;
					break;
				}
			}
			int arg = 0;
			int cduse;
			int op1;
			int op2;
			for (int l = tmp; l < ctr; l++)
			{
				if (cmdsplit[l][0] != '\0')
				{
					arg += 1;
					cduse = l;
					if (arg == 1)
					{
						op1 = cduse;
					}
					if (arg == 2)
					{
						op2 = cduse;
					}
				}
			}
			if (strcmp(command, "history") == 0)
			{
				if (arg == 1)
				{
					if (strcmp(cmdsplit[op1], "-c") == 0)
					{
						int ii = 0;
						while (hist_list[ii][0] != '\0')
						{
							hist_list[ii][0]='\0';
							ii++;
						}
					}
					else if (strcmp(cmdsplit[op1], "-w") == 0)
					{
						int ii = 0;
						while (hist_list[ii][0]!='\0')
						{
							fputs(hist_list[ii], fptr);
							fputs(" ",fptr);
							fflush(fptr);
							ii++;
						}
					}
				}
				else {
					rewind(fptr);
					char chh;
					while ((chh = getc(fptr)) != EOF) {
						printf("%c", chh);
					}
				}
			}
			else if (strcmp(command, "echo") == 0)
			{
				char finalcmd[100][100];
				int r = 0;
				for (int q = 0; q < ctr; q++)
				{
					if (cmdsplit[q][0] != '\0')
					{
						int s = 0;
						while (cmdsplit[q][s] != '\0')
						{
							finalcmd[r][s] = cmdsplit[q][s];
							s++;
						}
						finalcmd[r][s] = '\0';
						r++;
					}
				}
				int arg1 = 0;
				int arg2 = 0;
				int xx = 1;
				if (strcmp(finalcmd[1], "-n") == 0 || strcmp(finalcmd[1], "-nE") == 0 || strcmp(finalcmd[1], "-E") == 0 || strcmp(finalcmd[1], "-En") == 0)
				{
					arg1 = 1;
				}
				if (strcmp(finalcmd[2], "-E") == 0 || strcmp(finalcmd[2], "-n") == 0)
				{
					arg2 = 1;
				}
				if (arg1 == 1)
				{
					xx = 1;
				}
				if (arg2 == 1)
				{
					xx = 2;
				}
				int nnn = 0;
				int eee = 0;
				if (strcmp(finalcmd[1], "-n") == 0 || strcmp(finalcmd[2], "-n") == 0)
				{
					nnn = 1;
				}
				if (strcmp(finalcmd[1], "-E") == 0 || strcmp(finalcmd[2], "-E") == 0)
				{
					eee = 1;
				}
				if (strcmp(finalcmd[1], "-nE") == 0 || strcmp(finalcmd[1], "-En") == 0)
				{
					nnn = 1;
					eee = 1;
				}
				for (xx; xx < r; xx++)
				{
					printf("%s ", finalcmd[xx]);
				}
				if (nnn != 1)
				{
					printf("\n");
				}
			}
			else if (strcmp(command, "cd") == 0)
			{
				if (arg > 1)
				{
					if (arg == 2)
					{
						if (strcmp(cmdsplit[op1], "-L") == 0 || strcmp(cmdsplit[op1], "-P") == 0 || strcmp(cmdsplit[op1], "-LP") == 0)
						{
							if (chdir(cmdsplit[op2]) != 0)
							{
								printf("bash: cd: %s: No such file or directory\n", cmdsplit[op2]);
							}
						}
						else
						{
							printf("bash: cd: too many arguments\n");
						}
					}
					else
					{
						printf("bash: cd: too many arguments\n");
					}
				}
				else if (arg == 1)
				{
					if (chdir(cmdsplit[cduse]) != 0)
					{
						printf("bash: cd: %s: No such file or directory\n", cmdsplit[cduse]);
					}
				}
				else
				{
					printf("bash: cd: too less arguments\n");
				}
			}
			else if (strcmp(command, "pwd") == 0)
			{
				printf("%s\n", buf);
			}
			else if (strcmp(command, "exit") == 0)
			{
				int ro = 0;
				int tf = 0;
				while (isdigit(cmdsplit[op1][ro]))
				{
					ro++;
					if (cmdsplit[op1][ro] == '\0')
					{
						tf = 1;
					}
				}
				if (tf == 1)
				{
					if (arg > 1)
					{
						printf("exit\nbash: exit: too many arguments\n");
					}
					else
					{
						printf("Bye\n");
						break;
					}
				}
				else
				{
					printf("Bye\n");
					break;
				}
			}
			else if (strcmp(command, "ls") == 0 || strcmp(command, "cat") == 0 || strcmp(command, "date") == 0 || strcmp(command, "rm") == 0 || strcmp(command, "mkdir") == 0)
			{
				char path[] = "/bin/";
				strcat(path, command);
				char finalcmd[100][100];
				int r = 0;
				for (int q = 0; q < ctr; q++)
				{
					if (cmdsplit[q][0] != '\0')
					{
						int s = 0;
						while (cmdsplit[q][s] != '\0')
						{
							finalcmd[r][s] = cmdsplit[q][s];
							s++;
						}
						finalcmd[r][s] = '\0';
						r++;
					}
				}
				int pid = fork();
				if (pid == 0)
				{
					if (r == 1)
					{
						execl(path, finalcmd[0], NULL);
					}
					else if (r == 2)
					{
						execl(path, finalcmd[0], finalcmd[1], NULL);
					}
					else if (r == 3)
					{
						execl(path, finalcmd[0], finalcmd[1], finalcmd[2], NULL);
					}
					else if (r == 4)
					{
						execl(path, finalcmd[0], finalcmd[1], finalcmd[2], finalcmd[3], NULL);
					}
					else if (r == 5)
					{
						execl(path, finalcmd[0], finalcmd[1], finalcmd[2], finalcmd[3], finalcmd[4], NULL);
					}
					else if (r == 6)
					{
						execl(path, finalcmd[0], finalcmd[1], finalcmd[2], finalcmd[3], finalcmd[4], finalcmd[5], NULL);
					}
					else
					{
						printf("Too many arguments for this small shell\n");
						exit(1);
					}
				}
				else
				{
					wait(0);
				}
			}
			else
			{
				printf("Learn Unix Commands\n");
			}
		}
	}
fclose(fptr);
}
