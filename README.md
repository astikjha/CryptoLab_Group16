# CryptoLabX Toolkit

## Cryptography Laboratory (22CPP307)

### Assignment 1 – Build Your CryptoLabX Toolkit

## Project Overview

CryptoLabX is a modular cryptography toolkit developed as part of the Cryptography Laboratory course. The objective of this project is to build a reusable software framework that will be expanded throughout the semester with various cryptographic algorithms, attack techniques, mathematical utilities, and security analysis modules.

This first assignment focuses on setting up the project structure, implementing a menu-driven command-line interface, performing basic text file analysis, maintaining execution logs, and preparing the project for future development.

---

## Objectives

- Create a professional project structure.
- Initialize and manage the project using Git.
- Build a menu-driven command-line interface.
- Perform basic text file analysis.
- Maintain execution logs.
- Prepare reusable datasets.
- Create proper project documentation.

---

## Team Information

**Group:** Group 16

**Team Members:**

- Astik Jha

---

## Project Structure

```
CryptoLabX_Group16/
│
├── classical/
├── attacks/
├── math/
├── modern/
├── analysis/
│   └── file_analyzer.py
├── datasets/
│   ├── sample1.txt
│   ├── sample2.txt
│   ├── sample3.txt
│   ├── sample4.txt
│   └── sample5.txt
├── outputs/
├── docs/
├── tests/
├── utils/
│   └── logger.py
├── main.py
├── README.md
├── requirements.txt
└── activity.log
```

---

## Features Implemented

### 1. Menu Driven Command Line Interface

The application provides the following options:

- Encrypt (Coming Soon)
- Decrypt (Coming Soon)
- Attack (Coming Soon)
- Analyze
- Exit

The toolkit is designed so that future cryptographic algorithms can be added without changing the overall structure.

---

### 2. File Analysis

The Analyze option reads a text file from the **datasets** folder and displays:

- Number of characters
- Number of words
- Number of lines
- Number of unique characters
- Letter frequency (A–Z)

---

### 3. Activity Logging

Every execution records:

- Current date
- Current time
- Selected menu option

The log file helps keep track of program usage.

---

### 4. Sample Datasets

The project contains five sample text files inside the datasets folder for testing and future cryptographic experiments.

---

## Technologies Used

- Python 3
- Git
- GitHub
- Visual Studio Code
- Linux / Ubuntu

---

## Future Modules

The CryptoLabX toolkit will be expanded in future assignments to include:

### Classical Cryptography

- Caesar Cipher
- Playfair Cipher
- Hill Cipher
- Vigenère Cipher
- Rail Fence Cipher

### Modern Cryptography

- AES
- DES
- RSA
- ECC

### Cryptanalysis

- Frequency Analysis
- Brute Force Attacks
- Dictionary Attacks

### Mathematical Utilities

- Modular Arithmetic
- Euclidean Algorithms
- Matrix Operations
- Number Theory Functions

### Security Analysis

- Entropy Calculation
- Randomness Testing
- Cipher Performance Evaluation

---

## How to Run

Clone the repository:

```bash
git clone <repository-url>
```

Move to the project directory:

```bash
cd CryptoLabX_Group16
```

Run the application:

```bash
python3 main.py
```

---

## Git Repository

Git is used for version control to maintain the project history and track changes throughout development.

Typical workflow:

```bash
git status
git add .
git commit -m "Meaningful commit message"
git push
```

---

## Learning Outcomes

Through this assignment, we learned:

- Organizing a modular software project.
- Using Git for version control.
- Building a command-line application.
- Reading and analyzing text files.
- Maintaining execution logs.
- Writing project documentation.

---

## Author

**Astik Jha**

B.Tech Computer Science Engineering

Cryptography Laboratory (22CPP307)
