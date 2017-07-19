# Simple Shell

![Simple Shell](https://github.com/srinitude/simple_shell/blob/master/hsh.png)

## Welcome
Thanks for happening upon our project, Simple Shell! Simple Shell was inspired by Ken Thompson and the initial UNIX Shell. Felicia and I started development with the goal of creating a very basic shell that has similar functionality to the Thompson and bash shells, but we're each planning on forking this current project and developing our own individual sets of additional, domain-specific functionality that you will not be able to find on many of the shells that are currently out there in the ether. However, before forking to work on our own separate projects, we'll be adding more features and bug fixes to the current repo in order to realize to a "Minimum Viable Shell" (MVS).

For those interested in what happens when a typical shell executes a command typed by the user in the terminal, check out this [blog post](https://medium.com/@feliciaSWE/linux-command-ls-c-930cf1d7d8a6).

## Table of Contents
* [Requirements](#requirements)
* [Installation](#installation)
* [Usage](#usage)
* [Commands](#commands)
* [Roadmap](#roadmap)
* [Testing](#testing)
* [Credits](#credits)
* [License](#license)

## Requirements
* Ubuntu 14.04 LTS
* gcc 4.8.4 (-Wall, -Werror, -Wextra, and -pedantic flags)

## Installation
```sh
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

## Usage
Commands are currently executed just like they are in sh, bash, and other common shells.

To start Simple Shell in interactive mode, run the command below:
```sh
./hsh
```

To start Simple Shell in non-interactive mode, `echo` the command or `cat` the pseudo-random file you want to run and pipe the standard output into Simple Shell:
```sh
echo "ls -l" | ./hsh
```

## Commands
* Builtins
  - [x] exit
  - [x] env
  - [x] pwd
  - [ ] cd
  - [ ] setenv
  - [ ] unsetenv
  - [ ] help
  - [ ] history

* PATH
  - [x] chmod
  - [x] ls
  - [x] echo

## Roadmap

## Testing

## Credits
Simple Shell is owned and maintained by Kiren Srinivasan ([@srinitude](https://twitter.com/srinitude)) and Felicia Hsieh ([@feliciahsiehsw](https://twitter.com/feliciahsiehsw)). You can reply to us and to [@holbertonschool](https://twitter.com/holbertonschool) on Twitter for more updates on this project and our forked projects.

## License
