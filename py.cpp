#include <Python.h>
#include <fstream>
#include <iostream>

int main() {
    // Initialize Python interpreter
    Py_Initialize();

    // Open Python trash detection script file
    std::ifstream scriptFile("trash_detection.py");
    if (!scriptFile.is_open()) {
        std::cerr << "Failed to open Python trash detection script file\n";
        return 1;
    }

    // Read the content of the Python script
    std::string scriptContent((std::istreambuf_iterator<char>(scriptFile)),
                              std::istreambuf_iterator<char>());

    // Close the file
    scriptFile.close();

    // Run Python trash detection code
    PyRun_SimpleString(scriptContent.c_str());

    // Finalize Python interpreter
    Py_Finalize();

    return 0;
}
