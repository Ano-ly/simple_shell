#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include "main.h"

/**
 * is_path_is_exist - checks if command is a path to a file or a
 * normal command that has to be searched for in the directories
 * specified by PATH.
 * @comm: command inserted at terminal/command line
 * Description - Checks if argument is a path, or normal shell
 * command. If it is a path, it checks for the existence of the file
 * in question.
 * Return: 0 if it is a normal command, 1 if it is a path, and -1
 * if it is a path and file does not exist
*/

int is_path_is_exist(char *comm)
{
	int exists;
	int i;
	int is_path;
	struct stat _status;

	i = 0;
	is_path = 0;

	while (comm[i] != '\0')
	{
		if (comm[i] == '/')
		{
			is_path = 1;
			break;
		}
		i++;
	}
	if (is_path == 1)
	{
		exists = stat(comm, &_status);
		if (exists == 0)
			return (1);
		else
			return (-1);
	}
	return (0);
}

/**
 * find_command - find a command in PATH
 * @command: non_path command passed to the computer
 * by user.
 *
 * Definition - finds a command by searching directory paths listed in the
 * PATH environment variable. calls function find_file_in_dir, that does the
 * actual searching for each directory passed to it.
 * Return: 1, if command found, 0, if not found, -1 if error
 * occured.
*/

struct find_info find_command(char *command)
{
	char *path = getenv("PATH");
	int path_length = _strlen(path);
	char *path2 = malloc(path_length + 1);

	int found_state;
	char *dir;
	char *_dir;
	find_info fi;

	fi.find_status = 0;
	fi.dir_loc = NULL;

	if (path2 == NULL)
	{
		fi.find_status = -1;
		return (fi);
	}
	_memcpy(path2, path, path_length);
	path2[path_length] = '\0';
	dir = strtok(path2, ":");
	if (dir == NULL)
		dir = path2;
	while (dir != NULL)
	{
		found_state = find_file_in_dir(dir, command);
		if (found_state == 1)
		{
			printf("Sizze of dir: %ld", sizeof(dir));
			_dir = malloc(sizeof(dir) + 1);
			if (_dir == NULL)
				return (fi);
			_memcpy(_dir, dir, _strlen(dir));
			_dir[_strlen(dir)] = '\0';
			fi.find_status = 1;
			fi.dir_loc = _dir;
			free(path2);
			return (fi);
		}
		dir = strtok(NULL, ":");
	}
	free(path2);
	return (fi);
}

/**
 * find_file_in_dir - looks for a particular file in a particular directory
 * @dir: directory path
 * @file_name: name of file to be searched for
 * Definition - searches for regular file in a directory and prints
 * message to output
 * Return: 1 if found, 0 if not
*/

int find_file_in_dir(char *dir, char *file_name)
{
	DIR *dirp;
	struct dirent *file;

	printf("File name: %s\n", file_name);

	dirp = opendir(dir);
	if (dirp == NULL)
		perror("Could not access directory");
	file = readdir(dirp);
	while (file != NULL)
	{
		if (_strcmp(file->d_name, file_name) == 0)
		{
			printf("   File: %s\n", file->d_name);
			printf("File found!\n\n");
			return (1);
		}
		file = readdir(dirp);
	}
	closedir(dirp);
	return (0);
}

/**
 * _strcmp - compares two strings
 * @s1: first string to be compared
 * @s2: second string to be compared
 *
 * Description - compares two strings using ascii values
 * Return: 0 is similar, positive integer if s1 is greater than s2
 * negative integer if otherwise
*/

int _strcmp(char *s1, char *s2)
{
	int i;
	int s1l;
	int schoose;
	int s2l;

	if (s1 == NULL || s2 == NULL)
		return (-1);

	s1l = _strlen(s1);
	s2l = _strlen(s2);

	if (s1l > s2l)
	{
		schoose = s2l;
	}
	else
	{
		schoose = s1l;
	}

	for (i = 0; i < schoose; i++)
	{
		if (s1[i] - s2[i])
			break;
	}
	return (s1[i] - s2[i]);
}
