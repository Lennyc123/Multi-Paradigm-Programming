// Header files to use functions available in the standard C library.
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Global Variables:
char grade[][5] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "D-", "F"};
float gpaVal[] = {4.2, 4.0, 3.8, 3.2, 3.0, 2.8, 2.2, 2.0, 1.8, 1.2, 1.0, 0.8, 0.0};
char moduleNames[][50] = {"Intro to Programming", "Databases", "Computer Architecture", "Ethics in Computer Science",  "Advanced Programming", "Puzzles and Problem Solving"};

// Function to count the number of students within the provided CSV file.
int countStudents(){
    FILE *file = fopen("CTASample.csv", "r");
    char line[256];

    int countStudent = 0;
    while (fgets(line, sizeof(line), file)){
        countStudent++;
        if (countStudent>=2){
            char *name = strtok(line, ",");
        }
    }
    int studentNumber = countStudent;
    fclose(file);
    return studentNumber;
}

// Defining what grade letter is provided based on ones percentage.
int gradeLetter(float percentR)
{
    if (percentR >= 90 && percentR <= 100){
        char *gradeR = grade[0];
        printf("Grade: %s", gradeR);
    } else if (percentR >= 85 && percentR <= 89){
        char *gradeR = grade[1];
        printf("Grade: %s", gradeR);
    } else if (percentR >= 80 && percentR <= 84){
        char *gradeR = grade[2];
        printf("Grade: %s", gradeR);
    } else if (percentR >= 75 && percentR <= 79){
        char *gradeR = grade[3];
        printf("Grade: %s", gradeR);
    } else if (percentR >= 70 && percentR <= 74){
        char *gradeR = grade[4];
        printf("Grade: %s", gradeR);
    } else if (percentR >= 65 && percentR <= 69){
        char *gradeR = grade[5];
        printf("Grade: %s", gradeR);
    } else if (percentR >= 60 && percentR <= 64){
        char *gradeR = grade[6];
        printf("Grade: %s", gradeR);
    } else if (percentR >= 55 && percentR <= 59){
        char *gradeR = grade[7];
        printf("Grade: %s", gradeR);
    } else if (percentR >= 50 && percentR <= 54){
        char *gradeR = grade[8];
        printf("Grade: %s", gradeR);
    } else if (percentR >= 45 && percentR <= 49){
        char *gradeR = grade[9];
        printf("Grade: %s", gradeR);
    } else if (percentR >= 40 && percentR <= 44){
        char *gradeR = grade[10];
        printf("Grade: %s", gradeR);
    } else if (percentR >= 35 && percentR <= 39){
        char *gradeR = grade[11];
        printf("Grade: %s", gradeR);
    } else if (percentR <= 35){
        char *gradeR = grade[12];
        printf("Grade: %s", gradeR);
    }
}

// Defining what GPA score is provided based on ones percentage.
int gpaCal(float percentR){
    if (percentR >= 90 && percentR <= 100){
        float gpaR = gpaVal[0];
        printf("GPA: %.1f", gpaR);
    } else if (percentR >= 85 && percentR <= 89){
        float gpaR = gpaVal[1];
        printf("GPA: %.1f", gpaR);
    } else if (percentR >= 80 && percentR <= 84){
        float gpaR = gpaVal[2];
        printf("GPA: %.1f", gpaR);
    } else if (percentR >= 75 && percentR <= 79){
        float gpaR = gpaVal[3];
        printf("GPA: %.1f", gpaR);
    } else if (percentR >= 70 && percentR <= 74){
        float gpaR = gpaVal[4];
        printf("GPA: %.1f", gpaR);
    } else if (percentR >= 65 && percentR <= 69){
        float gpaR = gpaVal[5];
        printf("GPA: %.1f", gpaR);
    } else if (percentR >= 60 && percentR <= 64){
        float gpaR = gpaVal[6];
        printf("GPA: %.1f", gpaR);
    } else if (percentR >= 55 && percentR <= 59){
        float gpaR = gpaVal[7];
        printf("GPA: %.1f", gpaR);
    } else if (percentR >= 50 && percentR <= 54){
        float gpaR = gpaVal[8];
        printf("GPA: %.1f", gpaR);
    } else if (percentR >= 45 && percentR <= 49){
        float gpaR = gpaVal[9];
        printf("GPA: %.1f", gpaR);
    } else if (percentR >= 40 && percentR <= 44){
        float gpaR = gpaVal[10];
        printf("GPA: %.1f", gpaR);
    } else if (percentR >= 35 && percentR <= 39){
        float gpaR = gpaVal[11];
        printf("GPA: %.1f", gpaR);
    } else if (percentR <= 35){
        float gpaR = gpaVal[12];
        printf("GPA: %.1f", gpaR);
    }
}

