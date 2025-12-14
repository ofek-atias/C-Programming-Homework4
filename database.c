#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"

void create_database(Database *db, int initial_capacity) 
{   
    if (db == NULL)
    {
        printf("ERROR: NULL Database pointer.\n");
        exit(1);
    }

    db->songs = (Song**) calloc(initial_capacity, sizeof(Song*));
    
    if (db->songs == NULL)
    {
        printf("ERROR: Failed to allocate songs array.\n");
        exit(1);
    }

    db->capacity = initial_capacity;
    db->count = 0;
    
    
}


void db_add_song(Database *db, Song *s)
{
    if(db == NULL)
    {
        printf("ERROR: NULL Database pointer.\n");
        exit(1);
    }
    if(s == NULL)
    {
        printf("ERROR: NULL Song pointer.\n");
        exit(1);
    }
    if(db->capacity == db->count)
    {
        Song **temp_songs = (Song**) realloc(db->songs,db->capacity*2*sizeof(Song*));
            
        if(temp_songs == NULL)
        {
            printf("ERROR: Failed to expand database.\n");
            exit(1);
        }
        db->songs = temp_songs;
        db->capacity *=2;
        
    }

   
    db->songs[db->count] = s; 
    db->count +=1;
}

void db_remove_song(Database *db, const char *title) 
{
    int i = 0;
    if(db == NULL)
    {
        printf("ERROR: NULL Database pointer.\n");
        exit(1);
    }

    if(title == NULL)
    {
        printf("ERROR: NULL title.\n");
        exit(1);
    }

    while(db->songs[i]->title != NULL)
    {
        i++;
        if(i == sizeof(db->songs))
        {
            printf("ERROR: Song not found in database.\n");
            exit(1);
        }
        
    }
    
    free(db->songs[i]);
    db->count -= 1;

}

void free_db(Database *db) 
{

        printf("ERROR: NULL Database pointer.\n");

}



int main()
{ 
    return 0;
}

    /*
    Database *db = (Database*)malloc(sizeof(Database));
    Song *song = (Song*)malloc(sizeof(Song));
    Song *song2 = (Song*)malloc(sizeof(Song));
    Song *song3 = (Song*)malloc(sizeof(Song));

    int our_capacity = 2;
    create_database(db, our_capacity);
    db_add_song(db,song);
    db_add_song(db,song2);
    db_add_song(db,song3);




    return 0;
}
    */