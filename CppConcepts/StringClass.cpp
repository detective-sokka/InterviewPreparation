#include <iostream>
#include <stddef.h>
#include <stdlib.h>

class String
{
    public:
    String() : m_data{nullptr}, m_size{0}
    {
    }

    String(char *pData) : m_data{nullptr}, m_size{0}
    {
        if (!pData)
            return;
        
        size_t size;
        for (size=0; pData[size] != '\0'; size++)
        {            
        }
        
        m_data = (char*) malloc(sizeof(char) * (size + 1));
        m_size = size;

        for (size=0; pData[size] != '\0'; size++)
            m_data[size]  = pData[size];

        m_data[size] = '\0';
    }

    String(const String &param) : m_data{nullptr}, m_size{param.m_size}
    {
        if (param.m_size == 0)       
            return;
        
        m_data = (char*) malloc(sizeof(char) * (param.m_size + 1));
        m_size = param.m_size;
        
        for (int i = 0; i < param.m_size; i++)
            m_data[i] = param.m_data[i];

        m_data[m_size] = '\0';
    }

    String& operator=(const String &param)
    {
        if(&param == this)
            return *this;
        
        if (m_data != nullptr)
        {
            free(m_data);
            m_size = 0;
            m_data = nullptr;
        }

        m_data = (char*) malloc(sizeof(char) * (param.m_size + 1));
        m_size = param.m_size;
        
        for (int i = 0; i < param.m_size; i++)
            m_data[i] = param.m_data[i];

        m_data[m_size] = '\0';

        return *this;
    } 

    void printString()
    {
        if (!m_data)
            std::cout << "\nString is empty.\n";
        else
            std::cout << "\nThe string is : " << m_data << " and the size is : " << m_size << "\n";
    } 

    ~String()
    {
        if (m_data)
            free(m_data);
        
        m_data = nullptr;
        m_size = 0;
    }    

    private: 
        char *m_data;
        size_t m_size;
};

int main()
{

    std::cout << "\nDefault constructor -";
    String str1;
    str1.printString();    

    std::cout << "\nParameterized constructor -";
    String str2("abc");
    str2.printString();

    std::cout << "\nCopy constructor with empty String -";
    String str3{str1};
    str3.printString();    

    std::cout << "\nCopy constructor with String -";
    String str4{str2};
    str4.printString();

    std::cout << "\nAssignment operators -";
    str1 = str2;
    str1.printString();

    return 0;
}