// Getting a students highest scoring module
int largest(int array[], int n)
{
    int i;
    // Initialize maximum element
    int max = array[0];
    // Traverse array elements from second and
    // compare every element with current max 
    for (i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];
 
    return max;
}

// Getting a students lowest scoring module
int smallest(int array[], int n)
{
    int i;
    int min = array[0];
    for (i = 1; i < n; i++)
        if (array[i] < min)
            min = array[i];
 
    return min;
}

// Standard deviation of a students results
float CSD(float data[])
{
    float sum=0.0, mean, SD=0.0;
    int i;
    for(i=0;i<6;i++)
    {
        sum+=data[i];
        mean=sum/6;
    }
    for(i=0;i<6;i++)
        SD+=pow(data[i]-mean,2);
    return sqrt(SD/6);
}

// Getting the average of a students results and converting their average to a gpa score.
int studentGPA(int i)
{   
    // Reading CSV File
    FILE *file = fopen("CTASample.csv", "r");
    char line[256];

    int j = 0;
    while (fgets(line, sizeof(line), file)){
        j++;
        if(j == i)
        {   
            // Breaking string into a series of tokens using a delimiter.
            char *name = strtok(line, ",");
            char *IntrotoProgramming = strtok(NULL, ",");
            char *Databases = strtok(NULL, ",");
            char *ComputerArchitecture = strtok(NULL, ",");
            char *EthicsinComputerScience = strtok(NULL, ",");
            char *AdvancedProgramming = strtok(NULL, ",");
            char *PuzzlesandProblemSolving = strtok(NULL, ",");

            // Get student average
            float sumResults = atof(IntrotoProgramming) + atof(Databases) + atof(ComputerArchitecture) + atof(EthicsinComputerScience) + atof(AdvancedProgramming) + atof(PuzzlesandProblemSolving);

            printf("\nStudent Name: %s\n", name);

            float averageR = sumResults / 6;
            printf("Average percentage: %.2f\n", averageR);
            // Call calucate GPA function
            gpaCal(averageR);
        }
    }
    fclose(file);
    return 0;
}

// Getting a students highest scoring module
int highestScoringModule(int i)
{
    FILE *file = fopen("CTASample.csv", "r");
    char line[256];

    int j = 0;
    while (fgets(line, sizeof(line), file)){
        j++;
        if(j == i)
        {
            char *name = strtok(line, ",");
            char *IntrotoProgramming = strtok(NULL, ",");
            char *Databases = strtok(NULL, ",");
            char *ComputerArchitecture = strtok(NULL, ",");
            char *EthicsinComputerScience = strtok(NULL, ",");
            char *AdvancedProgramming = strtok(NULL, ",");
            char *PuzzlesandProblemSolving = strtok(NULL, ",");

            int sumResults = atoi(IntrotoProgramming) + atoi(Databases) + atoi(ComputerArchitecture) + atoi(EthicsinComputerScience) + atoi(AdvancedProgramming) + atoi(PuzzlesandProblemSolving);

            int introP = atoi(IntrotoProgramming);
            int dataB = atoi(Databases);
            int compA = atoi(ComputerArchitecture);
            int Ethic = atoi(EthicsinComputerScience);
            int adP = atoi(AdvancedProgramming);
            int PuzzleP = atoi(PuzzlesandProblemSolving);

            // Array containing results
            int array[6];
            array[0] = introP;
            array[1] = dataB;
            array[2] = compA;
            array[3] = Ethic;
            array[4] = adP;
            array[5] = PuzzleP;

            // calculating highest scoring module
            int n = sizeof(array)/sizeof(array[0]);
            int highR = largest(array, n);
            int index = -1;
     
            for (int i = 0; i < n; i++) {
                if (array[i] == highR) {
                    index = i;
                    break;
                }
            }
            
            printf("\nHighest Scoring Module: ");
            printf(moduleNames[index]);
            printf(" %d", highR);
            printf("%%");
        }
    }
    fclose(file);
    return 0;
}

