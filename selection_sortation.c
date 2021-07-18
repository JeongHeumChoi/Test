#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int student_id;
    int english;
    int math;
    int korean;
} studentProfile;

void getStudentScore(studentProfile *profiles, int n);
void selectionSortation(studentProfile *profiles, int n);
void printStudentProfile(studentProfile *profiles, int n);

int main(void) {
    
    srand(time(NULL));

    studentProfile *profiles;
    int n;
    
    printf("Enter your student's number : ");
    scanf("%d", &n);
    
    profiles = (studentProfile*) malloc(sizeof(studentProfile) * n);

    getStudentScore(profiles, n);    
    printStudentProfile(profiles, n);
    selectionSortation(profiles, n);
    printf("\n\nSelection Sortation result!\n\n");
    printStudentProfile(profiles, n);

    return 0;
}

void getStudentScore(studentProfile *profiles, int n) {

    for (int i = 0; i < n; i++) {
        (profiles + i) -> student_id = i + 1;
        (profiles + i) -> english = rand() % 101;
        (profiles + i) -> math = rand() % 101;
        (profiles + i) -> korean = rand() % 101;
    }
    
    return;
}

void selectionSortation(studentProfile *profiles, int n) {

    studentProfile temp;
    int i, j, max, maxIndex;

    for (i = 0; i < n - 1; i++) {

        max = profiles->korean;
        j = 0;
        maxIndex = j;
        for (j = 0; j < n - i; j++)
            if (max < (profiles + j)->korean) {
                max = (profiles + j)->korean;
                maxIndex = j;
            }
        
        temp = *(profiles + maxIndex);
        *(profiles + maxIndex) = *(profiles + j - 1);
        *(profiles + j - 1) = temp;
    }
            
    return;
}

void printStudentProfile(studentProfile *profiles, int n) {

    for (int i = 0; i < n; i++)
        printf("student ID : %5d\tEnglish : %5d\tMath : %5d\tKorean : %5d\n", (profiles + i)->student_id, \
                (profiles + i)->english, (profiles + i)->math, (profiles + i)->korean);
    
    return;
}
