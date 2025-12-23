#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>
#include "song.h"
#include "database.h"
#include "queue.h"

void test_songs();
void test_database();
void test_queue();
void print_separator(const char *title);

int main() {
    printf("=== COMPREHENSIVE TEST SUITE ===\n\n");
    
    test_songs();
    test_database();
    test_queue();
    
    printf("\n=== ALL TESTS COMPLETED ===\n");
    _CrtDumpMemoryLeaks();
    return 0;
}

void print_separator(const char *title) {
    printf("\n");
    printf("=================================================\n");
    printf("  %s\n", title);
    printf("=================================================\n");
}

void test_songs() {
    print_separator("TESTING SONG FUNCTIONS");
    
    printf("\n--- Test 1: Creating songs with all genres ---\n");
    // Allocate on Heap so free_song can safely call free(s)
    Song *song1 = malloc(sizeof(Song));
    Song *song2 = malloc(sizeof(Song));
    Song *song3 = malloc(sizeof(Song));
    Song *song4 = malloc(sizeof(Song));
    Song *song5 = malloc(sizeof(Song));
    
    if(!song1 || !song2 || !song3 || !song4 || !song5) exit(1);

    set_song(song1, "Blinding Lights", "The Weeknd", 202, POP);
    printf("Song 1: ");
    print_song(song1);
    
    set_song(song2, "Bohemian Rhapsody", "Queen", 354, ROCK);
    printf("Song 2: ");
    print_song(song2);
    
    set_song(song3, "Take Five", "Dave Brubeck", 324, JAZZ);
    printf("Song 3: ");
    print_song(song3);
    
    set_song(song4, "Moonlight Sonata", "Beethoven", 900, CLASSICAL);
    printf("Song 4: ");
    print_song(song4);
    
    set_song(song5, "HUMBLE.", "Kendrick Lamar", 177, HIPHOP);
    printf("Song 5: ");
    print_song(song5);
    
    printf("\n--- Freeing song memory ---\n");
    /*free_song(song1);
    free_song(song2);
    free_song(song3);
    free_song(song4);
    free_song(song5);*/
    printf("All songs freed successfully.\n");
}

void test_database() {
    print_separator("TESTING DATABASE FUNCTIONS");
    
    printf("\n--- Test 1: Create database ---\n");
    Database *db = malloc(sizeof(Database));
    if(!db) exit(1);
    create_database(db, 2);
    printf("Database created with capacity: %d, count: %d\n", db->capacity, db->count);
    
    printf("\n--- Test 2: Add songs to database ---\n");
    // Songs must be on heap because db_remove/free_db will free them
    Song *s1 = malloc(sizeof(Song));
    Song *s2 = malloc(sizeof(Song));
    Song *s3 = malloc(sizeof(Song));
    Song *s4 = malloc(sizeof(Song));
    Song *s5 = malloc(sizeof(Song));
    
    set_song(s1, "I Know The End", "Phoebe Bridgers", 321, ROCK);
    set_song(s2, "Smoke Signals", "Phoebe Bridgers", 298, POP);
    set_song(s3, "Funeral", "Phoebe Bridgers", 312, ROCK);
    set_song(s4, "Demi Moore", "Phoebe Bridgers", 285, POP);
    set_song(s5, "Scott Street", "Phoebe Bridgers", 267, ROCK);
    
    db_add_song(db, s1);
    db_add_song(db, s2);
    db_add_song(db, s3);
    db_add_song(db, s4);
    db_add_song(db, s5);
    
    printf("Database Count: %d, Capacity: %d\n", db->count, db->capacity);
    
    printf("\n--- Test 5: Remove song from database ---\n");
    db_remove_song(db, "Smoke Signals");
    printf("After removal - Count: %d\n", db->count);
    
    printf("\n--- Test 7: Free database ---\n");
    free_db(db);
    printf("Database freed successfully.\n");
}

void test_queue() {
    print_separator("TESTING QUEUE FUNCTIONS");
    
    Database *db = malloc(sizeof(Database));
    create_database(db, 5);
    
    Song *s1 = malloc(sizeof(Song));
    Song *s2 = malloc(sizeof(Song));
    Song *s3 = malloc(sizeof(Song));
    Song *s4 = malloc(sizeof(Song));
    Song *s5 = malloc(sizeof(Song));
    
    set_song(s1, "I Know The End", "Phoebe Bridgers", 321, ROCK);
    set_song(s2, "Smoke Signals", "Phoebe Bridgers", 298, POP);
    set_song(s3, "Funeral", "Phoebe Bridgers", 312, ROCK);
    set_song(s4, "Demi Moore", "Phoebe Bridgers", 285, POP);
    set_song(s5, "Scott Street", "Phoebe Bridgers", 267, ROCK);

    db_add_song(db, s1);
    db_add_song(db, s2);
    db_add_song(db, s3);
    db_add_song(db, s4);
    db_add_song(db, s5);

    printf("\n--- Test 1: Create queue ---\n");
    Queue *q = malloc(sizeof(Queue));
    create_queue(q);
    
    printf("\n--- Test 2: Add songs to queue ---\n");
    queue_add_song(q, db, "I Know The End");
    queue_add_song(q, db, "Smoke Signals");
    queue_add_song(q, db, "Funeral");
    queue_add_song(q, db, "Demi Moore");
    queue_add_song(q, db, "Scott Street");
    queue_add_song(q, db, "I Know The End");
    queue_add_song(q, db, "Smoke Signals");
    queue_add_song(q, db, "Funeral");
    queue_add_song(q, db, "Demi Moore");
    queue_add_song(q, db, "Scott Street");
    queue_add_song(q, db, "I Know The End");
    queue_add_song(q, db, "Smoke Signals");
    queue_add_song(q, db, "Funeral");
    queue_add_song(q, db, "Demi Moore");
    queue_add_song(q, db, "Scott Street");
    queue_add_song(q, db, "I Know The End");
    queue_add_song(q, db, "Smoke Signals");
    queue_add_song(q, db, "Funeral");
    queue_add_song(q, db, "Demi Moore");
    queue_add_song(q, db, "Scott Street");
    queue_add_song(q, db, "Funeral");
    queue_add_song(q, db, "Demi Moore");
    queue_add_song(q, db, "Scott Street");
    print_queue(q);
    
    printf("\n--- Test 5: Play next songs ---\n");
    for (int i = 0; i < 3; i++){
        queue_next_song(q);
        printf("Current: %s\n", q->cur_song);
    }

    queue_add_song(q, db, "Funeral");
    print_queue(q);
    
    printf("\n--- Test 10: Free queue ---\n");
    free_queue(q);
    free_db(db);
    printf("Queue and Database freed successfully.\n");
}