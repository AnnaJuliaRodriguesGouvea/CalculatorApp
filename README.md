### Simple Calculator in C++ with QtCreator

This project is a simple calculator application developed in C++ using QtCreator. The calculator allows you to perform basic sum, subtraction, multiplication and division operations between two floating point numbers (double). Additionally, it has history functionality that records the operations performed in a table next to the main interface.

### Application Features:

1. **Inputs:**
   - Two input fields where the user can enter floating point numbers.

2. **Available Operations:**
   - A combobox that allows you to select the desired operation:
     - **+** (sum)
     - **-** (subtraction)
     - **\*** (multiplication)
     - **/** (division)

3. **Calculate Button:**
   - When you click this button, the calculator performs the selected operation with the two given numbers and displays the result on the screen.

4. **Operations History:**
   - A table next to the calculator that keeps track of the operations performed. Each time the user calculates an operation, it is added to the history with the numbers used and the result.

### How to Run the Project:

To run the project on your local machine, follow the steps below:

1. **Installing QtCreator:**
   - Make sure you have QtCreator installed on your computer. You can download it at [Qt Downloads](https://www.qt.io/download-qt-installer-oss?hsCtaTracking=99d9dd4f-5681-48d2-b096-470725510d34%7C074ddad0-fdef-4e53-8aa8-5e8a876d6ab4).

2. **Repository Clone:**
   - Clone this repository to your local environment using Git:
     ```
     git clone https://github.com/AnnaJuliaRodriguesGouvea/CalculatorApp.git
     ```

3. **Open the Project in QtCreator:**
   - Open QtCreator and select "File" -> "Open File or Project".
   - Navigate to the directory where you cloned the repository and select the project file (.pro extension).

4. **Configuration and Compilation:**
   - QtCreator should automatically detect the project file and set up the environment.
   - Verify that the build settings are correct (such as the selected build kit).
   - Compile the project by clicking the compile button in the QtCreator toolbar.

5. **Application Execution:**
   - After successfully compiling, you can run the application directly from QtCreator.
   - The calculator interface will be displayed, allowing you to use the features described.

### Final considerations:

This simple calculator project demonstrates basic C++ graphical user interface (GUI) usage with QtCreator, allowing basic mathematical operations and keeping a history record of operations performed.