// include/data_structures.h
#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Bize size_t gibi tipleri sağlar.
#include <stddef.h> 

typedef struct BookNode 
{
    int id;
    char title[100];
    char author[100];
    int is_reserved;
    // ... diğer kitap bilgileri ...
    struct BookNode *next;
} BookNode;

//Koltuk rezervasyonu için ayarlamalar.
typedef struct Seat 
{
    int seat_number;
    int is_reserved;
    int reserved_by_student_id;
} Seat;


// Ana Kütüphane Yapısı (Bağlı listenin başını ve sonunu tutar)
typedef struct {
    BookNode *book_list_head; // Listenin başı
    BookNode *book_list_tail; // Listenin sonu
    
    Seat seats[80]; // Koltuklar için DİZİ
    int total_students;
    // ... diğer genel kütüphane bilgileri ...
} Library;


// Kütüphane başlatma
void initializeLibrary(Library *lib);
// void cleanupLibrary(Library *lib); // (Tavsiye)



// book_management.c'den gelenler
void initializeBookList(Library *lib);
void addBook(Library *lib, int id, const char* title, const char* author);



#endif // DATA_STRUCTURES_H
