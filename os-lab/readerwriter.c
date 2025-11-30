#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t wrt;            
pthread_mutex_t mutex; 
int readcount = 0;     
int data = 0;         

void* reader(void* arg) {
    int id = *((int*)arg);

    pthread_mutex_lock(&mutex);
    readcount++;
    if (readcount == 1)
        sem_wait(&wrt);   
    pthread_mutex_unlock(&mutex);

    printf("Reader %d is reading data = %d\n", id, data);
    sleep(1);

    pthread_mutex_lock(&mutex);
    readcount--;
    if (readcount == 0)
        sem_post(&wrt);   
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void* writer(void* arg) {
    int id = *((int*)arg);

    sem_wait(&wrt);       
    data++;
    printf("Writer %d is writing data = %d\n", id, data);
    sleep(1);
    sem_post(&wrt);       

    return NULL;
}

int main() {
    pthread_t r[3], w[2];
    int r_id[3] = {1, 2, 3};
    int w_id[2] = {1, 2};

    sem_init(&wrt, 0, 1);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&r[0], NULL, reader, &r_id[0]);
    pthread_create(&w[0], NULL, writer, &w_id[0]);
    pthread_create(&r[1], NULL, reader, &r_id[1]);
    pthread_create(&r[2], NULL, reader, &r_id[2]);
    pthread_create(&w[1], NULL, writer, &w_id[1]);

    pthread_join(r[0], NULL);
    pthread_join(w[0], NULL);
    pthread_join(r[1], NULL);
    pthread_join(r[2], NULL);
    pthread_join(w[1], NULL);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}

