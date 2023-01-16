#include <stdio.h>
#include <stdlib.h>
/*
 * * COP 3515 – Fall Semester, 2020  *
 * * Homework #2: The Hospital Bed Problem  *
 * * Matthew Signore  *
 * */

/*
 * The structure for a patient
 * */
struct patient {
    int daysTillRelease;
    char gender;
    struct hospital {
            int floor;
            int room;
    } hospital1;

};

/*
 * The structure for the hospital rooms and availability
 * */
struct hospitalSpace{
    int floor;
    int room;
    int available;
    char gender;
};

/*
 * The functions and global variables that are initialized
 * */
int covidPrintCounter = 0;
int covidPositiveCount (struct hospitalSpace im[]);
int covidNegativeCount (struct hospitalSpace im[]);
int covidPositiveFloors (struct hospitalSpace im[]);
int covidNegativeFloors (struct hospitalSpace im[]);
int highestFloor (struct hospitalSpace im[]);
int floorsFreeList[10];
int listcounter = -1;

int main() {
    setbuf(stdout, 0);

    /*
 * Creating the structures and local main variables
 * */

    struct patient patients[100];
    struct hospitalSpace space[100];
    FILE *file;
    char string [50];
    int count = 0;

    int floorcount = 1;
    int floorNumber = 1;
    char tempnumber [2];

    /*
 * Reading the file and turning it's data into the structure
 * */
    file = fopen("C:\\Users\\polan\\CLionProjects\\homework2\\data.txt", "r");



    while  (fgets(string, 50, file)) {

        patients[count].gender = string[0];
        space[count].gender = string[0];
        tempnumber[0] = string[2];
        tempnumber[1] = string[3];
        patients[count].daysTillRelease = atoi(tempnumber);

        if (floorcount == 10 ) {
            patients[count].hospital1.floor = floorNumber;
            patients[count].hospital1.room = floorcount;
            space[count].room = floorcount;
            space[count].floor = floorNumber;
            floorcount = 1;
            space[count].available = 0;
            floorNumber++;
        }
        else
        {patients[count].hospital1.floor = floorNumber;
            patients[count].hospital1.room = floorcount;
            space[count].available = 0;
            space[count].room = floorcount;
            space[count].floor = floorNumber;
            floorcount++;
        }

        count++;
    }

int daycount = 0;

    /* This is the simulator for each day in Scenario #1 or 2 */
    char s;
    printf("Would you like to run Scenario #1 (Statistics) or Scenario #2(Room Reallocation)? Please enter '1' or '2':");
    scanf("%c", &s);

        for (int x = 0; x < 28; x++) {
            int z = 99;
            int zlimit = 90;
            setbuf(stdin, 0);
            char c;
            printf("Today is Day %d, Would you like to see the current bed space for today? Please enter 'Y' or 'N'",
                   daycount);
            scanf("%c", &c);


            if (c == 'Y' || c == 'N') {

                /*
                * This counts down the days till release, then if it is in scenario #2,
                 * it replaces the bed to a lower floor when someone is released
                * */
            for (int h = 99; h >= 0; h--) {
                patients[h].daysTillRelease--;
                if (patients[h].daysTillRelease == 0) {

                    space[h].available = 1;
                    covidPrintCounter ++;
                    if ((h <= highestFloor(space)) && ( s == '2')) {
                        space[highestFloor(space)].available = 1;
                        space[h].available = 0;
                        space[h].gender = space[highestFloor(space)].gender;

                    }
                    patients[h].daysTillRelease = -1;
                }


            }

            /* This is where the data gets printed for showing the bed spaces
            *
            * */
                if (c == 'Y'){
                for (int v = 10; v > 0; v--) {
                    printf("Floor %d - ", v);
                    for (z; z >= zlimit; z--) {
                        if ( space[z].available == 0) {
                            printf(" %c ", space[z].gender);
                        }
                        else {
                            printf(" . ");
                        }
                    }
                    printf("\n");
                    zlimit = zlimit - 10;
                }
                }
                /*
                * This is where the print functions are handled
                 * for every 10 patients that are released.
                 * It calls upon various functions that handle the calculations for floor
                 * space and the patient counts
                * */
                if ((covidNegativeFloors(space) > 0) || (covidPrintCounter >= 10)) {
                    printf("\n 10 More patients have left the hospital");
                    printf("\nThe current COVID free floors are: ");
                    {
                        int counterFloors = covidNegativeFloors(space);
                        for (counterFloors; counterFloors > 0; counterFloors--) {
                            printf(" %d ", floorsFreeList[counterFloors - 1]);
                        }
                    }
                    printf("\n There are %d COVID patients and %d empty beds",
                           covidPositiveCount(space),
                           covidNegativeCount(space));

                    printf("\n There are %d floors with COVID patients and %d floors that are COVID-free. \n",
                           covidPositiveFloors(space),
                           covidNegativeFloors(space));
                    covidPrintCounter = 0;
                }

            }

            daycount++;
        }
        printf("\n Hospital bed simulation for scenario #%c is complete", s);


    return 0;

}

/* This returns the highest floor that is occupied by a COVID patient*/
int highestFloor(struct hospitalSpace im[]){
    int highest = 0;
    for (int x = 0; x <= 99; x++){
        if (im[x].available == 0){
            highest = x;
        }
    }
    return highest;
}
/* This returns the count of COVID patients currently in the hospital*/
int covidPositiveCount(struct hospitalSpace im[]){
    int covid = 0;
    for (int j = 99; j >= 0; j--){
        if (im[j].available != 1) {
            covid++;

        }


    }
    return covid;
}
/* This returns the empty bed count */
int covidNegativeCount(struct hospitalSpace im[]){
    int nonCovid = 0;
    for (int j = 99; j >= 0; j--){
        if (im[j].available == 1) {
            nonCovid++;
        }


    }
    return nonCovid;
}

/* This returns the current amount of floors that have tested positive for COVID */
int covidPositiveFloors(struct hospitalSpace im[]){
    int covidnFreefloors = 0;
    int s= 99;
    int slimit = 90;
    int checker = 0;
    for ( int n = 10; n > 0; n-- ) {
        for (s; s >= slimit; s--){
            if (im[s].available != 1) {
                checker = 1;
            }



        }
        if (checker == 1){
            covidnFreefloors++;
        }
        checker = 0;
        slimit = slimit - 10;
    }
    return covidnFreefloors;
}
/* This returns the total floors that are clear of COVID patients */
int covidNegativeFloors(struct hospitalSpace im[]){
    int covidFreefloors = 0;
    listcounter = -1;
    int s= 99;
    int slimit = 90;
    int checker = 0;
    for ( int n = 10; n > 0; n-- ) {
        for (s; s >= slimit; s--){
            if (im[s].available != 1) {
                checker = 1;
            }



        }
        if (checker == 0){
            floorsFreeList[n/n + listcounter] = n;
            listcounter++;
            covidFreefloors++;
        }
        checker = 0;
        slimit = slimit - 10;
    }
    return covidFreefloors;
}
