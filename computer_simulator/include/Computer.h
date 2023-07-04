/* @Author
 * Student Name:  Yusuf Yildiz
 * Student ID : 150210006
 */

#include <iostream>
#include <string>

//  Methods
/*
    add : CPU
    subtract : CPU
    multiply : CPU
    render : GPU
    trainModel : GPU
*/

enum OPS // Enum object for operations
{
    ADD,
    SUBTRACT,
    MULTIPLY,
    RENDER,
    TRAINMODEL,
    ERROR
};

OPS hash_ops(const std::string &);
class ALU
{
public:
    ALU(const int);
    const int add(const int i1, const int i2) const { return i1 + i2; };      // Most functions are defined in header to present
    const int subtract(const int i1, const int i2) const { return i1 - i2; }; // good coding style, and readability
    const int multiply(const int i1, const int i2) const { return i1 * i2; };
    const int get_NPC() const { return this->numPerCores; }; // Getter function to reach private member

private:
    const int numPerCores;
};

class CUDA
{
public:
    CUDA(const int);
    const std::string render() const { return "Video is rendered"; };
    const std::string trainModel() const { return "AI Model is trained"; };
    const int get_numCores() const { return this->numCores; }; // Getter function to reach private member

private:
    const int numCores;
};

class CPU
{
public:
    CPU(const int);
    CPU(const CPU &in_CPU) : m_ALU{in_CPU.m_ALU} {};
    const int execute(const std::string &) const;
    const ALU get_ALU() const { return this->m_ALU; }; // Getter function to reach private member

private:
    const ALU m_ALU;
};

class GPU
{
public:
    GPU(const int);
    GPU(const GPU &in_GPU) : m_CUDA{in_GPU.m_CUDA} {};
    const std::string execute(const std::string &) const;
    const CUDA get_CUDA() const { return this->m_CUDA; }; // Getter function to reach private member

private:
    const CUDA m_CUDA;
};

class Computer
{
public:
    Computer();
    ~Computer();
    void operator+(const CPU &);
    void operator+(const GPU &);
    void execute(const std::string &) const;

private:
    CPU *attachedCPU; // Not implemented as const for the simplicity and readability purpose
    GPU *attachedGPU;
};
