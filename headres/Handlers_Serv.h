#ifndef HANDLERS_SERV_H
#define HANDLERS_SERV_H
#include "serv_cli_fifo.h"



void hand_reveil(int sig){
    printf("Signal %d recu\n", sig);
}

void fin_serveur(int sig){
    printf("Signal %d recu : arret du serveur\n", sig);
    unlink(FIFO1);
    unlink(FIFO2);
    exit(0);
}

#endif