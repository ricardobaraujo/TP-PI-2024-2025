# PI Project - Meal Ticket and Employee Management

## Description

This project, developed for the Introduction to Programming (Programação Imperativa) course at IPCA, is a C application for managing cafeteria operations including employees, weekly menus, and meal tickets. It provides a terminal-based interactive interface for creating, listing, and persisting data across sessions using text files.

## Features

- **Employee Management:** Add new employees (with ID, name, NIF, and phone number), list all employees in a formatted table, and check for duplicate IDs.
- **Menu Management:** Create weekly menus with four meal options per day (fish, meat, diet, and vegetarian) including calorie counts, and list all menus in a detailed table.
- **Meal Ticket Management:** Manage meal tickets associated with employees and menu entries.
- **File Persistence:** Read from and write to text files (`funcionarios.txt`, `ementas.txt`) using semicolon-delimited formats.
- **Terminal Interface:** Interactive menus with input validation for all operations.

## Project Structure

| File | Description |
|---|---|
| `main.c` | Entry point, main loop, menus, and CRUD operations for employees and menus |
| `profunc.h` | Header file with struct definitions, constants, and function prototypes |
| `profunc.c` | Utility functions (input reading, duplicate checking, display helpers) |
| `funcionarios.txt` | Employee data file (semicolon-delimited) |
| `ementas.txt` | Weekly menu data file (semicolon-delimited) |
| `makefile` | Build automation |

## Data Structures

- **`dados_func`** - Employee record: ID, name, NIF, phone number.
- **`dados_ementa`** - Menu entry: day of the week, date, four dish options (fish, meat, diet, vegetarian) each with calorie count.
- **`dados_senha`** - Meal ticket: ID, day of the week, selected dish.

## Building

To build and run the project, use the provided `makefile`:

```sh
make
