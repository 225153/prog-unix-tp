#ifndef SERV_CLI_FIFO_H
#define SERV_CLI_FIFO_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdlib.h>

#define NMAX 270
#define FIFO1 "fifo1"
#define FIFO2 "fifo2"


struct question{
    int id;
    int n;
};

struct reponse{
    int id;
    int pid_serveur;
    int entiers[NMAX];
};

#endif
