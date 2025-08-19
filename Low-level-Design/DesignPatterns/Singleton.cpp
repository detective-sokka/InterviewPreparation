#include <iostream>
#include <string>

class Singleton
{
    static Singleton *instance;    

    public:
        static Singleton& getInstance()
        {
            static Singleton instance;            
            return instance;
        }
        Singleton(const Singleton &) = delete;
        Singleton & operator=(const Singleton &) = delete;        
    private: 
        Singleton() {            
        }
};

// Set instance to nullptr initially
Singleton* Singleton::instance = nullptr;

int main()
{    
    std::cout << &Singleton::getInstance();
    std::cout << &Singleton::getInstance();
    return 0;
}