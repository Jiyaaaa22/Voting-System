#include <stdio.h>
#include <string.h>
	
#define CANDIDATE_COUNT 4

#define CANDIDATE1 "Suresh"
#define CANDIDATE2 "Tushar"
#define CANDIDATE3 "Jim"
#define CANDIDATE4 "Rakesh"

int votesCount1 = 0, votesCount2 = 0, votesCount3 = 0, votesCount4 = 0, spoiledVotes = 0;

// Function to authenticate the user
int authenticateUser() {
    char username[20];
    char password[20];

    printf("\n\n ### Login ###\n\n");
    printf(" Enter username: ");
    scanf("%s", username);

    printf(" Enter password: ");
    scanf("%s", password);

    // Simple authentication (replace with a secure authentication mechanism in a real-world scenario)
    if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0) {
        printf(" Login successful!\n");
        return 1;  // Successful login
    } else {
        printf(" Login failed. Invalid credentials.\n");
        return 0;  // Failed login
    }
}

// Function to cast a vote
void castVote() {
    int choice;
    printf("\n\n ### Please choose your Candidate ####\n\n");
    printf(" 1. %s\n", CANDIDATE1);
    printf(" 2. %s\n", CANDIDATE2);
    printf(" 3. %s\n", CANDIDATE3);
    printf(" 4. %s\n", CANDIDATE4);
    printf(" 5. %s\n", "None of These");

    printf("\n Input your choice (1 - 5): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: votesCount1++; break;
        case 2: votesCount2++; break;
        case 3: votesCount3++; break;
        case 4: votesCount4++; break;
        case 5: spoiledVotes++; break;
        default: printf("\n Error: Wrong Choice !! Please retry");
    }
    printf("\n Thanks for your vote!");
}

// Function to display voting results
void votesCount() {
    printf("\n\n Voting Result");
    printf("\n %s - %d ", CANDIDATE1, votesCount1);
    printf("\n %s - %d ", CANDIDATE2, votesCount2);
    printf("\n %s - %d ", CANDIDATE3, votesCount3);
    printf("\n %s - %d ", CANDIDATE4, votesCount4);
    printf("\n %s - %d ", "Spoiled Votes", spoiledVotes);
}

// Function to determine the leading candidate
void getLeadingCandidate() {
    printf("\n\n  #### Leading Candidate ####\n\n");
    if (votesCount1 > votesCount2 && votesCount1 > votesCount3 && votesCount1 > votesCount4)
        printf("[%s]", CANDIDATE1);
    else if (votesCount2 > votesCount3 && votesCount2 > votesCount4 && votesCount2 > votesCount1)
        printf("[%s]", CANDIDATE2);
    else if (votesCount3 > votesCount4 && votesCount3 > votesCount2 && votesCount3 > votesCount1)
        printf("[%s]", CANDIDATE3);
    else if (votesCount4 > votesCount1 && votesCount4 > votesCount2 && votesCount4 > votesCount3)
        printf("[%s]", CANDIDATE4);
    else
        printf("----- Warning !!! No-win situation ----");
}

// Function to save voting results to a file
void saveVotingResultsToFile() {
    FILE *file = fopen("voting_results.txt", "w");
    if (file != NULL) {
        fprintf(file, "Voting Results\n");
        fprintf(file, "%s - %d\n", CANDIDATE1, votesCount1);
        fprintf(file, "%s - %d\n", CANDIDATE2, votesCount2);
        fprintf(file, "%s - %d\n", CANDIDATE3, votesCount3);
        fprintf(file, "%s - %d\n", CANDIDATE4, votesCount4);
        fprintf(file, "Spoiled Votes - %d\n", spoiledVotes);
        fclose(file);
        printf("\n Voting results saved to voting_results.txt\n");
    } else {
        printf("Error: Could not save voting results to file.\n");
    }
}


int main() {
    int choice;
    int isLoggedIn = 0;

    do {
        if (!isLoggedIn) {
            isLoggedIn = authenticateUser();
            if (!isLoggedIn) {
                continue;  // Re-prompt for login if unsuccessful
            }
        }

        printf("\n\n ###### Welcome to Election/Voting 2024 #####");
        printf("\n 1. Cast the Vote");
        printf("\n 2. Find Vote Count");
        printf("\n 3. Find Leading Candidate");
        printf("\n 4. Save Voting Results to File");
        printf("\n 0. Exit");
	
        printf("\n\n Please enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: castVote(); break;
            case 2: votesCount(); break;
            case 3: getLeadingCandidate(); break;
            case 4: saveVotingResultsToFile(); break;
            case 0: printf("\n Exiting the program...\n"); break;
            default: printf("\n Error: Invalid Choice");
        }
    } while (choice != 0);

    return 0;
}
