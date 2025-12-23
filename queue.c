#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void create_queue(Queue *q)
{
    if (q == NULL)
    {
        printf("ERROR: NULL Queue pointer.\n");
        exit(1);
    }
    
    q->prev_song = NULL;
    q->cur_song = NULL;
    q->queue_songs = (char**) calloc(MAX_Q_SIZE, sizeof(char*));

    if (q->queue_songs == NULL)
    {
        printf("ERROR: Failed to allocate songs array.\n");
        exit(1);
    }

    q->capacity = MAX_Q_SIZE;
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

void queue_add_song(Queue *q, Database *db, const char *title) {
    
    int i = 0;
    int found_s_index = -1;
    
    if (q == NULL)
    {
        printf("ERROR: NULL queue pointer.\n");
        exit(1);
    }
    
    if (db == NULL)
    {
        printf("ERROR: NULL database pointer.\n");
        exit(1);
    }

    if (title == NULL)
    {
        printf("ERROR: NULL title.\n");
        exit(1);
    }
    
    for (i = 0; i < db->count; i++)
    {
        if (strcmp(db->songs[i]->title, title) == 0)
        {
            found_s_index = i;
            break;
        }     
    }    

    if (found_s_index == -1)
    {
        printf("ERROR: Song was not found in database.\n");
        return;
    }
    
    if (q->size == MAX_Q_SIZE)
    {
        printf("ERROR: Queue is full.\n");
        return;
    }

    q->queue_songs[q->rear] = strdup(title);

    if (q->queue_songs[q->rear] == NULL)
        exit(1);
    
    q->rear = ((q->rear+1) % MAX_Q_SIZE);
    q->size +=1;
}



void queue_next_song(Queue *q) {
    if (q == NULL)
    {
        printf("ERROR: NULL queue pointer.\n");
        exit(1);
    }

    if (q->size == 0)
    {
        printf("ERROR: Queue is empty.\n");
        return;
    }
     
    if (q->prev_song != NULL)
    {
        free(q->prev_song); 
        q->prev_song = NULL;
    }

    q->prev_song = q->cur_song;

    q->cur_song = q->queue_songs[q->front];
    q->queue_songs[q->front] = NULL;

    q->front = (q->front + 1) % MAX_Q_SIZE;
    q->size -= 1;
    
}


void print_queue(const Queue *q) {
    if (q == NULL)
    {
        printf("ERROR: NULL queue pointer.\n");
        exit(1);
    }
    
    if(q->size == 0)
    {
        printf("Queue is empty.\n");
        return;
    }
    
    printf("Queue contents:\n");

    for (int i = 0; i < q->size; i++)
    {
        printf("%d. %s\n", i+1, q->queue_songs[(q->front+i) % MAX_Q_SIZE]);
    }
}

void free_queue(Queue *q) {
    if (q == NULL)
    {
        printf("ERROR: NULL queue pointer.\n");
        exit(1);
    }

    for (int i = 0; i < MAX_Q_SIZE; i++)
    {
        if (q->queue_songs[i] != NULL) {
            free(q->queue_songs[i]);
            q->queue_songs[i] = NULL;
        }
    }
    free(q->queue_songs);
    q->queue_songs = NULL;

    if (q->prev_song != NULL) {
        free(q->prev_song);
        q->prev_song = NULL;
    }

    if (q->cur_song != NULL) {
        free(q->cur_song);
        q->cur_song = NULL;
    }
    
    free(q);
    q = NULL;
}
