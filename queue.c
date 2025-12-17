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
    
    if(db == NULL)
    {
        printf("ERROR: NULL database pointer.\n");
        exit(1);
    }

    if(title == NULL)
    {
        printf("ERROR: NULL title.\n");
        exit(1);
    }
    
    for(i = 0; i < db->count; i++)
    {
        if(strcmp(db->songs[i]->title,title) == 0)
        {
            found_s_index = i;
            break;
        }     
    }    

    if(found_s_index == -1)
    {
        printf("ERROR: Song was not found in database.\n");
        return;
    }
    
    if (q->size == q->capacity)// maybe should  before the song not found error
    {
        printf("ERROR: Queue is full.\n");
        return;
    }

    q->queue_songs[q->rear] = strdup(title) ;

    if ( q->queue_songs[q->rear] == NULL)// waiting for instructions from benji from the forum.
    {
        printf("ERROR: Failed to allocate memory for song title.\n");
        exit(1); 
    }

    
    q->rear = ((q->rear+1)%MAX_Q_SIZE);
    q->size +=1;
    
}



void queue_next_song(Queue *q) { //validate this function


    if(q == NULL)
    {
        printf("ERROR: NULL queue pointer.\n");
        exit(1);
    }

    if(q->size == 0)
    {
        printf("ERROR: Queue is empty.\n");
        return;
    }
     
    if(q->prev_song != NULL)
    {
        free(q->prev_song); 

    }

    q->prev_song = q->cur_song;

    q->cur_song = q->queue_songs[q->front];
    q->queue_songs[q->front] = NULL;

    q->front = (q->front + 1) % MAX_Q_SIZE;
    q->size -= 1;  
    
}


void print_queue(const Queue *q) {
    printf("ERROR: NULL queue pointer.\n");

    printf("Queue is empty.\n");

    printf("Queue contents:\n");
}

void free_queue(Queue *q) {
    printf("ERROR: NULL queue pointer.\n");
}
