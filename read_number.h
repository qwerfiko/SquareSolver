///\file
///\brief read_number file
#ifndef READ_NUMBER_H
#define READ_NUMBER_H
/*!
    The function reads the values of the coefficients entered by the user.
    In case of an input error, it clears the buffer and starts again. Successfully read values are saved in the input buffer
    \param [in, out] a, b, c - coefficients
*/
void read_number (double *a, double *b, double *c);
/*!
    The function cleans the buffer. getchar() pulls values from the buffer one at a time until it encounters "\n" and does not save them anywhere
*/
void clear_buffer();

//-----------------------------------------------------------------------------

enum CONSOLE_COLORS {TEXT_GREEN = 10,
                     TEXT_BLUE  = 11,
                     TEXT_RED = 12,
                     TEXT_MAGENTA = 13,
                     TEXT_YELLOW = 14,
                     TEXT_WHITE = 15
};

void consolePaintText (CONSOLE_COLORS colors);
#endif

