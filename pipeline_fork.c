//Code Skeleton: Look for ToDo tasks 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define NUM_INTEGERS 10 // Number of integers to take from the user

// Function for the Data Producer
void data_producer(int write_fd) {
    int numbers[NUM_INTEGERS]; // Array to hold user input
    printf("Enter %d integers (space-separated): ", NUM_INTEGERS);
       // ToDo:Take user input
         // ToDo: Write to the pipe
        printf("Producer: sent integer %d\n", numbers[i]);
    }
     // ToDo: Close the write end after sending all integers
}

// Function for the Data Processor
void data_processor(int read_fd, int write_fd) {
    int number;
     // Read from the pipe
         // ToDo:Square the integer
         // ToDo:Write the squared value to the next pipe
        printf("Processor: processed integer square %d to %d\n", number, squared);
    }
      // ToDo:Close the read end when done
     // ToDo:Close the write end when done
}

// Function for the Data Consumer
void data_consumer(int read_fd) {
    int squared;
    while (//ToDo) { // Read processed data
        printf("Consumer: received squared value %d\n", squared); // Print the result
    }
     // ToDo:Close the read end when done
}

int main() {
     //ToDo: Pipe for producer to processor
     //ToDo: Pipe for processor to consumer

    // ToDo:Create the first pipe

    // ToDo:Create the second pipe
    
    // ToDo:Create the Data Producer process
    pid_t producer_pid = fork();
    if (producer_pid < 0) {
        //ToDo:Error messge
    }
    if (producer_pid == 0) {
         // ToDo: Close the read end of the first pipe
         // ToDo:Call producer function
        exit(EXIT_SUCCESS);
    }

    // ToDo: Create the Data Processor process similar to Producer
    

    // ToDo:Create the Data Consumer process in the main process
     // ToDo:Close the read end of the first pipe
     // ToDo:Close the write end of the first pipe
     // ToDo:Close the write end of the second pipe
     // ToDo:Call consumer function

    // ToDo:Wait for child processes to complete
     // ToDo:Wait for producer
     // ToDo:Wait for processor

    return 0; // End of the program
}
