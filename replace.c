#include <stdio.h>
#include <stdbool.h>

#define FRAME_SIZE 2  // Number of frames

// Function to check if a page is in the frame
bool isPageInFrame(int frame[], int page) {
    for (int i = 0; i < FRAME_SIZE; i++) {
        if (frame[i] == page) {
            return true;
        }
    }
    return false;
}

// Function to print the current frame
void printFrame(int frame[]) {
    for (int j = 0; j < FRAME_SIZE; j++) {
        if (frame[j] != -1) {
            printf("%d ", frame[j]);
        } else {
            printf("- "); // Print '-' for empty frames
        }
    }
}

// Function to print table header
void printTableHeader() {
    printf("+-------+--------------------+--------------------+\n");
    printf("|  Page |   Current Frame    |     Page Fault     |\n");
    printf("+-------+--------------------+--------------------+\n");
}

// Function to print table row
void printTableRow(int page, int frame[], bool fault) {
    printf("| %5d | ", page);
    printFrame(frame);
    printf(" | %s                  |\n", fault ? "Yes" : "No ");
}

// Optimal Page Replacement Algorithm
void optimalPageReplacement(int pages[], int n) {
    int frame[FRAME_SIZE] = {-1, -1}; // Initialize frame
    int pageFaults = 0;

    printf("\nOptimal Page Replacement:\n");
    printTableHeader();

    for (int i = 0; i < n; i++) {
        bool fault = false; // Track if a fault occurred
        if (!isPageInFrame(frame, pages[i])) {
            // Page fault occurs
            fault = true;
            pageFaults++;
            
            // If frame is not full, add the page
            if (frame[0] == -1) {
                frame[0] = pages[i];
            } else if (frame[1] == -1) {
                frame[1] = pages[i];
            } else {
                // Find the page to replace
                int replaceIndex = -1;
                int farthest = i;

                for (int j = 0; j < FRAME_SIZE; j++) {
                    // Find the page that will not be used for the longest time
                    int k;
                    for (k = i + 1; k < n; k++) {
                        if (frame[j] == pages[k]) {
                            break;
                        }
                    }
                    if (k > farthest) {
                        farthest = k;
                        replaceIndex = j;
                    }
                }
                // Replace the page
                frame[replaceIndex] = pages[i];
            }
        }
        // Print current frame status in the table
        printTableRow(pages[i], frame, fault);
    }
    printf("+-------+--------------------+--------------------+\n");
    printf("Total Page Faults (Optimal): %d\n", pageFaults);
}

// FIFO Page Replacement Algorithm
void fifoPageReplacement(int pages[], int n) {
    int frame[FRAME_SIZE] = {-1, -1}; // Initialize frame
    int pageFaults = 0;
    int nextFrameToReplace = 0; // Start with 0 instead of -1 for cyclic replacement

    printf("\nFIFO Page Replacement:\n");
    printTableHeader();

    for (int i = 0; i < n; i++) {
        bool fault = false; // Track if a fault occurred
        if (!isPageInFrame(frame, pages[i])) {
            // Page fault occurs
            fault = true;
            pageFaults++;

            // If frame is not full, add the page
            if (frame[0] == -1) {
                frame[0] = pages[i];
                nextFrameToReplace = 1; // Set next frame index for replacement
            } else if (frame[1] == -1) {
                frame[1] = pages[i];
                nextFrameToReplace = 0; // Set next frame index for replacement
            } else {
                // Replace the next frame in FIFO order
                frame[nextFrameToReplace] = pages[i];
                nextFrameToReplace = (nextFrameToReplace + 1) % FRAME_SIZE; // Cycle between 0 and 1
            }
        }
        // Print current frame status in the table
        printTableRow(pages[i], frame, fault);
    }
    printf("+-------+--------------------+--------------------+\n");
    printf("Total Page Faults (FIFO): %d\n", pageFaults);
}

// LRU Page Replacement Algorithm
void lruPageReplacement(int pages[], int n) {
    int frame[FRAME_SIZE] = {-1, -1}; // Initialize frame
    int pageFaults = 0;

    printf("\nLRU Page Replacement:\n");
    printTableHeader();

    for (int i = 0; i < n; i++) {
        bool fault = false; // Track if a fault occurred
        if (!isPageInFrame(frame, pages[i])) {
            // Page fault occurs
            fault = true;
            pageFaults++;

            // If frame is not full, add the page
            if (frame[0] == -1) {
                frame[0] = pages[i];
            } else if (frame[1] == -1) {
                frame[1] = pages[i];
            } else {
                // Find the LRU page
                int lruIndex = 0; // Start with the first frame
                for (int j = 0; j < FRAME_SIZE; j++) {
                    if (frame[j] != -1) {
                        for (int k = i - 1; k >= 0; k--) {
                            if (frame[j] == pages[k]) {
                                lruIndex = j; // Found a page that is still in the future
                                break;
                            }
                        }
                    }
                }
                // Replace the LRU page
                frame[lruIndex] = pages[i];
            }
        }
        // Print current frame status in the table
        printTableRow(pages[i], frame, fault);
    }
    printf("+-------+--------------------+--------------------+\n");
    printf("Total Page Faults (LRU): %d\n", pageFaults);
}

int main() {
    int n;

    // Get the number of pages from the user
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    
    int pages[n];

    // Get the page reference string from the user
    printf("Enter the page reference string (space-separated): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    optimalPageReplacement(pages, n);
    fifoPageReplacement(pages, n);
    lruPageReplacement(pages, n);

    return 0;
}
