#include <stdio.h>
#include <string.h>
#include <math.h> // import this library to use mathematical functions
#include <stdbool.h>

// functions, main() itu function, tapi di C, defaultnya memang sudah ada main(). main() utk menggerakan semua code yang ada.

// make new function below
void sec_func(){
    // function selain main(), kalo mau isinya terwujud, harus dipanggil didalam function main()
    printf("Hello second function!\n");
}

// functions can receive parameters that can be used for codes inside the function
void third_func(int insNum){
    int dumNum = 0;
    dumNum += insNum;
    printf("%d\n", dumNum);
}

// kalo mau functionnya return nilai dan bisa "dipakai", ya buat jadi type int dan return smthg.
int fourth_func(int x){
    return 100 + x;
}

// apabila mau cleaner code, kita bisa declare function kosong dl sperti int x; diatas main(), baru dibawah main() isi
void fifth_func(); // code will be below main(), but still call it in main()

int sixth_func(int k); // recursion

void learn_lib_math(float k, float l, int s);

int main(){
    // printf("Hello world\n");
    // printf("I am currently living in RTB.\n");

    // // in printf, if you were about to print something like %d %d, you should bracket one variable one by one
    // int zx = 1, xz = 2;
    // printf("%d %d\n", (zx), (xz)); // if you do (zx, xz), it will cause an error, because its like (1,2)

    // // scanf
    // char firstName[30];
    // printf("Enter your first name and press enter: ");
    // scanf("%s", &firstName); // always put &var_name biar gak error, biar merujuk ke var itu
    // printf("Hello %s\n", firstName);
    // // scanf always leaves \n after input. if there is fgets or scanf below it, you have to CONSUME the \n.

    // // you can use this line below 
    // while ((getchar()) != '\n');

    // // or just use fgets first, then scanf later.

    // // kalau mau input sentences, yang ada whitespace dll, pakai fgets
    // // rumus fgets = fgets(nama_variable_sbg_placeholder, sizeof(nama_variable_sbg_placeholder), stdin)
    // // fgets tidak pakai variable didepan sbg placeholder dia, karena lgsg masuk ke var didalam () nya fgets
    // char myName[50];
    // printf("What is your hobby?\nMy hobby is : ");
    // fgets(myName, sizeof(myName) --> kasih angka sizenya (misal kalo int doang brti kan 4) atau lgsg sizeof() jg bisa
    // supaya dia lgsg ambil result dari sizeof(), lalu  ,stdin);
    // printf("%s\n", myName);


    // // memory address. the place where variables are stored in an address.
    // // biasa pakai & utk nunjukkin lokasi memory address.
    // int tryMe = 100;
    // printf("%p\n", &tryMe); // pake %p karena point-ing the memory address iykwim. hexadec format (1-F)

    // // &var_name = pointer. basically.
    // // cara simpen lokasi memory address = 
    // int* ptrTryMe = &tryMe; // ini bisa disebut sebagai reference
    // printf("%p\n", (ptrTryMe));

    // // let's say mau ambil value sesuai memory address, caranya begini =
    // printf("%d\n", (*ptrTryMe)); //jadi yang pointer, di point lagi. kalo line ini *ptrTryMe artinya dereference

    // // kesimpulannya
    // printf("%p\n", (&tryMe)); // adalah pointer yg nunjukkin memory address
    // printf("%p\n", (ptrTryMe)); // sama aja tapi udah di declare dalam variable
    // printf("%d\n", (*ptrTryMe)); // menunjuk value dalam memory address

    // // pointers can be applied to list, as it can gives us the value inside the list using ptr.
    // int tryList[] = {5,10,15,20,25};
    // printf("%d\n", (*tryList)); //default = index 0 printed
    // printf("%d\n", (*(tryList + 1))); // index 1 or more, do *(var_name + 1 / n);

    // // looping ngambil semua isi list dengan pointer
    int i;
    for (i = 0; i < 5; ++i){
        printf("%d\n", (*(tryList + i)));
    }

    sec_func();
    third_func(15); // input (15) inside bracket bc the func req. parameter. called as arguments here, parameter there.
    printf("Your favorite number is %d\n", fourth_func(69)); // function called with parameters inside bc it returns value.
    fifth_func();
    printf("%d\n", sixth_func(10));
    learn_lib_math(1.4, 1.6, 4);
}

void fifth_func(){
    printf("This function is below main!\n");
}

int sixth_func(int k) { // recursion, example of using = fibonacci sequence
    if (k > 0) {
        return k + sixth_func(k - 1);
    }
    return 0;
}

void learn_lib_math(float k, float l, int s){
    // these stuff are probably most used from the library
    printf("%.1f\n", sqrt(s)); // square root
    printf("%.1f\n", ceil(k)); // ceil = tafsir keatas
    printf("%.1f\n", floor(l)); // floor = tafsir kebawah
    printf("%.1f\n", pow(s, 2)); // power = pangkat
    printf("%d\n", abs(-100)); // if the compiler ngomel, its literally fine.
}