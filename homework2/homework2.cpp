#include <iostream>

class smart_array
{
public:
  smart_array(int size)
  {
    if (size > 0)
    {
      this->size = size;
      arr = new int[this->size];
      index = 0;
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

  smart_array& operator=(smart_array& smart_arr)
  {
    if (this->arr != nullptr) this->arr = nullptr;
    delete[] this->arr;
    this->size = smart_arr.size;
    this->arr = new int[this->size];
    this->index = smart_arr.index;
    for (int index{}; index < this->size; ++index)
    {
      this->arr[index] = smart_arr.arr[index];
    }
    return *this;
  }

  ~smart_array()
  {
    if (arr != nullptr) arr = nullptr;
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

	smart_array new_array(2);
    new_array.add_element(44);
    new_array.add_element(34);

    arr = new_array;
  }
  catch (const std::exception& ex) 
  {
    std::cout << ex.what() << std::endl;
  }
  return EXIT_SUCCESS;
}