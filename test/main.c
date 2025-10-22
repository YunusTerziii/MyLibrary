#include "data_structures.h" 

void printMenu() 
{
    printf("\n--- Kütüphane Yönetim Sistemi ---\n");
    printf("1. Kitapları Listele\n");
    printf("2. Yeni Kitap Ekle\n");
    printf("3. Koltuk Durumunu Göster\n");
    printf("0. Çıkış\n");
    printf("Seçiminiz: ");
}

int main()
{
    Library myLibrary;
    initializeLibrary(&myLibrary);

    int id;
    char title[100];   // Struct'taki boyutla aynı olmalı
    char author[100];  // Struct'taki boyutla aynı olmalı 
    printf("Eklenecek Kitap ID'si: ");
    scanf("%d", &id);

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Kitap Başlığı: ");
    fgets(title, 100, stdin);

    title[strcspn(title, "\n")] = '\0';

    printf("Yazar Adı: ");
    fgets(author, 100, stdin);

    author[strcspn(author, "\n")] = '\0';
    addBook(&myLibrary, id, title, author);



    return 0;
}