
# Simple Shell

Simple Shell is a basic command-line shell program implemented in C language. It provides a minimalistic command-line interface with the following features:

## Features

- **Command Execution**: Simple Shell allows you to execute system commands and programs by typing them in the shell prompt.

- **Built-in Commands**: In addition to external commands, the shell supports some built-in commands, such as `cd` for changing the current directory and `exit` for exiting the shell.

- **Command History**: The shell maintains a command history, allowing you to recall and execute previous commands using the up and down arrow keys.

- **Redirection**: You can use input and output redirection with the `>` and `<` operators to read from or write to files.

- **Piping**: The shell supports command piping using the `|` operator, allowing you to chain multiple commands together.

- **Tab Completion**: Basic tab completion for commands and file paths is available for convenience.

- **Signal Handling**: The shell handles common signals such as Ctrl+C (SIGINT) and Ctrl+Z (SIGTSTP) for process control.

- **Prompt Customization**: You can customize the shell prompt to display useful information such as the current working directory or username.

## Usage

1. **Compile the Shell**:
   - To compile the shell, run the following command in your terminal:

     ```shell
     gcc simple_shell.c -o simple_shell
     ```

2. **Run the Shell**:
   - Start the shell by executing the compiled binary:

     ```shell
     ./simple_shell
     ```

3. **Using the Shell**:
   - Enter commands at the shell prompt and press Enter to execute them.
   - Use built-in commands like `cd` and `exit` as needed.
   - Utilize features such as input/output redirection, piping, and signal handling.

4. **Exiting the Shell**:
   - To exit the shell, use the `exit` command or press Ctrl+D.

## Customization

You can customize the shell's behavior and appearance by modifying the source code. For example, you can change the prompt format or add additional built-in commands.

## Contributing

If you'd like to contribute to this project, please follow these guidelines:

- Fork the repository on GitHub.
- Make your changes and create a pull request with a clear description of your changes.
- Be sure to adhere to the code style and conventions used in the project.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
