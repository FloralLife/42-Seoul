#!/bin/bash

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$1 get_next_line_bonus.c get_next_line_utils_bonus.c main.c
