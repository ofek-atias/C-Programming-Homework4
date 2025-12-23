#include "song.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO : verify if you need to free the input pointers title and artist or not.
void set_song(Song *s, const char *title, const char *artist, /*We may have to allocate memory dynamically to the struct song, waiting for an answer*/
              int duration, Genre genre) {
    
    if (s == NULL)
    {
        printf("ERROR: NULL Song pointer.\n");
        exit(1);
    }

    if (title == NULL)
    {
        printf("ERROR: NULL title pointer.\n");
        exit(1);
    }

    if (artist == NULL)
    {    
        printf("ERROR: NULL artist pointer.\n");
        exit(1);
    }

    (s->title) = (char*) malloc(strlen(title)+1);

    if (s->title == NULL)
    {
        printf("ERROR: Failed to allocate memory for title.\n");
        exit(1);
    }

    (s->artist) = (char*) malloc(strlen(artist)+1);
    
    if (s-> artist == NULL)
    {
        printf("ERROR: Failed to allocate memory for artist.\n");
        exit(1);
    }

    strcpy(s->title, title);
    strcpy(s->artist, artist);

    s->duration_in_seconds = duration;
    s->genre = genre;
}


void print_song(const Song *s) 
{
    char *genre_str;

    if (s == NULL)
    {
        printf("ERROR: NULL Song pointer.\n");
        exit(1);
    }
    if ((s->title == NULL) || (s->artist == NULL))
    {
        printf("ERROR: Song has NULL fields.\n");
        exit(1);
    }

    switch(s->genre){
        case POP:
            genre_str = "POP";
            break;
        case ROCK:
            genre_str = "ROCK";
            break;
        case JAZZ:
            genre_str = "JAZZ";
            break;
        case CLASSICAL:
            genre_str = "CLASSICAL";
            break;
        case HIPHOP:
            genre_str = "HIPHOP";
            break;
    }
    

    printf("Title: %s, Artist: %s, Duration: %ds, Genre: %s\n", s->title, s->artist, s->duration_in_seconds, genre_str);
}

void free_song(Song *s) 
{
    if (s == NULL)
    {
        printf("ERROR: NULL Song pointer.\n");
        exit(1);
    }
    if (s->title != NULL) {
        free(s->title);
        s->title = NULL;
    }
    if (s->artist != NULL) {
        free(s->artist);
        s->artist = NULL;
    }
    free(s);
    s = NULL;
}

/*int main(){
    
    Song *song = (Song*)malloc(sizeof(Song));

    const char *art = "Noam";
    const char *name = "Luck";

    set_song(song, art, name, 120, POP);
    print_song(song);


    return 0;
}*/
