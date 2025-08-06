#include <iostream>
// #include "CppConcepts/SharedPtr/SharedPtr.cpp"
#include "CppConcepts/String/String.cpp"
// #include "CppConcepts/UniquePtr/UniquePtr.cpp"
#include "CppConcepts/Vector/Vector.cpp"

int main()
{
    std::cout << "\n###### Test Custom Shared Pointer ##### ";
    // test_shared_ptr();

    std::cout << "\n##### Test Custom Unique Pointer ##### ";
    // test_unique_ptr();

    std::cout << "\n##### Test Custom String Class ##### ";
    // test_custom_string();

    std::cout << "\n##### Test Custom Vector Class ##### ";
    test_custom_vector();

    return 0;
}