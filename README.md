# Go Fish C++

[![C++17](https://img.shields.io/badge/Standard-C%2B%2B17-blue.svg)](https://isocpp.org/std/the-standard)

---

## Table of Contents

1. [Overview](#overview)  
2. [Features](#features)  
3. [Prerequisites](#prerequisites)  
4. [Build & Run](#build--run)  
5. [Project Structure](#project-structure)  
6. [Class Overview](#class-overview)  
7. [Gameplay](#gameplay)  
8. [Usage Example](#usage-example)  
9. [Contributing](#contributing)  
10. [License](#license)  

---

## Overview

**Go Fish C++** is a simple, object-oriented command-line implementation of the classic card game “Go Fish.”  
Written in modern **C++17**, it demonstrates:

- Clean separation of concerns  
- Dynamic memory and container usage  
- Robust input validation  
- Basic computer opponent logic (random choice)  
- Replay functionality  

This project is ideal for showcasing core C++ skills and fundamental OOP best practices.

---

## Features

- **Human vs. Computer**: Play against a built-in computer opponent that randomly selects a rank from its hand.  
- **Input Validation**: Prompts the user again on invalid choices.  
- **Automatic Book Detection**: Collects sets of four matching ranks (“books”) and removes them from hands.  
- **Game State Display**: Shows each player’s hand, number of books, and remaining deck size.  
- **Replay Option**: At game end, choose to play again or quit.

---

## Prerequisites

- A **C++17**-capable compiler (GCC 7+, Clang 5+, MSVC 2017+)  
- Standard C++ library only (no external dependencies)  
- UNIX shell or Windows Command Prompt / PowerShell  

---

## Build & Run

### Clone the repository
```bash
git clone https://github.com/your-username/Go-Fish-CPlusPlus.git
cd Go-Fish-CPlusPlus
