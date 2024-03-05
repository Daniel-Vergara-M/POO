#include <iostream>

using namespace std;

/*
 *   Prints a string to the console with a new line at the end.
 *@param message
 *   The string to be printed.
 */
void println(string message)
{
    cout << message << endl;
}
/*
 *   Prints a string to the console.
 *   Used mostly for asking input from the user.
 *@param message
 *   The string to be printed.
 */
void print(string message)
{
    cout << message;
}


/*
*  Asks the user for input and returns its value.
*  @param message
*    The message to be printed before asking for input.
*/
template <typename T>
T input(string message)
{
    T value;
    print(message);
    cin >> value;
    return value;
}