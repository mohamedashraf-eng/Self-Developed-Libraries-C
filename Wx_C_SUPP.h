/*
    Author: Mohamed Ashraf (Wx)
    Date: 2/3/2022
    Type: 2D-Dynamic Memory Allocator.
*/

// HEADER GUARDS: __Wx_C_SUPP_H__
#ifndef __Wx_C_SUPP_H__
#define __Wx_C_SUPP_H__

// HEADER LIBRARIES USED:
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
#include <stdbool.h>
//=====================================

// IMPORTANT KEYBOARD KEYS(ASCII):
// BACKSPACE:
#define BKSP 8
// ENTER:
#define ENTER 13
// ESCAPE:
#define ESC 27
// SPACE:
#define SPACE 32
// TAB:
#define TAB 9

//==================================================

/*
  -----------------------------
  c:  char
  8:  uint8_t
  16: uint16_t
  32: uint32_t
  -----------------------------
*/

/*****************************************************
*                    GLOBAL VARIABLES                *
******************************************************/


/*****************************************************
*                    FUNCTION DECLARED               *
******************************************************/
uint32_t **WX_ALLOCATE_32(const uint16_t , const uint16_t );
uint16_t **WX_ALLOCATE_16(const uint16_t , const uint16_t );
uint8_t  **WX_ALLOCATE_8 (const uint16_t , const uint16_t );

void WX_FREE(uint32_t **, const uint16_t );

void **wxalloc(const uint8_t, const uint16_t, const uint16_t );

/*****************************************************
*                    FUNCTIONS                       *
******************************************************/

// FUNCTION TO DYNAMICALLY ALLOCATE 2D MEMORY TYPE: (uint32_t).
uint32_t **WX_ALLOCATE_32(const uint16_t _SIZE_A, const uint16_t _SIZE_B)
{
  // Assign allocated double pointer address to "A2D_PTR".
  uint32_t **A2D_PTR = (uint32_t **) malloc( (_SIZE_A * sizeof(uint32_t **)) );

  // Check if the memory is allocated.
  if( (A2D_PTR  == NULL) )
  {
    printf("\n ERROR - MALLOC_FAILURE !EXIT\n");
    exit(-1);
  }

  // Assign second allocated memory pointer to the double pointer.
  for(uint32_t i = 0; (i < _SIZE_A); i++)
  {
    *(A2D_PTR + i) = (uint32_t *) malloc( (_SIZE_A * sizeof(uint32_t *)) );
  }

  // return the allocated memory.
  return A2D_PTR;
}// end WX_ALLOCATE_32.

// FUNCTION TO DYNAMICALLY ALLOCATE 2D MEMORY TYPE: (uint16_t).
uint16_t **WX_ALLOCATE_16(const uint16_t _SIZE_A, const uint16_t _SIZE_B)
{
  // Assign allocated double pointer address to "A2D_PTR".
  uint16_t **A2D_PTR = (uint16_t **) malloc( (_SIZE_A * sizeof(uint16_t **)) );

  // Check if the memory is allocated.
  if( (A2D_PTR  == NULL) )
  {
    printf("\n ERROR - MALLOC_FAILURE !EXIT\n");
    exit(-1);
  }

  // Assign second allocated memory pointer to the double pointer.
  for(uint32_t i = 0; (i < _SIZE_A); i++)
  {
    *(A2D_PTR + i) = (uint16_t *) malloc( (_SIZE_A * sizeof(uint16_t *)) );
  }

  // return the allocated memory.
  return A2D_PTR;
}// end WX_ALLOCATE_16.

// FUNCTION TO DYNAMICALLY ALLOCATE 2D MEMORY TYPE: (uint8_t).
uint8_t **WX_ALLOCATE_8(const uint16_t _SIZE_A, const uint16_t _SIZE_B)
{
  // Assign allocated double pointer address to "A2D_PTR".
  uint8_t **A2D_PTR = (uint8_t **) malloc( (_SIZE_A * sizeof(uint8_t **)) );

  // Check if the memory is allocated.
  if( (A2D_PTR  == NULL) )
  {
    printf("\n ERROR - MALLOC_FAILURE !EXIT\n");
    exit(-1);
  }

  // Assign second allocated memory pointer to the double pointer.
  for(uint32_t i = 0; (i < _SIZE_A); i++)
  {
    *(A2D_PTR + i) = (uint8_t *) malloc( (_SIZE_A * sizeof(uint8_t *)) );
  }

  // return the allocated memory.
  return A2D_PTR;
} //end WX_ALLOCATE_8.

