// Bize size_t gibi tipleri sağlar.
#include <stddef.h> 

// *** 1. Düğüm Yapısı (Node) ***
// struct Node'u tanımlıyoruz, çünkü kendi içine işaret edecek.
typedef struct Node {
    void *data;               // Saklanan veriyi gösteren genel işaretçi
    struct Node *next;        // Listede bir sonraki Node'a işaretçi
} Node; 
