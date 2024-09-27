# HSH

A Linux based shell command interpreter based on SH

## Description

HSH follows up where simpleshell left off, adding redirection, piping, and logical operator functionality, as well as expanding the number of builtins. 

## Environment

HSH was designed in and to be run on POSIX compliant distros (specifically Ubuntu 22.04)

## How to Install and Run

1. Clone the repository `git clone https://github.com/LRWyatt801/atlas-shell_v2`
2. In your terminal, run `./hsh`

## Builtins

| Builtin    | Description                           |
| ---------- | ---------                             |
| `cd`       | Changes directory                     |
| `pwd`      | Prints current directory              |
| `env`      | Prints out the environment            |
| `exit`     | Exits the program                     |
| `setenv`   | Sets an environment variable          |
| `unsetenv` | Removes an environemnt variable       |

## Features

-`>`    Redirects output of `command` to `file`           `command > file`
-`>>`   Appends output of `command` to `file`             `command >> file`
-`<`    Redirects contents of `file`to input of `command` `command < file`
-`<<`   Heredoc
-`|`    Pipes output of `command` to input of `command`   `command | command`
-`;`    tbd
-`&&`   tbd
-`||`   tbd

## Dataflow
