#include <stdio.h>
#include <string.h>
struct Movie {
    char title[50];
    char genre[30];
    char director[50];
    int releaseYear;
    float rating;
};
void display(struct Movie m) {
    printf("\nTitle: %s\n", m.title);
    printf("Genre: %s\n", m.genre);
    printf("Director: %s\n", m.director);
	printf("Release Year: %d\n", m.releaseYear);
    printf("Rating: %.1f/10\n", m.rating);
}
int main() {
    struct Movie movies[10];
    int count = 0;           
    int choice, i;
    do{
        printf("\n=== Movie Menu ===\n");
        printf("1. Add a New Movie\n");
        printf("2. Search Movies by Genre\n");
        printf("3. Display All Movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
        	if (count < 10){
            printf("\nEnter movie title: ");
            scanf("%s", movies[count].title);
            printf("Enter genre: ");
            scanf("%s", movies[count].genre);
            printf("Enter director: ");
            scanf("%s", movies[count].director);
            printf("Enter release year: ");
            scanf("%d", &movies[count].releaseYear);
            printf("Enter rating: ");
            scanf("%f", &movies[count].rating);
            count++;
            printf("Movie added successfully!\n");
        } else {
        	printf("\nMovie list is full");
		}
        } else if (choice == 2) {
            char searchGenre[30];
            int found = 0;
            printf("\nEnter genre to search: ");
            scanf("%s", searchGenre);
            printf("\n=== Matching Movies ===\n");
            for (i = 0; i < count; i++) {
                if (strcmp(movies[i].genre, searchGenre) == 0) {
                    display(movies[i]);
                    found = 1;
                }
            }
            if (found == 0) {
                printf("No movies found in this genre.\n");
            }
        } else if (choice == 3) {
            if (count == 0) {
                printf("\nNo movies added yet.\n");
            } else {
                printf("\n=== All Movies ===\n");
                for (i = 0; i < count; i++) {
                	display(movies[i]);
                }
            }
    }
    } while (choice != 4);
            printf("program ended.\n");
    return 0;
}
