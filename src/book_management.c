#include "data_structures.h"


/* initializeLibrary, addBook, listBooks gibi tüm fonksiyonların
 gerçek kodları buraya yazılacak.*/


// Sadece kitap listesini başlatır
void initializeBookList(Library *lib) {
    lib->book_list_head = NULL;
    lib->book_list_tail = NULL;
}

// Kitap Ekleme
void addBook(Library *lib, int id, const char* title, const char* author) {
    // 1. Yeni düğüm için bellekten yer al (malloc)
    BookNode *newNode = (BookNode*)malloc(sizeof(BookNode));
    if (newNode == NULL) {
        printf("Hata: Kitap eklenemedi (Bellek yetersiz)!\n");
        return;
    }

    // 2. Düğümün verilerini doldur
    newNode->id = id;
    strcpy(newNode->title, title);
    strcpy(newNode->author, author);
    newNode->is_reserved = 0;
    newNode->next = NULL; // Listenin sonuna eklenecek

    // 3. Listeye bağla (Kuyruk işaretçisi sayesinde O(1))
    if (lib->book_list_head == NULL) {
        // Bu ilk kitapsa
        lib->book_list_head = newNode;
        lib->book_list_tail = newNode;
    } else {
        // Listede zaten kitap(lar) varsa
        lib->book_list_tail->next = newNode;
        lib->book_list_tail = newNode;
    }
    printf("Kitap eklendi: %s\n", title);
}