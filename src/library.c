#include "data_structures.h"

void initializeBookList(Library *lib);

// Bu "ana" başlatıcıdır
void initializeLibrary(Library *lib) {
    // Her modülün kendi başlatma fonksiyonunu çağır
    initializeBookList(lib);

    //initializeSeats(lib);
    // initializeStudentList(lib);
    
    lib->total_students = 0;
}

// Not: Program biterken belleği temizlemek için
// bir cleanupLibrary(Library *lib) fonksiyonunu da
// buraya yazmak iyi bir fikirdir.