// Getting a students lowest scoring module
int lowestScoringModule(int i)
{
    FILE *file = fopen("CTASample.csv", "r");
    char line[256];

    int j = 0;
    while (fgets(line, sizeof(line), file)){
        j++;
        if(j == i)
        {
            char *name = strtok(line, ",");
            char *IntrotoProgramming = strtok(NULL, ",");
            char *Databases = strtok(NULL, ",");
            char *ComputerArchitecture = strtok(NULL, ",");
            char *EthicsinComputerScience = strtok(NULL, ",");
            char *AdvancedProgramming = strtok(NULL, ",");
            char *PuzzlesandProblemSolving = strtok(NULL, ",");

            int sumResults = atoi(IntrotoProgramming) + atoi(Databases) + atoi(ComputerArchitecture) + atoi(EthicsinComputerScience) + atoi(AdvancedProgramming) + atoi(PuzzlesandProblemSolving);

            int introP = atoi(IntrotoProgramming);
            int dataB = atoi(Databases);
            int compA = atoi(ComputerArchitecture);
            int Ethic = atoi(EthicsinComputerScience);
            int adP = atoi(AdvancedProgramming);
            int PuzzleP = atoi(PuzzlesandProblemSolving);

            // Array containing results
            int array[6];
            array[0] = introP;
            array[1] = dataB;
            array[2] = compA;
            array[3] = Ethic;
            array[4] = adP;
            array[5] = PuzzleP;

            // calculating lowest scoring module
            int n = sizeof(array)/sizeof(array[0]);
            int lowR = smallest(array, n);
            int index = -1;
     
            for (int i = 0; i < n; i++) {
                if (array[i] == lowR) {
                    index = i;
                    break;
                }
            }
            
            printf("\nLowest Scoring Module: ");
            printf(moduleNames[index]);
            printf(" %d", lowR);
            printf("%%");
        }
    }
    fclose(file);
    return 0;
}

// Standard deviation of a students results
int standardDeviation(int i)
{
    FILE *file = fopen("CTASample.csv", "r");
    char line[256];

    int j = 0;
    while (fgets(line, sizeof(line), file)){
        j++;
        if(j == i)
        {
            char *name = strtok(line, ",");
            char *IntrotoProgramming = strtok(NULL, ",");
            char *Databases = strtok(NULL, ",");
            char *ComputerArchitecture = strtok(NULL, ",");
            char *EthicsinComputerScience = strtok(NULL, ",");
            char *AdvancedProgramming = strtok(NULL, ",");
            char *PuzzlesandProblemSolving = strtok(NULL, ",");

            float introP = atof(IntrotoProgramming);
            float dataB = atof(Databases);
            float compA = atof(ComputerArchitecture);
            float Ethic = atof(EthicsinComputerScience);
            float adP = atof(AdvancedProgramming);
            float PuzzleP = atof(PuzzlesandProblemSolving);

            // Array containing results
            float array[6];
            array[0] = introP;
            array[1] = dataB;
            array[2] = compA;
            array[3] = Ethic;
            array[4] = adP;
            array[5] = PuzzleP;

            // Calculating standard Deviation
            int i;
            for(i = 0; i < 6; i++);
            printf("\nStandard deviation of results: %.3f", CSD(array));

        }
    }
    fclose(file);
    return 0;
}

