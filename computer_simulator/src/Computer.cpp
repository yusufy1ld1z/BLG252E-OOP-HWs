/* @Author
 * Student Name:  Yusuf Yildiz
 * Student ID : 150210006
 */

#include "Computer.h"
#include <iostream>
#include <string>

OPS hash_ops(const std::string &str_op) // Hash function to use enum object
{
    if (str_op == "add")
        return ADD;
    else if (str_op == "subtract")
        return SUBTRACT;
    else if (str_op == "multiply") // This function is implemented for the sake of simplicity
        return MULTIPLY;           // and the goal is to present good coding style
    else if (str_op == "render")
        return RENDER;
    else if (str_op == "trainModel")
        return TRAINMODEL;
    else
    {
        std::cout << "Undefined operation!" << std::endl; // Show information message to user
        return ERROR;                                     // Return ERROR code
    }
};

// Computer Class' Methods
Computer::Computer() : attachedCPU{nullptr}, attachedGPU{nullptr} // Default constructor for Computer class
{
    std::cout << "Computer is ready" << std::endl;
};

Computer::~Computer() // Destructor for Computer class to prevent memory leak
{
    delete this->attachedCPU;
    this->attachedCPU = nullptr; // Pointers assigned back to nullptr to prevent dangling pointers
    delete this->attachedGPU;
    this->attachedGPU = nullptr;
}

void Computer::operator+(const CPU &m_CPU) // CPU attachment method
{
    if (this->attachedCPU == nullptr)
    {
        this->attachedCPU = new CPU(m_CPU);
        std::cout << "CPU is attached" << std::endl;
    }
    else
    {
        std::cout << "There is already a CPU" << std::endl;
    }
};

void Computer::operator+(const GPU &m_GPU) // GPU attachment method
{
    if (this->attachedGPU == nullptr)
    {
        this->attachedGPU = new GPU(m_GPU);
        std::cout << "GPU is attached" << std::endl;
    }
    else
    {
        std::cout << "There is already a GPU" << std::endl;
    }
};

void Computer::execute(const std::string &operation) const
{
    switch (hash_ops(operation)) // Take enum corresponce of the given operation
    {
    case ADD:
        std::cout << attachedCPU->execute(operation) << std::endl; // CPU operation
        break;
    case SUBTRACT:
        std::cout << attachedCPU->execute(operation) << std::endl; // CPU operation
        break;
    case MULTIPLY:
        std::cout << attachedCPU->execute(operation) << std::endl; // CPU operation
        break;
    case RENDER:
        std::cout << attachedGPU->execute(operation) << std::endl; // GPU operation
        break;
    case TRAINMODEL:
        std::cout << attachedGPU->execute(operation) << std::endl; // GPU operation
        break;
    default:
        std::cout << "Undefined operation!" << std::endl;
        break;
    }
}
// CPU Class' Methods
CPU::CPU(int in) : m_ALU{in} // Constructor for CPU class
{
    std::cout << "CPU is ready" << std::endl;
};

const int CPU::execute(const std::string &operation) const
{
    std::cout << "Enter two integers" << std::endl; // Take 2 integers from user
    int i1, i2;
    std::cin >> i1 >> i2;
    switch (hash_ops(operation)) // Take enum corresponce of the given operation
    {
    case ADD:
        return get_ALU().add(i1, i2);
        break;
    case SUBTRACT:
        return get_ALU().subtract(i1, i2);
        break;
    case MULTIPLY:
        return get_ALU().multiply(i1, i2);
        break;
    default:
        return ERROR; // Return ERROR code
        break;
    }
}

// GPU Class' Methods
GPU::GPU(const int in) : m_CUDA{in}
{
    std::cout << "GPU is ready" << std::endl;
};

const std::string GPU::execute(const std::string &operation) const
{
    switch (hash_ops(operation)) // Take enum corresponce of the given operation
    {
    case RENDER:
        return get_CUDA().render();
        break;
    case TRAINMODEL:
        return get_CUDA().trainModel();
        break;
    default:
        return "Undefined operation!"; // Return information message
        break;
    }
}

// ALU Class' Methods
ALU::ALU(const int m_numPerCores) : numPerCores{m_numPerCores} // Constructor for ALU class
{
    std::cout << "ALU is ready" << std::endl;
};

// CUDA Class' Methods
CUDA::CUDA(const int m_numCores) : numCores{m_numCores} // Constructor for CUDA class
{
    std::cout << "CUDA is ready" << std::endl;
};
