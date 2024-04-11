# Bank System Simulation

This program simulates the essential features and operations of a banking system, including account creation, deposit, withdrawal, and balance check. It is written in the C programming language and utilizes defined data structures to access information from files, including customer details and account balances.

## Features

- **Account Creation**: Users can create new bank accounts with unique IDs and passwords.
- **Deposit**: Users can deposit funds into their accounts.
- **Withdrawal**: Users can withdraw funds from their accounts, provided they have sufficient balance.
- **Balance Check**: Users can check their account balances.
- **File Handling**: Customer details and account balances are stored and accessed using file handling techniques.

## Usage

1. Compile the program using a C compiler, such as GCC: `gcc bank_system.c -o bank_system`
2. Run the compiled executable: `./bank_system`
3. Follow the on-screen instructions to perform various banking operations.

## File Structure

- **bank_system.c**: The main source code file containing the implementation of the banking system.
- **customer_details.txt**: A file containing customer information such as ID, name, and contact details.
- **account_balances.txt**: A file containing account balances for each customer.

## How It Works

The program utilizes data structures to represent customer details and account balances. It reads and writes this information to files for persistent storage. When a user interacts with the system, the program reads the necessary data from files, performs the requested operation, and updates the files accordingly.

## Future Improvements

- Implement additional features such as account transfers and account closure.
- Improve error handling and input validation to enhance robustness.
- Enhance security measures, such as encryption for sensitive data.
- Implement a graphical user interface (GUI) for a more user-friendly experience.

## Contribution

Contributions to the project are welcome! Feel free to fork the repository, make improvements, and submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Thanks to the C programming language community for providing valuable resources and support.
- Special thanks to all contributors who help improve and maintain this project.
