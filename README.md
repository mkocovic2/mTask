
# mTask 🗂️

**mTask** is a lightweight, Command-Line Interface (CLI) based project manager that helps you manage your tasks and projects effortlessly. Built with simplicity and scalability in mind, mTask is designed using Object-Oriented Programming (OOP) principles and leverages the Factory design pattern. The tool is JSON-compatible and built in C++ using the powerful **JSON.hpp** library to handle data storage.

## Features 🚀

- **Lightweight & Fast:** Designed to run efficiently with minimal resources.
- **JSON Compatible:** Saves your tasks and projects in a readable and portable JSON format.
- **Object-Oriented:** Built using OOP principles for clean and scalable code.
- **Factory Pattern:** Uses the Factory design pattern to create task objects dynamically.
- **Cross-Platform:** Can be compiled and run on most platforms (Linux, macOS, Windows).

---

## Installation ⚙️

### Prerequisites

Before you install, make sure you have the following installed:
- C++ compiler (e.g., GCC, Clang)
- **JSON.hpp** library (included in the project)

### Steps

1. Clone this repository to your local machine:
   ```bash
   git clone https://github.com/yourusername/mTask.git
   cd mTask
   ```

2. Build the project using CMake:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. Run the CLI tool:
   ```bash
   ./mTask
   ```

---

## Usage 🖥️

[Still Developing]

---

## Example JSON File 📁

Here’s what a sample JSON file might look like when storing tasks:

```json
{
  "tasks": [
    {
      "name": "Finish project report",
      "due": "2025-02-20",
      "status": "incomplete"
    },
    {
      "name": "Prepare presentation slides",
      "due": "2025-02-22",
      "status": "incomplete"
    }
  ]
}
```

---

## Design Philosophy 🧠

### Object-Oriented Design

The project follows OOP principles, making the code modular, easy to maintain, and extend. The primary classes are:

- `Task`: Represents a single task with attributes like name, due date, and status.
- `TaskManager`: Handles operations like creating, listing, and deleting tasks.
- `JSONStorage`: Handles reading and writing tasks to a JSON file.

### Factory Pattern

The Factory Pattern is used to dynamically create task objects, allowing easy expansion and customization of task types in the future.

---

## Contributing 🤝

Contributions are welcome! If you'd like to improve mTask, feel free to open an issue or submit a pull request. Please make sure to follow the code style and write tests for new features.

---

Feel free to modify this as needed and adjust the badges, username, and other specific details to fit your project! Let me know if you need any more adjustments.
