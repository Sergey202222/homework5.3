#include <iostream>

class smart_array
{
public:
  smart_array(int size)
  {
    if (size > 0)
    {
      this->size = size;
      this->index = 0;
      arr = new int[this->size];
    }
    else throw std::exception("Incorrect size!");
  }

  void add_element(int el)
  {
    if (index < size)
    {
      arr[index] = el;
      ++index;
    }
    else
    {
      throw std::exception("Array subscript out of range!");
    }
  }

  int get_element(int index)
  {
    if (index < 0 || index >= size) throw std::exception("Array subscript out of range!");
    else return arr[index];
  }

  ~smart_array()
  {
    delete[] arr;
  }
private:
  int* arr;
  int size;
  int index;
};

int main()
{
  try 
  {
    smart_array arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);
    arr.add_element(14);
    arr.add_element(15);
    std::cout << arr.get_element(1) << std::endl;
  }
  catch (const std::exception& ex) 
  {
    std::cout << ex.what() << std::endl;
  }
    return EXIT_SUCCESS;
}