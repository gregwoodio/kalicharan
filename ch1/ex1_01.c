/*
 * Data Structures in C by Noel Kalicharan
 * Chapter 1, exercise 1
 *
 * A survey of 10 pop artists is made. Each person votes for an artist by
 * specifying the number of the artist (a value from 1 to 10). Each voter
 * is allowed one vote for the artist or his/her choice. The vote is 
 * recorded as a number from 1 to 10. The number of voters is unknown 
 * beforehand but the votes are terminated by a vote of 0. Any vote which
 * is not a number from 1 to 10 is a spoilt vote.
 * A file, votes.txt, contains the names of the candidates. The first name
 * is considered as candidate 1, the second as candidate 2, and so on. The
 * names are followed by the votes. Write a program to read the data and
 * evaluate the results of the survey.
 * Print the results in alphabetical order by artist name and in order by 
 * votes received (most votes first). Print all output to the file, 
 * results.txt.
 */

#include <stdio.h>
#include <stdlib.h>

#define MaxCandidates 10
#define MaxNameLength 30

typedef struct {
    char name[MaxNameLength + 1];
    int numVotes;
} ArtistData;

typedef struct {
    int valid, spoilt;
} VoteCount;

void initialize(ArtistData artists[], int max, FILE *in);
VoteCount processVotes(ArtistData artists[], int max, FILE *in, FILE *out);
int getLargest(ArtistData artists[], int lo, int hi);
void printResults(ArtistData artists[], int max, VoteCount c, FILE *out);
void sortByVote(ArtistData artists[], int lo, int hi);
void sortByName(ArtistData artists[], int lo, int hi);

int main() {
    ArtistData artists[MaxCandidates + 1];
    VoteCount count;
    FILE *in = fopen("votes.txt", "r");
    FILE *out = fopen("results.txt", "w");

    initialize(artists, MaxCandidates, in);
    count = processVotes(artists, MaxCandidates, in, out);
    printResults(artists, MaxCandidates, count, out);

    fclose(in);
    fclose(out);
}

void initialize(ArtistData artists[], int max, FILE *in) {
    char name[MaxNameLength];
    int j, k;
    for (j = 1; j <= max; j++) {
        fgets(artists[j].name, MaxNameLength, in);
        for (k = 0; artists[j].name[k] != '\0'; k++) {
            if (artists[j].name[k] == '\n') artists[j].name[k] = '\0';
        }
        artists[j].numVotes = 0;
    }
}

VoteCount processVotes(ArtistData artists[], int max, FILE *in, FILE *out) {
    int v;
    VoteCount tmp;
    tmp.valid = tmp.spoilt = 0;
    fscanf(in, "%d", &v);
    while (v != 0) {
        if (v < 1 || v > max) {
            fprintf(out, "Invalid vote: %d\n", v);
            ++tmp.spoilt;
        } else {
            ++artists[v].numVotes;
            ++tmp.valid;
        }
        fscanf(in, "%d", &v);
    }
    return tmp;
}

int getLargest(ArtistData artists[], int lo, int hi) {
    int j, big = lo;
    for (j = lo + 1; j <= hi; j++) {
        if (artists[j].numVotes > artists[big].numVotes) {
            big = j;
        }
    }
    return big;
}

void printResults(ArtistData artists[], int max, VoteCount c, FILE *out) {
    int j;
    fprintf(out, "\nNumber of voters: %d\n", c.valid + c.spoilt);
    fprintf(out, "Number of valid voters: %d\n", c.valid);
    fprintf(out, "Number of spoilt votes: %d\n", c.spoilt);

    sortByVote(artists, 1, MaxCandidates);
    fprintf(out, "\nBy Score");
    fprintf(out, "\n%-15s\tScore\n\n", "Artist");
    for (j = 1; j <= max; j++) {
        fprintf(out, "%-15s %3d\n", artists[j].name, artists[j].numVotes);
    }

    sortByName(artists, 1, MaxCandidates);
    fprintf(out, "\nBy Name");
    fprintf(out, "\n%-15s\tScore\n\n", "Artist");
    for (j = 1; j <= max; j++) {
        fprintf(out, "%-15s %3d\n", artists[j].name, artists[j].numVotes);
    }
    
    fprintf(out, "\nThe Winner(s)\n");
    int win = getLargest(artists, 1, max);
    int winningVote = artists[win].numVotes;

    for (j = 1; j <= max; j++) {
        if (artists[j].numVotes == winningVote) {
            fprintf(out, "%s\n", artists[j].name);
        }
    }
}

void sortByVote(ArtistData artists[], int lo, int hi) {
    int j, k;
    ArtistData insertItem;
    for (j = lo + 1; j <= hi; j++) {
        insertItem = artists[j];
        k = j - 1;
        while (k >= lo && insertItem.numVotes > artists[k].numVotes) {
            artists[k + 1] = artists[k];
            --k;
        }
        artists[k + 1] = insertItem;
    }
}

void sortByName(ArtistData artists[], int lo, int hi) {
    int j, k;
    ArtistData insertItem;
    for (j = lo + 1; j <= hi; j++) {
        insertItem = artists[j];
        k = j - 1;
        while (k >= lo && strcmp(insertItem.name, artists[k].name) < 0) {
            artists[k + 1] = artists[k];
            --k;
        }
        artists[k + 1] = insertItem;
    }
}
