# Initial Reason for Building
This project began as a self-study initiative during winter break in 2023, in preparation for upcoming my Data Structures and Algorithms class. Often times, while studying I will listen to the cult classic lofi-girl on YouTube. One fateful day, I was targeted with suggestion for an interestingly named and aptly timed video, "sorting algorithms to relax/study to." This video would serve as the inspiration for the following project. 

SortViz is currently limited to console output, I aim to implement a GUI in the future. Some ongoing challenges include optimizing the visualization for larger arrays and improving user interaction.

This project was built before I had access to version control, so you will be able to peer into my thought process between iterations. You'll no doubt note my exceedingly obnoxious commented out sections that identify the problems I was running into and the direction I wanted the project to go.

Curious about the beautiful monstrosity that inspired this project?: 
https://www.youtube.com/watch?v=vr5dCRHAgb0

# SortViz

SortViz is a sorting algorithm visualizer written in C++. It allows users to input their own array and visualize various sorting algorithms, such as Bubble Sort, Quick Sort, and Merge Sort. The tool is designed to help users understand the sorting process step by step.

## Features
- Visualizes multiple sorting algorithms.
- User inputs array data and selects the sorting algorithm to visualize.
- Displays sorting statistics including total swaps, steps taken, and ratios.

## Installation
1. Clone the repository:
    ```bash
    git clone https://github.com/aspirebyjare/sortviz.git
    ```
2. Compile the project using g++:
    ```bash
    g++ v4Main.cpp -o sortviz
    ```

## Usage
1. Run the executable:
    ```bash
    ./sortviz
    ```
2. Follow the on-screen instructions to enter an array and select a sorting algorithm to visualize.

## Built With
- C++