// FUNCTION TO DYNAMICALLY ALLOCATE 2D MEMORY TYPE: (float).
float **WX_ALLOCATE_F(const uint16_t _SIZE_A, const uint16_t _SIZE_B)
{
  // Assign allocated double pointer address to "A2D_PTR".
  float **A2D_PTR = (float **) malloc( (_SIZE_A * sizeof(float **)) );

  // Check if the memory is allocated.
  if( (A2D_PTR  == NULL) )
  {
    printf("\n ERROR - MALLOC_FAILURE !EXIT\n");
    exit(-1);
  }

  // Assign second allocated memory pointer to the double pointer.
  for(uint32_t i = 0; (i < _SIZE_A); i++)
  {
    *(A2D_PTR + i) = (float *) malloc( (_SIZE_A * sizeof(float *)) );
  }

  // return the allocated memory.
  return A2D_PTR;
}// end WX_ALLOCATE_F.

// FUNCTION TO DYNAMICALLY ALLOCATE 2D MEMORY TYPE: (char).
char **WX_ALLOCATE_C(const uint16_t _SIZE_A, const uint16_t _SIZE_B)
{
  // Assign allocated double pointer address to "A2D_PTR".
  char **A2D_PTR = (char **) malloc( (_SIZE_A * sizeof(char **)) );

  // Check if the memory is allocated.
  if( (A2D_PTR  == NULL) )
  {
    printf("\n ERROR - MALLOC_FAILURE !EXIT\n");
    exit(-1);
  }

  // Assign second allocated memory pointer to the double pointer.
  for(uint32_t i = 0; (i < _SIZE_A); i++)
  {
    *(A2D_PTR + i) = (char *) malloc( (_SIZE_A * sizeof(char *)) );
  }

  // return the allocated memory.
  return A2D_PTR;
}// end WX_ALLOCATE_C.

// Funcution to free the 2D Dynamic array.
void WX_FREE(uint32_t **_MEM_ADDR, const uint16_t _SIZE_A)
{
  for(uint16_t i = 0; (i < _SIZE_A); i++)
  {
    free( *(_MEM_ADDR + _SIZE_A) );
  }

  free(_MEM_ADDR);
}// end WX_FREE.


// Function to user friendly the code complexity.

/*
- User friendly:
Converting the case value to understandble one.
*/

// Convert Byte to Bits.
#define Byte2Bit(x) ( (x) * (8) )

void **wxalloc(const uint8_t _SIZE, const uint16_t _SIZE_A, const uint16_t _SIZE_B)
{
  switch(_SIZE)
  {
    // char: (c) 0x63 - 98
    case ( (char ) 0x63 ):
    {
      return (void **) (WX_ALLOCATE_C(_SIZE_A, _SIZE_B));
      break;
    }

    // unsigned integer (8):
    case ( Byte2Bit(sizeof(uint8_t)) ):
    {
      return (void **) (WX_ALLOCATE_8(_SIZE_A, _SIZE_B));
      break;
    }

    // unsigned integer (16): 16
    case ( Byte2Bit(sizeof(uint16_t)) ):
    {
      return (void **) (WX_ALLOCATE_16(_SIZE_A, _SIZE_B));
      break;
    }

    // unsigned integer (32): 32
    case ( Byte2Bit(sizeof(uint32_t)) ):
    {
      return (void **) (WX_ALLOCATE_32(_SIZE_A, _SIZE_B));
      break;
    }

    // float: (f) 0x66 - 102
    case ( (char) 0x66 ):
    {
      return (void **) (WX_ALLOCATE_F(_SIZE_A, _SIZE_B));
      break;
    }

    default: {printf("\n ERROR - INVALID_INPUT !EXIT\n"); return NULL;}

  }
}// end wxalloc.

#endif
