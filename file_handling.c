#include <stdio.h>

int main(){
    // the way to handle files in c is using pointer, of course.

    // always start with the line FILE *nama_var
    FILE *fileptr;

    // to open a file = fopen(filename, mode);
    // mode = write, read, append

    // write, dia bakal nulis di file yg dituju, kalo dalam file itu ada isi, overwritten. ga harus buat 
    fileptr = fopen("tumbal_untuk_file_handling.txt", "w");

    // untuk print isian dari file yang dibuka, pakai fprintf (no var declaration required)
    fprintf(fileptr, "Hello\nIt is a,\nBatman.");

    // close the file
    fclose(fileptr);

    // append texts
    fileptr = fopen("tumbal_untuk_file_handling.txt", "a");

    // sama aja cara isinya kayak write, cuma bedanya dia gabakal overwrite gara gara itu append bukan write (mode open filenya)
    fprintf(fileptr, "\nThis is the continuation of the writing before.\nBecause it is an append mode\nIt won't overwrite the writings.");

    fclose(fileptr);


    // SUMMARY 29/07/2023
    // WRITE AND APPEND FILES ARE POSSIBLE USING fopen("nama_file.extensionnya apa", "w" / "a")
    // CHECKPOINT HERE, LEARNING HOW TO READ FILES IN C

    // how to read files from C
    fileptr = fopen("tumbal_untuk_file_handling.txt", "r");

    // jika file yg di read ga ada isi, dia bakal return NULL
    // ada baiknnya bikin pengecekan if null = printf gak ada isi
    if (fileptr == NULL) {
        printf("Nothing inside to read !");
    }
    else {
        // buat variable untuk tampung text / data yang bakal diretrieve dulu dari file yang dituju

        // kalau bisa memorinya spesifik dibuat dalam []
        char takeData[100];

        // retrieve dengan fgets(), masukkin target fgets ke var yang dibuat utk nampung data
        // kalo cuma fgets doang, dia cuma bakalan ambil line pertama, line kedua dll kebawah gak bakal diambil

        // maka dari itu pake while loop untuk ambil semua
        // whilenya langsung ambil kondisi fgetsnya
        while (fgets(takeData, sizeof(takeData), fileptr)) { // var yang dimasukkin di urutan ke 3 fgets = var yg buka filenya (line 35)
            printf("%s", takeData);
        }

        // always do fclose(nama_var)
        fclose(fileptr);
    }
    
}