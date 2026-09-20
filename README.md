# Portland Request Searching Tool

## Overview

This project is a C++ program that reads service request data from a `.txt` file containing Portland service requests (such as potholes, graffiti removal, broken streetlights), and help users quickly search and manage service records using a Binary Search Tree (BST). 

The goal is to practice writing a program by C++ to read an external file, implementing Binary Search Tree data structure to manage a large dataset, supporting insert, search, remove, display, and remove all data using program.

## Dataset

The dataset contains information such as:

- request ID
- request type
- Neighborhood/District
- Street
- Priority
- Status
- Date Created
- Agency/Department
- Description

The file `service_requests_10000.txt` cotains roughly 10,000 requests records.

The file `test.txt` is a smaller mock dataset containing 50 requests recoreds.

## Tools

- C++
- Table ADT (Abstract Data Type)
- Binary Search Tree (Data Structure)
- File I/O operations

# How to Run

1. Clone this repository.
2. Place all the files are located in the same folder.
3. Compile all of `.cpp` files.
4. When prompted, enter the exact name of the text file, including the file extension, to load the dataset.