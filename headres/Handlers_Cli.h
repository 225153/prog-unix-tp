#ifndef HANDLERS_CLI_H
#define HANDLERS_CLI_H

#include "serv_cli_fifo.h"

void hand_reveil(int sig){
    printf("Réveil du client par le signal %d\n", sig);
}

#endif