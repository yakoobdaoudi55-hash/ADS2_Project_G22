#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float score;
    char category[20];
} Record;

/* Display records in table format */
void displayDataset(Record arr[], int count) {

    int i;

    printf("%-5s %-20s %-8s %-15s\n", "ID", "Name", "Score", "Category");
    printf("------------------------------------------------\n");

    for (i = 0; i < count; i++) {

        // print each structure as a formatted row
        printf("%-5d %-20s %-8.2f %-15s\n",
               arr[i].id,
               arr[i].name,
               arr[i].score,
               arr[i].category);
    }
}

/* Compute average score */
float averageByField(Record arr[], int count) {

    float sum = 0.0f;
    int i;

    // avoid division by zero
    if (count == 0)
        return 0.0f;

    // accumulate all scores
    for (i = 0; i < count; i++) {
        sum += arr[i].score;
    }

    return sum / count;
}

/* Load records from binary file */
int loadDataset(const char* filename, Record arr[], int* count) {

    FILE* fp = fopen(filename, "rb");

    // check if file opening failed
    if (!fp)
        return -1;

    *count = 0;

    // read structures one by one until EOF
    while (fread(&arr[*count], sizeof(Record), 1, fp) == 1) {

        // increment count after successful read
        (*count)++;
    }

    fclose(fp);
    return 0;
}

/* Find lowest score */
Record findMinByField(Record arr[], int count) {

    int i;

    // assume first record is minimum initially
    Record min = arr[0];

    for (i = 1; i < count; i++) {

        // replace minimum if smaller score found
        if (arr[i].score < min.score) {
            min = arr[i];
        }
    }

    return min;
}

/* Save records to binary report */
int saveBinaryReport(const char* filename, Record arr[], int count) {

    FILE* fp = fopen(filename, "wb");
    int i;

    // verify file creation
    if (!fp)
        return -1;

    for (i = 0; i < count; i++) {

        // write one structure at a time into binary file
        fwrite(&arr[i], sizeof(Record), 1, fp);
    }

    fclose(fp);
    return 0;
}

/* Sort dataset using selected field */
void sortDatasetByField(Record arr[], int count, char* field) {

    int i, j;
    Record temp;

    // Bubble Sort algorithm
    for (i = 0; i < count - 1; i++) {

        for (j = 0; j < count - i - 1; j++) {

            int needSwap = 0;

            // compare scores
            if (strcmp(field, "score") == 0) {

                if (arr[j].score > arr[j + 1].score)
                    needSwap = 1;
            }

            // compare names alphabetically
            else if (strcmp(field, "name") == 0) {

                if (strcmp(arr[j].name, arr[j + 1].name) > 0)
                    needSwap = 1;
            }

            // compare IDs numerically
            else if (strcmp(field, "id") == 0) {

                if (arr[j].id > arr[j + 1].id)
                    needSwap = 1;
            }

            // exchange records if needed
            if (needSwap) {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/* Get highest score record */
Record findMaxByField(Record arr[], int count) {

    int i;

    // start by assuming first element is maximum
    Record max = arr[0];

    for (i = 1; i < count; i++) {

        // update maximum if bigger score found
        if (arr[i].score > max.score) {
            max = arr[i];
        }
    }

    return max;
}

/* Filter records by threshold */
int filterByCondition(Record arr[], int count, float threshold, Record out[]) {

    int i;
    int total = 0;

    for (i = 0; i < count; i++) {

        // copy only records satisfying condition
        if (arr[i].score > threshold) {

            out[total] = arr[i];
            total++;
        }
    }

    // return number of copied records
    return total;
}

/* Main Program */
int main() {

    Record dataset[100];
    Record filtered[100];

    int count = 0;
    int i;

    /* Create sample dataset */
    FILE* fp = fopen("students.dat", "wb");

    if (fp) {

        Record samples[] = {

            {1, "Alice",   85.5f, "Science"},
            {2, "Bob",     72.0f, "Math"},
            {3, "Charlie", 91.0f, "Science"},
            {4, "Diana",   60.5f, "Arts"},
            {5, "Eve",     78.0f, "Math"}

        };

        for (i = 0; i < 5; i++) {

            // save each structure into file
            fwrite(&samples[i], sizeof(Record), 1, fp);
        }

        fclose(fp);
    }

    /* Read dataset */
    if (loadDataset("students.dat", dataset, &count) == -1) {

        printf("Error loading dataset.\n");
        return 1;
    }

    printf("=== DATASET ANALYSIS REPORT ===\n\n");

    printf("-- Original Records --\n");
    displayDataset(dataset, count);

    printf("\n-- Sorted Dataset By Score --\n");

    // sort array using score field
    sortDatasetByField(dataset, count, "score");

    displayDataset(dataset, count);

    Record maxRecord = findMaxByField(dataset, count);
    Record minRecord = findMinByField(dataset, count);

    printf("\nHighest Score : %s (%.2f)\n",
           maxRecord.name,
           maxRecord.score);

    printf("Lowest Score  : %s (%.2f)\n",
           minRecord.name,
           minRecord.score);

    printf("Average Score : %.2f\n",
           averageByField(dataset, count));

    int filteredCount =
        filterByCondition(dataset, count, 75.0f, filtered);

    printf("\n-- Filtered Records (>75) : %d found --\n",
           filteredCount);

    displayDataset(filtered, filteredCount);

    // save filtered dataset into another file
    if (saveBinaryReport("report.dat", filtered, filteredCount) == 0) {

        printf("\nFiltered report saved successfully.\n");
    }

    return 0;
}
