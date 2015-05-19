#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int t[9];
    int selection[9];
    int max[9] = {0};
    int maxy[9] = {0};
    int matrix[9][10];
    int count[10] = {0};
    int s0, s1, s2, s3, s4, s5, s6, s7, s8;
    int a, b, c, d, e, f, g, h, i, j, k, r, u, v, x, y, m = 0, step = 10;

    for(a = 0; a < 9; a++) {
        selection[a] = -1;
    }

    //matrix is reset.
    for (x = 0; x < 9; x++) {
        for (y = 0; y < 10; y++) {
            matrix[x][y] = 0;
        }
    }
 
    //Enter number.
    printf("Please enter the number held[Write line or leaving your space bar]: \n");

    //Read number.
    for (d = 0; d < 9; d++) {
        scanf("%d", &t[d]);
    }

    //Write number.
    printf("The number entered :");
    for (d = 0; d < 9; d++) {
        printf("%d", t[d]);
    }

    //Matrix printed.
        printf("\n---------------------------------------------------------\n");
        for (x = 0; x < 9; x++) {
            for (y = 0; y < 10; y++) {
                printf(" %-4d ", matrix[x][y]);
            }
            printf("\n");
        }
        printf("---------------------------------------------------------\n");

    //000000000 -...- 999999999 compared numbers. How many pieces of which figure is learned.
    for (j = 0; j < 9; j++) {
        for(c = 0; c < 10; c++) {
            if (t[j] == c) {
                count[c] += 1;
            }
        }
    }

    //If there are no figures on the number entered that figure is given to -1.
    for (j = 0; j < 9; j++) {
        for(c = 0; c < 10; c++) {
            if (count[c] == 0) {
                count[c] = -1;
            }
        }
    }

    //If you have -1 figure. The array is given a value of -1.
    for (g = 0; g < 10; g++) {
        for (f = 0; f < 10; f++) {
            if(count[g] == -1) {
                matrix[f][g] = count[g];
            }
        }
    }

    //What number it is printed as many pieces.
    printf("\nEntered number pieces:");
    for (k = 0; k < 10; k++) {
        printf("\n%d. %d",k, count[k]);
    }

    //This figure is then transferred to selection array.
    for (c = 0; c < 10; c++) {
        e = count[c];
        switch (e) {
        case 1:{
            int x = 0;
            while(selection[x] != -1) {
                x++;
            }
            selection[x] = c;
            break;
        }
        case 2: {
            for (h = 0; h < 2; h++) {
                int x = 0;
                while(selection[x] != -1) {
                    x++;
                }
                selection[x] = c;
            }
            break;
        }
        case 3:{
            for (h = 0; h < 3; h++) {
                int x = 0;
                while(selection[x] != -1) {
                    x++;
                }
                selection[x] = c;
            }
            break;
        }
        case 4:{
            for (h = 0; h < 4; h++) {
                int x = 0;
                while(selection[x] != -1) {
                    x++;
                }
                selection[x] = c;
            }
            break;
        }
        case 5:{
            for (h = 0; h < 5; h++) {
                int x = 0;
                while(selection[x] != -1) {
                    x++;
                }
                selection[x] = c;
            }
            break;
        }
        case 6:{
            for (h = 0; h < 6; h++) {
                int x = 0;
                while(selection[x] != -1) {
                    x++;
                }
                selection[x] = c;
            }
            break;
        }
        case 7:{
            for (h = 0; h < 7; h++) {
                int x = 0;
                while(selection[x] != -1) {
                    x++;
                }
                selection[x] = c;
            }
            break;
        }
        case 8:{
            for (h = 0; h < 8; h++) {
                int x = 0;
                while(selection[x] != -1) {
                    x++;
                }
                selection[x] = c;
            }
            break;
        }
        case 9:{
            for (h = 0; h < 9; h++) {
                int x = 0;
                while(selection[x] != -1) {
                    x++;
                }
                selection[x] = c;
            }
            break;
        }
        default:
            break;
        }
    }

    //Selection array is printed.
    printf("\nselection :");
    for (k = 0; k < 9; k++) {
        printf("%d", selection[k]);
    }

    //Matrix printed.
    printf("\n---------------------------------------------------------\n");
    for (x = 0; x < 9; x++) {
        for (y = 0; y < 10; y++) {
            printf(" %-4d ", matrix[x][y]);
        }
        printf("\n");
    }
    printf("---------------------------------------------------------\n");

    //It must have the number entered in step 729 is probably the most bad.
    for (i = 0; i < 729; i++) {

        //25, 50, 75 and 100. step figures that have the greatest value in the matrix asked whether steps are held number is printed on the screen.
        //The game ends if the number is correct, incorrect continues.
        if (step == 24 || step == 49 || step == 74 || step == 99) {
            for (x = 0; x < 9; x++) {
                for (y = 0; y < 10; y++) {
                    if (matrix[x][y] > max[x]) {
                        max[x] = matrix[x][y];
                        maxy[x] = y;
                    }
                }
                printf("max:%d maxy:%d\n", max[x], maxy[x]);
            }
            step++;
            printf("%d. step\n", step);
            printf("%d%d%d%d%d%d%d%d%d <- Entered Number\n", t[0], t[1], t[2], t[3], t[4], t[5], t[6], t[7], t[8]);
            for (x = 0; x < 9; x++) { printf("%d", maxy[x]); } printf(" <- Estimated Number\n");
            printf("Is it true estimated number?[1/0]: "); scanf("%d", &v);
            switch (v) { case 0: { continue; break; } case 1: { m = 9; break; } default: break; }
        } else {
            //Randomly selected from the array number is compared with the number entered.
            //How many number are correctly given as the answer place.
            step++;
            printf("%d. step\n", step);
            printf("%d%d%d%d%d%d%d%d%d <- Entered Number\n", t[0], t[1], t[2], t[3], t[4], t[5], t[6], t[7], t[8]);
            for(b = 0; b < 9; b++) {
                u = selection[b];
                r = rand() % 9;
                selection[b] = selection[r];
                selection[r] = u;
            }
            for (x = 0; x < 9; x++) { printf("%d", selection[x]); } printf(" <- Estimated Number\n");
            printf("How many digits right place?: "); scanf("%d", &m);

            s0 = selection[0];
            s1 = selection[1];
            s2 = selection[2];
            s3 = selection[3];
            s4 = selection[4];
            s5 = selection[5];
            s6 = selection[6];
            s7 = selection[7];
            s8 = selection[8];
        }

        //According to figures probability value is added
        switch (m) {
        case 0: {
            matrix[0][s0] = 0;
            matrix[1][s1] = 0;
            matrix[2][s2] = 0;
            matrix[3][s3] = 0;
            matrix[4][s4] = 0;
            matrix[5][s5] = 0;
            matrix[6][s6] = 0;
            matrix[7][s7] = 0;
            matrix[8][s8] = 0;
            break;
        }
        case 1: {
            matrix[0][s0] += 11;
            matrix[1][s1] += 11;
            matrix[2][s2] += 11;
            matrix[3][s3] += 11;
            matrix[4][s4] += 11;
            matrix[5][s5] += 11;
            matrix[6][s6] += 11;
            matrix[7][s7] += 11;
            matrix[8][s8] += 11;
            break;
        }
        case 2: {
            matrix[0][s0] += 22;
            matrix[1][s1] += 22;
            matrix[2][s2] += 22;
            matrix[3][s3] += 22;
            matrix[4][s4] += 22;
            matrix[5][s5] += 22;
            matrix[6][s6] += 22;
            matrix[7][s7] += 22;
            matrix[8][s8] += 22;
            break;
        }
        case 3: {
            matrix[0][s0] += 33;
            matrix[1][s1] += 33;
            matrix[2][s2] += 33;
            matrix[3][s3] += 33;
            matrix[4][s4] += 33;
            matrix[5][s5] += 33;
            matrix[6][s6] += 33;
            matrix[7][s7] += 33;
            matrix[8][s8] += 33;
            break;
        }
        case 4: {
            matrix[0][s0] += 44;
            matrix[1][s1] += 44;
            matrix[2][s2] += 44;
            matrix[3][s3] += 44;
            matrix[4][s4] += 44;
            matrix[5][s5] += 44;
            matrix[6][s6] += 44;
            matrix[7][s7] += 44;
            matrix[8][s8] += 44;
            break;
        }
        case 5: {
            matrix[0][s0] += 55;
            matrix[1][s1] += 55;
            matrix[2][s2] += 55;
            matrix[3][s3] += 55;
            matrix[4][s4] += 55;
            matrix[5][s5] += 55;
            matrix[6][s6] += 55;
            matrix[7][s7] += 55;
            matrix[8][s8] += 55;
            break;
        }
        case 6: {
            matrix[0][s0] += 66;
            matrix[1][s1] += 66;
            matrix[2][s2] += 66;
            matrix[3][s3] += 66;
            matrix[4][s4] += 66;
            matrix[5][s5] += 66;
            matrix[6][s6] += 66;
            matrix[7][s7] += 66;
            matrix[8][s8] += 66;
            break;
        }
        case 7: {
            matrix[0][s0] += 77;
            matrix[1][s1] += 77;
            matrix[2][s2] += 77;
            matrix[3][s3] += 77;
            matrix[4][s4] += 77;
            matrix[5][s5] += 77;
            matrix[6][s6] += 77;
            matrix[7][s7] += 77;
            matrix[8][s8] += 77;
            break;
        }
        case 8: {
            matrix[0][s0] += 88;
            matrix[1][s1] += 88;
            matrix[2][s2] += 88;
            matrix[3][s3] += 88;
            matrix[4][s4] += 88;
            matrix[5][s5] += 88;
            matrix[6][s6] += 88;
            matrix[7][s7] += 88;
            matrix[8][s8] += 88;
            break;
        }
        case 9:
        {
            matrix[0][s0] += 99;
            matrix[1][s1] += 99;
            matrix[2][s2] += 99;
            matrix[3][s3] += 99;
            matrix[4][s4] += 99;
            matrix[5][s5] += 99;
            matrix[6][s6] += 99;
            matrix[7][s7] += 99;
            matrix[8][s8] += 99;
            printf("%d held\n", m);
            printf("%d. step\n", step);
            printf("Number Found!\n");
            printf("%d%d%d%d%d%d%d%d%d <- Entered number\n", t[0], t[1], t[2], t[3], t[4], t[5], t[6], t[7], t[8]);
            break;
        }
        default:
            printf("An incorrect value your input!\n");
            break;
        }

        //Matrix printed.
        printf("---------------------------------------------------------\n");
        for (x = 0; x < 9; x++) {
            for (y = 0; y < 10; y++) {
                printf(" %-4d ", matrix[x][y]);
            }
            printf("\n");
        }
        printf("---------------------------------------------------------\n");
        if (m == 9) { break; }
    }
    return 0;
}
