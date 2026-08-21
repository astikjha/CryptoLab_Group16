# Assignment 3 - Static Application Security Testing (SAST)

## 1. Objective

The objective of this assignment is to develop a small Cryptocurrency Wallet application and perform Static Application Security Testing (SAST) using SonarQube.

The application is intentionally developed with security weaknesses so that they can be identified through security testing and static code analysis. After identifying the issues, they can be documented, remediated, and analyzed again.

---

## 2. Application Overview

A console-based Cryptocurrency Wallet application has been developed using Python.

The application provides the following core functionalities:

- Wallet creation
- Balance inquiry
- Transaction requests
- Transaction history

Cryptographic functionality is not implemented as it is not required for this assignment.

The application maintains wallet information using Python objects and a dictionary of users.

---

## 3. Technologies Used

| Technology | Purpose |
|------------|---------|
| Python | Application development |
| SonarQube | Static Application Security Testing |
| SonarScanner | Sending source code for analysis |
| Docker | Running SonarQube and SonarScanner |
| WSL2 | Development environment |

### SonarQube Details

- Edition: Community Edition
- Version: 9.9.8
- Server: `http://localhost:9000`

---

## 4. Project Structure

```text
secure_application/
│
├── src/
│   └── wallet.py
│
├── testcases/
│   └── vulnerability_testcases.txt
│
├── reports/
│
├── sast/
│
├── screenshots/
│
├── outputs/
│
├── sonar-project.properties
│
└── README.md