#include <stdio.h>
#include <stdlib.h>

// probably the real solution isn't this complex
// implemented dictionary (as i know in python but in C for now)
// learnt how to create a dict in C, which used a struct that has to be very precise on using memory and the limits of the dict
// dict uses struct, malloc, and free() (free = only if using malloc)
// the reason i have to use dict for this one is bc i needed the key value function to tie up alphabet given to it's position
// probably just ignore the warning about pointer bc by 29/07/2023, i have no idea why that matters.
// spent 3 days for this

int main() {
    char lots_of_char[3];
    int loc_1 = 1;
    int loc_2 = 2;
    int loc_3 = 3;
    int i;
    printf("Input three alphabets to put in order : ");
    scanf("%c %c %c", &lots_of_char[0], &lots_of_char[1], &lots_of_char[2]);
    printf("%c %c %c\n", lots_of_char[0], lots_of_char[1], lots_of_char[2]);
    // B D A, sort to A B D
    // tell the location of A B D before it was switched
    
    struct key_value {
        int key;
        char* value;
    };
    
    struct key_value *list_order = malloc(sizeof(struct key_value) * loc_3);
    if (list_order == NULL) {
        perror("Malloc");
        exit(EXIT_FAILURE);
    }
    
    list_order[0].key = lots_of_char[0];
    list_order[0].value = loc_1;
    
    list_order[1].key = lots_of_char[1];
    list_order[1].value = loc_2;
    
    list_order[2].key = lots_of_char[2];
    list_order[2].value = loc_3;
    
    // buat temporary variable utk hold value
    char temp_char;
    int temp_idx;
    int indicate_tof = 1;
    // jika cek lots_of_char[0] > lots_of_char[1] --> True,
    while (indicate_tof){
        if (list_order[0].key > list_order[1].key){
            temp_char = list_order[0].key;
            list_order[0].key = list_order[1].key;
            list_order[1].key = temp_char;
            temp_idx = list_order[0].value;
            list_order[0].value = list_order[1].value;
            list_order[1].value = temp_idx;
        }
        if (list_order[1].key > list_order[2].key){
            temp_char = list_order[1].key;
            list_order[1].key = list_order[2].key;
            list_order[2].key = temp_char;
            temp_idx = list_order[1].value;
            list_order[1].value = list_order[2].value;
            list_order[2].value = temp_idx;
        }
        if (list_order[0].key > list_order[2].key){
            temp_char = list_order[0].key;
            list_order[0].key = list_order[2].key;
            list_order[2].key = temp_char;
            temp_idx = list_order[0].value;
            list_order[0].value = list_order[2].value;
            list_order[2].value = temp_idx;
        }
        if (list_order[0].key < list_order[1].key && list_order[0].key < list_order[2].key && list_order[1].key < list_order[2].key){
            indicate_tof = 0;
        }
    }
    printf("%c %c %c\n", list_order[0].key, list_order[1].key, list_order[2].key);
    // isi temp var 
    
    printf("%c = %d\n", list_order[0].key, list_order[0].value);
    printf("%c = %d\n", list_order[1].key, list_order[1].value);
    printf("%c = %d\n", list_order[2].key, list_order[2].value);

    free(list_order);
    return 0;
}