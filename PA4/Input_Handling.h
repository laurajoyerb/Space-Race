#ifndef INPUT_HANDLING
#define INPUT_HANDLING

class Invalid_Input // Class for handling all errors
{
public:
  Invalid_Input(const char* in_ptr) : msg_ptr(in_ptr) {} // Sets member variable "msg_ptr" equal to the input into the constructor
  const char* const msg_ptr;
private:
  Invalid_Input(); // eliminates default constructor
};

#endif
