#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

#define BROJ_MOLEKULA 20

sem_t mutex;
sem_t semKiseonik;
sem_t semVodonik;

int kiseonik=0,vodonik=0;

int trenutnoSpremni = 0;

int funkcijaVeze() {

    trenutnoSpremni++;
    if(trenutnoSpremni % 3 == 0) {
        printf("Kreiran je novi molekul!\n\n");
        trenutnoSpremni = 0;
    }
    sleep(2);
    return 0;

}

void* funkcijaKiseonika() {

        int sekundiCekanja = rand() % 5;
        sleep(sekundiCekanja);

        sem_wait(&mutex);
        kiseonik+=1;

        if(vodonik>=2) {
            sem_post(&semVodonik);
            sem_post(&semVodonik);
            vodonik-=2;
            sem_post(&semKiseonik);
            kiseonik-=1;
        }
        else {
            sem_post(&mutex);
        }
        
        sem_wait(&semKiseonik);
        printf("Kiseonik je stigao u molekulnu vezu!\n");

        funkcijaVeze();
        sem_post(&mutex);

}

void* funkcijaVodonika() {

        int sekundiCekanja = rand() % 5;
        sleep(sekundiCekanja);

        sem_wait(&mutex);
        vodonik+=1;

        if(vodonik>=2 && kiseonik>=1) {
            sem_post(&semVodonik);
            sem_post(&semVodonik);
            vodonik-=2;
            sem_post(&semKiseonik);
            kiseonik-=1;
        }
        else {
            sem_post(&mutex);
        }

        sem_wait(&semVodonik);
        printf("Vodonik je stigao u molekulnu vezu!\n");
        funkcijaVeze();

}

main() {

    printf("Start\n");
    
    sem_init(&mutex,0,1);
    sem_init(&semKiseonik,0,0);
    sem_init(&semVodonik,0,0);
    
    pthread_t kiseonici[BROJ_MOLEKULA];
    for (int i=0; i<BROJ_MOLEKULA; i++) pthread_create(&kiseonici[i], NULL, funkcijaKiseonika, NULL);
    
    pthread_t vodonici[2*BROJ_MOLEKULA];
    for (int i=0; i<2*BROJ_MOLEKULA; i++) pthread_create(&vodonici[i], NULL, funkcijaVodonika, NULL);

 
    for(int i = 0; i < BROJ_MOLEKULA; i++) pthread_join(kiseonici[i], NULL);
    for(int i = 0; i < 2*BROJ_MOLEKULA; i++) pthread_join(vodonici[i], NULL);

    printf("\n\nUkupno je kreirano %d molekula",BROJ_MOLEKULA);

}