// Median value of a students results 
int medianResult(int i){
    FILE *file = fopen("CTASample.csv", "r");
    char line[256];

    int j = 0;
    while (fgets(line, sizeof(line), file)){
        j++;
        if(j == i)
        {
            char *name = strtok(line, ",");
            char *IntrotoProgramming = strtok(NULL, ",");
            char *Databases = strtok(NULL, ",");
            char *ComputerArchitecture = strtok(NULL, ",");
            char *EthicsinComputerScience = strtok(NULL, ",");
            char *AdvancedProgramming = strtok(NULL, ",");
            char *PuzzlesandProblemSolving = strtok(NULL, ",");
            
            float introP = atof(IntrotoProgramming);
            float dataB = atof(Databases);
            float compA = atof(ComputerArchitecture);
            float Ethic = atof(EthicsinComputerScience);
            float adP = atof(AdvancedProgramming);
            float PuzzleP = atof(PuzzlesandProblemSolving);

            // Array containing results
            float array[6];
            array[0] = introP;
            array[1] = dataB;
            array[2] = compA;
            array[3] = Ethic;
            array[4] = adP;
            array[5] = PuzzleP;

            int b, k, n;
            float median, t;

            // Calculating median value
            for (b = 1; b <= 6-1; b++){
                for (k = 1; k <= 6-b; k++){
                    if(array[k] <= array[k+1]) {
                        t = array[k];
                        array[k] = array[k+1];
                        array[k+1] = t;
                    }
                    else
                    continue;
                }
            }

            if ( 6 % 2 == 0)
                median = (array[6/2] + array[6/2+1])/2.0 ;
            else
            median = array[6/2 + 1];

            printf("\nMedian of results is: %.1f\n", median);

        }
    }
    fclose(file);
    return 0;
}

// How far from the next highest GPA a student was, if not at 4.2 
int nextGPA(int i)
{
    FILE *file = fopen("CTASample.csv", "r");
    char line[256];

    int j = 0;
    while (fgets(line, sizeof(line), file)){
        j++;
        if(j == i)
        {
            char *name = strtok(line, ",");
            char *IntrotoProgramming = strtok(NULL, ",");
            char *Databases = strtok(NULL, ",");
            char *ComputerArchitecture = strtok(NULL, ",");
            char *EthicsinComputerScience = strtok(NULL, ",");
            char *AdvancedProgramming = strtok(NULL, ",");
            char *PuzzlesandProblemSolving = strtok(NULL, ",");

            int sumResults = atoi(IntrotoProgramming) + atoi(Databases) + atoi(ComputerArchitecture) + atoi(EthicsinComputerScience) + atoi(AdvancedProgramming) + atoi(PuzzlesandProblemSolving);

            int averageR = sumResults / 6;
            
            // Calculating how far a student is from the next GPA
            if (averageR >= 85  && averageR <=89){
                int nextGPApercent = 90 - averageR;
                printf("%d%% away from achieving a %.1f GPA", nextGPApercent, gpaVal[0]);
            } else if (averageR >= 80 && averageR <= 84){
                int nextGPApercent = 85 - averageR;
                printf("%d%% away from achieving a %.1f GPA", nextGPApercent, gpaVal[1]);
            } else if (averageR >= 75 && averageR <= 79){
                int nextGPApercent = 80 - averageR;
                printf("%d%% away from achieving a %.1f GPA", nextGPApercent, gpaVal[2]);
            } else if (averageR >= 70 && averageR <= 74){
                int nextGPApercent = 75 - averageR;
                printf("%d%% away from achieving a %.1f GPA", nextGPApercent, gpaVal[3]);
            } else if (averageR >= 65 && averageR <= 69){
                int nextGPApercent = 70 - averageR;
                printf("%d%% away from achieving a %.1f GPA", nextGPApercent, gpaVal[4]);
            } else if (averageR >= 60 && averageR <= 64){
                int nextGPApercent = 65 - averageR;
                printf("%d%% away from achieving a %.1f GPA", nextGPApercent, gpaVal[5]);
            } else if (averageR >= 55 && averageR <= 59){
                int nextGPApercent = 60 - averageR;
                printf("%d%% away from achieving a %.1f GPA", nextGPApercent, gpaVal[6]);
            } else if (averageR >= 50 && averageR <= 54){
                int nextGPApercent = 55 - averageR;
                printf("%d%% away from achieving a %.1f GPA", nextGPApercent, gpaVal[7]);
            } else if (averageR >= 45 && averageR <= 49){
                int nextGPApercent = 50 - averageR;
                printf("%d%% away from achieving a %.1f GPA", nextGPApercent, gpaVal[8]);
            } else if (averageR >= 40 && averageR <= 44){
                int nextGPApercent = 45 - averageR;
                printf("%d%% away from achieving a %.1f GPA", nextGPApercent, gpaVal[9]);
            } else if (averageR >= 35 && averageR <= 39){
                int nextGPApercent = 40 - averageR;
                printf("%d%% away from achieving a %.1f GPA", nextGPApercent, gpaVal[10]);
            } else if (averageR <= 35){
                int nextGPApercent = 35 - averageR;
                printf("%d%% away from achieving a %.1f GPA", nextGPApercent, gpaVal[11]);
            }
        }
    }
    fclose(file);
    return 0;
}

