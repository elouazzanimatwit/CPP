#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int base;  // Base address for the segment
    int limit; // Limit of the segment
} MemorySegment;

// Function to translate logical address to physical address
int translateAddress(MemorySegment segment, int logicalAddress) {
    if (logicalAddress < 0 || logicalAddress >= segment.limit) {
        printf("Error: Segmentation Fault - Invalid Logical Address\n");
        return -1; // Indicate error
    }
    return segment.base + logicalAddress; // Calculate physical address
}

// Function to check if a process can be allocated memory
int canAllocate(int size, MemorySegment segment, int allocated) {
    return (allocated + size) <= segment.limit; // Check if size can be allocated
}

int main() {
    MemorySegment segment;

    // Take user input for base and limit
    printf("Enter base address: ");
    scanf("%d", &segment.base);
    printf("Enter limit (in bytes): ");
    scanf("%d", &segment.limit);

    // Allocate memory for process sizes
    int *processSizes = (int *)malloc(segment.limit * sizeof(int)); // Allocate maximum for process sizes
    if (processSizes == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    int numProcesses;
    printf("Enter number of processes: ");
    scanf("%d", &numProcesses);

    // Store sizes of processes and track allocated memory
    int totalAllocated = 0;
    int fragmentedMemory = segment.limit; // Initially, fragmented memory is the entire limit

    printf("Enter sizes of %d processes (in bytes):\n", numProcesses);
    for (int i = 0; i < numProcesses; i++) {
        printf("Size of process %d: ", i + 1);
        scanf("%d", &processSizes[i]);

        // Check if we can allocate memory for this process
        if (canAllocate(processSizes[i], segment, totalAllocated)) {
            int logicalAddress = totalAllocated; // Current logical address is the total allocated size
            totalAllocated += processSizes[i]; // Add size to total allocated
            fragmentedMemory -= processSizes[i]; // Reduce fragmented memory
            
            // Calculate the physical address
            int physicalAddress = translateAddress(segment, logicalAddress);
            printf("Process %d of size %d bytes allocated successfully. Physical Address: %d\n", 
                   i + 1, processSizes[i], physicalAddress);
        } else {
            printf("Process %d of size %d bytes cannot be allocated due to insufficient memory. \nRemaining unassigned memory: %d bytes\n", 
                   i + 1, processSizes[i], fragmentedMemory);
        }
    }

    // Report total allocated and fragmentation
    printf("\nTotal allocated memory: %d bytes\n", totalAllocated);
    printf("Fragmented memory left (remaining unassigned memory): %d bytes\n", fragmentedMemory);

    // Free allocated memory
    free(processSizes);
    return 0;
}
