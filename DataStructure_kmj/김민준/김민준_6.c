#define swap(x,y,t)((t)=(x),(x)=(y),(y)=(t))
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_pokemon {
    char pokemon_name[21];
    int pokemon_num;
} Pokemon;

int compare_pokemon_name(const void* a, const void* b) {
    return strcmp(((Pokemon*)a)->pokemon_name, ((Pokemon*)b)->pokemon_name);
}

int binary_search(Pokemon* list, char pokemon_name[], int l, int r) {
    while (l <= r) {
        int middle = (l + r) / 2;
        int cmp = strcmp((list + middle)->pokemon_name, pokemon_name);

        if (cmp == 0) return (list + middle)->pokemon_num;
        if (cmp < 0) l = middle + 1;
        else r = middle - 1;
    }
    return -1;
}

int main() {
    int pokemon_count, problem_count;
    char pokemon_name[21];
    scanf("%d %d", &pokemon_count, &problem_count);

    Pokemon* list = (Pokemon*)calloc(pokemon_count, sizeof(Pokemon));
    Pokemon* list_copy = (Pokemon*)calloc(pokemon_count, sizeof(Pokemon));

    for (int i = 0; i < pokemon_count; i++) {
        scanf("%s", (list + i)->pokemon_name);
        (list + i)->pokemon_num = i + 1;
    }

    memcpy(list_copy, list, sizeof(Pokemon) * pokemon_count);

    qsort(list_copy, pokemon_count, sizeof(Pokemon), compare_pokemon_name);

    for (int i = 0; i < problem_count; i++) {
        scanf("%s", pokemon_name);

        if (pokemon_name[0] >= 'A' && pokemon_name[0] <= 'Z') {
            int result = binary_search(list_copy, pokemon_name, 0, pokemon_count - 1);
            if (result != -1) {
                printf("%d\n", result);
            }
            else {
                printf("Pokemon not found\n");
            }
        }
        else if (pokemon_name[0] >= '0' && pokemon_name[0] <= '9') {
            printf("%s\n", (list + atoi(pokemon_name) - 1)->pokemon_name);
        }
    }

    free(list);
    free(list_copy);

    return 0;
}

