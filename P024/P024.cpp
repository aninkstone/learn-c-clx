#include <iostream>
#include "P024_P022.h"

#define sitebigandsmell 32

void j(char site[][sitebigandsmell], char move,int currPosX, int currPosY);
void k(char site[][sitebigandsmell]);
int* y(char site[][sitebigandsmell]);
void snake_eats_beans(int currPosX, int currPosY, int currPosxtwo, int currPosytwo, char site[][sitebigandsmell]);
int Generate_random_numbers_from_1_to_1000();

int currPosytwo = 'u';
int currPosxtwo = 'u';
int extent = 1;
struct Node* head = NULL;

int main(){
	char move = 0;
	char site[sitebigandsmell][sitebigandsmell] = { 0 };
    int currPosX = sitebigandsmell / 2;
    int currPosY = sitebigandsmell / 2;
    j(site, move,currPosX, currPosY);
}

void j(char site[][sitebigandsmell], char move, int currPosX, int currPosY) {
    site[sitebigandsmell / 2][sitebigandsmell / 2] = 4;
    head = CreateList(extent);
    k(site);
	for (; true;) {
		scanf("%c", &move);
        switch (move){
        case'w':
            head->orientation = 1;
            int nn = CountList(head);
            for (int p = 0; true; p++) {
                if (nn == p) {
                    site[currPosY][currPosX] = 0;
                    currPosY = currPosY - 1;
                    break;
                }
            }
            //site[currPosY][currPosX] = 0;
            //currPosY = currPosY - 1;
            snake_eats_beans(currPosX, currPosY, currPosxtwo, currPosytwo, site);
            site[currPosY][currPosX] = 4;
            if (currPosxtwo == 'u') {
                int* b = y(site);
                *b = currPosxtwo;
                b++;
                *b = currPosytwo;
            }
            k(site);
            break;
        case's':
            head->orientation = 2;

            if (currPosxtwo == 'u') {
                int* b = y(site);
                *b = currPosxtwo;
                b++;
                *b = currPosytwo;
            }
            k(site);
            break;
        case'a':
            
            break;
        case'd':
            
            break;
        default:
            break;
        }
		move = 0;
	}
}
void snake_eats_beans(int currPosX, int currPosY, int currPosxtwo, int currPosytwo, char site[][sitebigandsmell]) {
    if (currPosX == currPosxtwo) {
        if (currPosY == currPosytwo) {
            site[currPosY][currPosX] = 4;
            DestroyList(head);
            extent++;
            head = CreateList(extent);
            switch (head->orientation) {
            case 1:
                ApplyValue(extent, 'y', currPosY + 1, head);
                break;
            case 2:
                ApplyValue(extent, 'y', currPosY - 1, head);
                break;
            case 3:
                ApplyValue(extent, 'x', currPosX + 1, head);
                break;
            case 4:
                ApplyValue(extent, 'x', currPosX - 1, head);
                break;
            }
            
        }
    }
    currPosytwo = 'u';
    currPosxtwo = 'u';
    return;
}
int* y(char site[][sitebigandsmell]) {
    int coordinates_of_beans__1X2Y[2] = { 0 };
    int o = 500;
    currPosytwo = Generate_random_numbers_from_1_to_1000();
    currPosxtwo = 0;
    if (currPosytwo < o) {
        currPosytwo = Generate_random_numbers_from_1_to_1000() % sitebigandsmell;
        currPosxtwo = Generate_random_numbers_from_1_to_1000() % sitebigandsmell;
        coordinates_of_beans__1X2Y[0] = currPosxtwo;
        coordinates_of_beans__1X2Y[1] = currPosytwo;
        site[currPosytwo][currPosxtwo] = 2;
        return (int*)coordinates_of_beans__1X2Y;
    }
}
void k(char site[][sitebigandsmell]) {
    for (int o = 0; o < sitebigandsmell; o++) {
        for (int i = 0; i < sitebigandsmell; i++) {
            printf("%d", site[o][i]);
        }
        printf("\n");
    }
    return;
}
void move(int currPosY, int currPosX,char site[][sitebigandsmell]) {
    int d = 0;
    int f = 0;
    int o = 0;
    int nn = CountList(head);
    if (nn == 1) {
        site[currPosY][currPosX] = 0;
        currPosY = currPosY - 1;
    }
    else {
        f = CountList(head);
        for (int n = 1; n < f; n++) {
            if (n + 1 == f + 1) {
                d = ReadValue(n + 1, 'x', head);
            }
            o = ReadValue(n, 'x', head);
            if (n + 1 == f + 1) {
                return;
            }
            else {
                ApplyValue(n + 1, 'x', o, head);
            }
        }
        ApplyValue(1, 'x', , head);
    }
    return;
}
int Generate_random_numbers_from_1_to_1000() {
    srand(time(NULL));
    int random_number = rand() % 1000 + 1;
    return random_number;
}

int Swap(struct Node* src, struct Node* des) {

}