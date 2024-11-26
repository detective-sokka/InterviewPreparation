#include <iostream>
#include <string>

class Singleton
{
    static Singleton *instance;    

    public:
        static Singleton* getInstance()
        {
            if(instance == nullptr)
            {
                instance = new Singleton();
            }

            return instance;
        }
};

// Set instance to nullptr initially
Singleton* Singleton::instance = nullptr;

int main()
{
    Singleton singleton{};

    std::cout << singleton.getInstance() << std::endl;

    Singleton newSingleton;
    std::cout << newSingleton.getInstance();

    return 0;
}