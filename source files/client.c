#include "serv_cli_fifo.h"
#include "Handlers_Cli.h"

void main(){
    /* Déclarations */
    int fd1, fd2;
    struct question q;
    struct reponse r;

    /*ouverture des tubes nommés */
    fd1 = open(FIFO1, O_WRONLY);
    fd2 = open(FIFO2, O_RDONLY);

    if (fd1 == -1 || fd2 == -1) {
        perror("Erreur ouverture des tubes");
        exit(1);
    }
    /* Installation des Handlers */
    signal(SIGUSR1, hand_reveil);
    /* Construction et envoi d’une question */
    q.id = getpid();
    q.n = 5; 
    write(fd1, &q, sizeof(struct question));
    /* Attente de la réponse */
    pause();
    /* Lecture de la réponse */
    read(fd2, &r, sizeof(struct reponse));
    /* Envoi du signal SIGUSR1 au serveur */
    kill(r.pid_serveur, SIGUSR1);
    
    /* Traitement local de la réponse */
    printf("Réponse du serveur %d :\n", r.pid_serveur);
    for(int i = 0; i < q.n; i++){
        printf("%d ", r.entiers[i]);
    }
    printf("\n");

    


}