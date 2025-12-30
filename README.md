ZenVault 
A High-Performance Dynamic Resource Manager developed in C.

📖 About The Project
ZenVault is a Command Line Interface (CLI) tool designed to manage large datasets of inventory items (resources) with high efficiency.

Inspired by the complex inventory systems found in modern RPGs (like Genshin Impact), this project focuses on the systems engineering side of game development: efficient memory management. Instead of using static arrays, ZenVault utilizes dynamic memory allocation to scale its capacity in real-time based on user input.

This project was built to demonstrate proficiency in:

Pointers & Memory Addressing

Dynamic Allocation (malloc, realloc, free)

Data Structures (struct)

CRUD Operations

⚙️ Technical Key Features
Dynamic Scalability: The system starts with a small memory footprint. Using realloc(), it doubles its capacity automatically when the limit is reached, ensuring optimal memory usage (Geometric Expansion Strategy).

Leak-Free Design: Implements a strict freeMemory() protocol to ensure zero memory leaks upon program termination.

Structured Data: Uses custom typedef struct to simulate complex objects with mixed data types (Integers, Strings, Floats).

User Interface: A clean, looped CLI menu for seamless interaction.

🛠️ Installation & Usage
This project is optimized for Linux (Ubuntu/WSL) environments.

Prerequisites
GCC Compiler

Build Steps
Clone the Repository

Bash

git clone https://github.com/yourusername/zenvault.git
cd zenvault
Compile the Source Code

Bash

gcc zenvault.c -o zenvault
Run the Application

Bash

./zenvault
💻 Code Snippet Highlight
Demonstrating dynamic memory resizing:

C

// When inventory is full, double the capacity
if (itemCount == capacity) {
    capacity *= 2;
    inventory = (Item*)realloc(inventory, capacity * sizeof(Item));
    
    if (inventory == NULL) {
        // Error handling for safe crash
        printf("Memory Re-allocation Failed\n");
        exit(1);
    }
}
🚀 Future Roadmap
[ ] Implement File I/O to save/load inventory to .csv.

[ ] Add QuickSort algorithm to sort items by Rarity/Power.

[ ] Add a search function to find items by ID or Name.

👨‍💻 Author
Anand Mohan Kumar

Computer Science Student @ Guru Ghasidas Vishwavidyalaya

Interest Areas: Systems Programming, Game Development, Open Source.