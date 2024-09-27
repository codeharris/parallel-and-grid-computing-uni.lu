#include <iostream>
#include <random>
#include <vector>
#include <thread>

std::vector<int> initialize_cells(size_t n)
{
    std::vector<int> cells(n);
    // std::mt19937 m{std::random_device{}()};
    std::mt19937 m{0}; // fix the seed to ease debugging.
    std::uniform_int_distribution<int> u{0, 1};
    for (int i = 0; i < cells.size(); ++i)
    {
        cells[i] = u(m);
    }
    return std::move(cells);
}

void print(const std::vector<int> &cells)
{
    for (auto cell : cells)
    {
        std::cout << cell;
    }
    std::cout << std::endl;
}

// You write the simulation in a loop using two arrays of cells (the current array and the next array).

void simulate_step(const std::vector<int>& current, std::vector<int>& next)
{
 size_t size = current.size();
    for (size_t i = 0; i < size; ++i) {
        int left = current[(i - 1 + size) % size];  
        int center = current[i];
        int right = current[(i + 1) % size];

        // Move car if there is space ahead
        if (center == 1 && right == 0) {
            next[i] = 0;         // The car leaves the current cell
            next[(i + 1) % size] = 1; // The car moves to the next cell
        } else if (center == 0 && left == 1) {
            next[i] = 1; // The car enters from the left
        } else {
            next[i] = center; // Otherwise, state stays the same
        }
    }   
}

// Function to find the longest sequence of consecutive '1's in the cells
int find_longest_ones(const std::vector<int>& cells) {
    int max_length = 0;  // To store the maximum length of consecutive '1's
    int current_length = 0;

    for (size_t i = 0; i < cells.size(); ++i) {
        if (cells[i] == 1) {
            current_length++; // Increment the length of consecutive '1's
            if (current_length > max_length) {
                max_length = current_length; // Update max length if needed
            }
        } else {
            current_length = 0; // Reset if the sequence is broken
        }
    }
    return max_length;
}

// Main function to run the simulation for a given number of steps
void simulate(size_t steps, std::vector<int>& current, std::vector<int>& next) {
    int max_longest_ones = 0;  // Variable to store the overall longest sequence

    for (size_t step = 0; step < steps; ++step) {
        print(current);  // Print the current state of cells
        simulate_step(current, next); // Calculate the next state

        int longest_ones = find_longest_ones(current); // Find the longest sequence of '1's
        if (longest_ones > max_longest_ones) {
            max_longest_ones = longest_ones; // Update the overall longest sequence
        }

        std::this_thread::sleep_for(std::chrono::seconds(1)); // Pause for 1 second
        current.swap(next); // Swap the arrays for the next iteration
    }

    // Output the overall longest sequence of '1's
    std::cout << "The longest traffic jam (consecutive 1's) during the simulation was: " 
              << max_longest_ones << " cars long." << std::endl;
}

int main(int argc, char **argv)
{
    using namespace std::chrono_literals;
    std::mt19937 m{0};
    std::uniform_int_distribution<int> u{0, 1};
    size_t n = 50;
    size_t steps = 10;
    std::vector<int> cells = initialize_cells(n);

    // Initialize the arrays: 'current' holds the current state, 'next' holds the future state
    std::vector<int> current = initialize_cells(n);
    std::vector<int> next(n, 0);

    simulate(steps, current, next); // Run the simulation

    print(cells);

    /** Notes:
     * `std::this_thread::sleep_for(1000ms);` sleeps the program for 1 second.
     * `u(m)` randomly generates either 0 or 1 following a uniform distribution.
     * You can use `u(m)` to generate whether a car enters the queue (cells[0]) at the current step.
     */
    return 0;
}
