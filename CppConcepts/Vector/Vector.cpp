#include <initializer_list>
#include <iostream>

template <typename T>
class Vector {
public: 
    Vector() : m_ptr{new T[2]},
               m_size{2} {                
    }

    Vector(std::initializer_list<T> init) : m_ptr{new T[init.size()]},
                                            m_size{init.size()} {        
        size_t index=0;

        for (auto& value : init) 
            m_ptr[index++] = value;
    }
 
    Vector(const Vector<T>& obj) : m_ptr{new T[obj.size()]}, 
                                   m_size{obj.size()} {           

        for (size_t i=0; i < m_size; i++)
            m_ptr[i] = obj.m_ptr[i];
    }

    Vector(Vector&& obj) : m_ptr{obj.m_ptr}, 
                           m_size{obj.size()} {        
        obj.m_ptr = nullptr;
        obj.m_size = 0;        
    }    

    Vector& operator = (const Vector& obj) {
        
        if (&obj != this)
        {
            delete[] m_ptr;
            m_size = obj.m_size;
            m_ptr = new T[m_size];
            
            for (int i=0; i < obj.size(); i++)
                m_ptr[i] = obj.m_ptr[i];                            
        }

        return *this;
    }

    Vector& operator = (Vector&& obj) {
        if (&obj != this) {
            delete[] m_ptr;            
            m_ptr = obj.m_ptr;
            m_size = obj.m_size;

            obj.m_ptr = nullptr;
            obj.m_size = 0;
        }

        return *this;
    }

    size_t size() const {
        return m_size;
    }

    void clear() {
        delete[] m_ptr;
        m_ptr = nullptr;
        m_size = 0; 
    }

    void display() const {
        std::cout << "\nContents of vector are : ";
        if (!m_ptr) 
            return;
        for (size_t i=0; i < m_size; i++)
            std::cout << m_ptr[i] << ", ";
    }

    ~Vector() {
        delete[] m_ptr;
        m_size = 0;
    }    

private: 
        T* m_ptr;
        size_t m_size;
};

void test_custom_vector() {
    Vector<int> a = {1, 2, 3};
    a.display();
    Vector<int> b = a;
    b.display();
    Vector<int> c = std::move(a);
    c.display();    
    a = c;
    a.display();
    b = std::move(c);
}