// Representing students results (percentage) as a grade letter i.e., A, B, C etc.,   
int moduleGradeLetter(int i)
{
    FILE *file = fopen("CTASample.csv", "r");
    char line[256];

    int j = 0;
    while (fgets(line, sizeof(line), file)){
        j++;
        if(j == i)
        {
            char *name = strtok(line, ",");
            char *IntrotoProgramming = strtok(NULL, ",");
            char *Databases = strtok(NULL, ",");
            char *ComputerArchitecture = strtok(NULL, ",");
            char *EthicsinComputerScience = strtok(NULL, ",");
            char *AdvancedProgramming = strtok(NULL, ",");
            char *PuzzlesandProblemSolving = strtok(NULL, ",");

            int sumResults = atoi(IntrotoProgramming) + atoi(Databases) + atoi(ComputerArchitecture) + atoi(EthicsinComputerScience) + atoi(AdvancedProgramming) + atoi(PuzzlesandProblemSolving);

            int introP = atoi(IntrotoProgramming);
            int dataB = atoi(Databases);
            int compA = atoi(ComputerArchitecture);
            int Ethic = atoi(EthicsinComputerScience);
            int adP = atoi(AdvancedProgramming);
            int PuzzleP = atoi(PuzzlesandProblemSolving);

            // Array containing results
            int array[6];
            array[0] = introP;
            array[1] = dataB;
            array[2] = compA;
            array[3] = Ethic;
            array[4] = adP;
            array[5] = PuzzleP;

            printf("\n\nList of modules and grade achieved:\n");

            int c;
            for(c = 0; c < 6; c++){
                printf(moduleNames[c]);
                printf("\n");
                gradeLetter(array[c]);
                printf("\n");
            }
            printf("\n");
            return 0;
            
        }
    }
    fclose(file);
    return 0;
}

//  While loop to iterate through the csv file
//  Call functions for each students i.e., i
int studentData(){  
    int i = 2;
    int numStudents = countStudents();

    while (i <= numStudents) {
        studentGPA(i);
        highestScoringModule(i);
        lowestScoringModule(i);
        standardDeviation(i);
        medianResult(i);
        nextGPA(i);
        moduleGradeLetter(i);
        i++;
    }
}

// Live mode a user can enter a set of marks and modules from the command line and have the program calculate their GPA.
int liveMode()
{
    printf("--- In live-Mode main menu ---\n");
    printf("* Please enter your result from each module in order to calculate your GPA *\n\n");

    int i;
    int entry;
    printf("Enter total number of modules taken: ");
    scanf("%d", &entry);

    char names[entry][30];
    int results[entry];

    for (i = 0; i < entry; i++){
        printf("Enter Module Name: ");
        scanf("%s", names[i]);
        printf("Enter Your Result (Percentage): ");
        scanf("%d", &results[i]);
    }

    printf("\nModules and results listed below\n");
    i=0;
    while (i < entry){
        printf("%s: %d%%\n", names[i], results[i]);
        i++;
    }

    int sum = 0;
    for (i = 0; i<entry; i++){
        sum = sum + results[i];
    }
    float averageR = sum / entry;
    printf("\nCalculated GPA value\n");
    gpaCal(averageR);
    printf("\n");
}


// menu: user interface.
int display_menu(){
    printf("\nAcademic Records");
    printf("\n%.*s", 16, "---------------------------------------------------------------------");

    printf("\nWelcome to the Main Menu");
    printf("\n%.*s", 24, "---------------------------------------------------------------------");
    printf("\n\n1 - View student academic reports\n");
    printf("2 - Enter Live-Mode (GPA Calculator)\n");
    printf("5 - Exit application\n");
    
}

// Call main function / menu functionality
int main()
{   
    int choice;
    while (true)
    {
        display_menu();
        printf("\nChoice: ");
        scanf("%d", &choice);
        if (choice == 5)
        {
            break;
        } else if (choice == 1)
        {
            studentData();
        } else if (choice == 2)
        {
            liveMode();
        } else{
            return 0;
        }
                
    }

    return 0;
    
}