# Simple_shell

## Description

This project implements some functionalities of a simple C shell (UNIX command interpreter) using the C programming language.
The program can run in interactive and non-interactive mode.

This shell uses only the following commands. Other, more common functions, such as string functions, have been customized or rewritten.

||Functions Used||
|----|----|----|
|access|chdir|close|
|closedir|execve|exit|
|fork|free|fstat|
|getcwd|getline|kill|
|lstat|malloc|open|
|opendir|perror|read|
|readdir|signal|stat|
|strtok|wait|waitpid|
|wait3|wait4|write|
|_exit|

The *README* file, *man page*, man_1_simple_shell, and the *AUTHORS* page are also available.

## Table of Contents

1. Simple shell 0.1

A prompt is displayed and waits for the user to type a command. A command is entered when the user enters a new line. The simple shell will not handle semi-columns, pipes, redirections, or any other advanced features.
The commands comprise of one word. No arguments will be passed to the program.
If an executable cannot be found, an error message will print, and the prompt is ready for the next commands.
Errors will be handled simply. The shell will handle the "end of file" condition (Ctrl+D) and exit() with code = 0.

        $ ./hsh

3. Simple shell 0.1.1 - Alternative getline function
Uses a buffer to read many chars at once and call the least possible the read system call. It uses static variables.

4. Simple shell 0.2 - Handle command lines with arguments
        $ [COMMAND] [ARG1] [ARG2] ...

5. Simple shell 0.2.1 - Implement strtok()

    The program will implement its own version of strtok().

6. Simple shell 0.3 - Handle the PATH environment variable

    The program will handle the $PATH environment variable.

7. Simple shell 0.4 - exit()
Implements the exit built-in, that exits the shell

        $ exit

Argument to the built-in exit will not be handled

8. Simple shell 0.4.1 - exit
Handle arguments for the built-in exit, where [STATUS] is an integer used to exit the shell.

       $ exit [STATUS]

9. Simple shell 0.4.2 - When a user enters Ctrl+c, the shell will not quit.

        [Ctrl+c]

10. Simple shell 1.0 - Implements the env built-in, that prints the current environment.

        $ env

11. setenv, unsetenv - Implements the setenv and unsetenv built-in commands:

        $ setenv VARIABLE_VALUE

where VARIABLE_VALUE is a new environment variable or modify an existing one.

        $ unsetenv VARIABLE

where VARIABLE is an environment variable.

12. cd - Implements the builtin command cd that changes the current directory of the process. If no argument is given to cd the command must be interpreted like cd $HOME. It will handle the command,

        cd -

The environment variable PWD will have to be updated when directory is changed again.

        $ cd [DIRECTORY]

13. Command separator - handle the command separator (semi-colon), where [COMMAND] is a bash or Linux command.

        $ [COMMAND] ; [COMMAND]

14. && and || - handle && and || shell logical operators, where [COMMAND] is a bash or Linux command.

        $ [COMMAND] && [COMMAND]

        $ [COMMAND] || [COMMAND]

15. alias - handle aliases. Output the alias and insert a new alias into the .bashrc file.

        $ alias

16. Variables
The shell will handle variables replacement, the $? variable, and $$ variable.

        $ echo $?
        $ echo $$

17. Comments - handles comments on the command line

         $ [COMMAND] # ignore this

18. help - implements the help buit-in

        $ help [COMMAND]

19. history - implements the history built-in, without any argument. The history built-in displays the history list, one command by line, preceded with line numbers (starting at 0). On exit, the entire history, without line numbers, will be written to a file named .simple_shell_history in the directory $HOME.
When the shell starts, read the file .simple_shell_history in the directory $HOME if it exists, and set the first line number to the total number of lines in the file modulo 4096

        $ history

20. File as input
The shell can take a file as a command line argument. It contains all of the commands that your shell should run before exiting
The file contains one command per line. In this mode, the shell should not print a prompt and should not read from stdin.

        $ simple_shell [FILENAME]

## Blog
For a more practical treatise on the behavior of what happens when a command is typed in a Linux shell, please read, "What happens when you type *ls -l* in the shell".
        [Link to Blogs]

## Test suite
The test suite is a community effort and tests the tasks from above. Contributors are listed in the AUTHORS file as well.
Also see https://github.com/srinitude/shellgame

## Installation
To install this project, type in your terminal, git clone the repository with

        git clone https://github.com/srinitude/simple_shell

The Betty style coding convention was used and the source file is in the Github repository at https://github.com/holbertonschool/Betty.

## Usage
Files were compiled on Ubuntu 14.04 LTS, using gcc 4.8.4. This code was compiled in a shell script with the following flags:

        $ gcc -Wall -Werror -Wextra -pedantic *. -o hsh

The files follow the Betty style coding convention.

## Contributors

Authors also are listed in the "AUTHORS" file. Please contact the authors for getting collaboration access to the Github repository.

## Credits

Felicia Hsieh and Kiren Srinivasan. The project is titled, "0x15. C - Simple Shell" and was created between July 6, 2017 to July 14, 2017. You may contact felicia@tixwr
iteoff.com and srinitude@gmail.com.

## License
GNU public license

--------

  [contributor]: http://x.net/
  [1]: http://markdowntutoriallink
  [source code]: githublink
