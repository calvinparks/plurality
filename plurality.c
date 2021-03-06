#include <cs50.h>
#include <stdio.h>
#include <string.h>


// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Temporary Array of candidates
candidate tmp_candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

// used to determine if there are more than one winner
int first_winner_vote_count;

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }


    
    
    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string candidate_selected)
{
   
    
    // look for candidate called name
    for (int j = 0; j < candidate_count; j++)
    {
        if (strcmp(candidates[j].name, candidate_selected) == 0)
        {
            candidates[j].votes++;  
            return true;
        }
    }
   
    // if no cadidtate found just retrun false
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    for (int k = 1; k < candidate_count; k++)
    {
        for (int l = 0; l < candidate_count - k; l++)
        {
            if (candidates[l].votes < candidates[l + 1].votes) 
            {
                tmp_candidate = candidates[l];
                candidates[l] = candidates[l + 1];
                candidates[l + 1] = tmp_candidate;
            }
        }
    }
    
    first_winner_vote_count = candidates[0].votes;
    for (int m = 0; m < candidate_count; m++) 
    {
        if (candidates[m].votes == first_winner_vote_count) 
        {
            //printf("%s == %i\n",candidates[m].name,candidates[m].votes);
            printf("%s\n", candidates[m].name);
        }
    }
    return;
}

