#include "serv_cli_fifo.h"
#include "Handlers_Serv.h"

void main() {
 /*Declarations*/
   int fd1, fd2, i;
   struct question q;
   struct reponse r;
/*Declarations des tubes nommés*/
    fd1=mkfifo(FIFO1, 0666);
    fd2=mkfifo(FIFO2, 0666);
/*initialisation du générateur de nombres aléatoires*/
    srand(getpid());
/* Ouverture des tubes nommés */
    fd1 = open(FIFO1, O_RDONLY);
    fd2 = open(FIFO2, O_WRONLY);

    if (fd1 == -1 || fd2 == -1) {
        perror("Erreur ouverture des tubes");
        exit(1);
    }
/* Installation des Handlers */
    signal(SIGUSR1, hand_reveil);
    signal(SIGINT, fin_serveur);
    while(1) {
        /* lecture d’une question */
        
        /* Lecture d'une question */
        if (read(fd1, &q, sizeof(struct question)) != sizeof(struct question))
            continue;
        /* construction de la réponse */
        if (q.n > NMAX) q.n = NMAX;
        r.id = q.id;
        r.pid_serveur = getpid();
        for(i=0; i<q.n; i++){
            r.entiers[i]=1+rand()%NMAX;
        }

        /* envoi de la réponse */
        write(fd2, &r, sizeof(struct reponse));

        /* envoi du signal SIGUSR1 au client concerné */
        kill(q.id, SIGUSR1);
    }
    

}