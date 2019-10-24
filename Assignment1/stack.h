
#ifndef STACK_INCLUDED 
#define STACK_INCLUDED  1

#include <iostream>
#include <initializer_list>

class stack 
{
   size_t current_size;
   size_t current_capacity; 

   double* data; 
      // INVARIANТ: has been allocated with size current_capacity.
      // 0 <= current_size <= current_capacity. 

   void ensure_capacity( size_t c );
      // Ensure that stack has capacity of at least c.
    
  
public: 
   //Function prototypes:

   stack( ); //Default constructor constructing empty stack.

   stack( const stack& s ); //Copy constructor copying from stack s

   ~stack( ); //Destructor freeing allocated memory

   const stack& operator = ( const stack& s );  
	//Assignment operator

   stack( std::initializer_list<double> init ); 
	//Other constructor that does initialization of form s = { 1,2,3 }

   void push( double d ); 
	//Add an element at the end

   void pop( ); 
	//Delete the last element

   void clear( ); 
	//Make the stack empty

   void reset( size_t s ); 
	//Change a size of the stack

   double peek( ) const; 
	//Returns the last element on the stack

   size_t size( ) const; 
	//Returns a current size of the stack

   bool empty( ) const; 
	//Returns 1(true) if the stack is empty

   friend std::ostream& operator << ( std::ostream& , const stack& ); 
	//Additional method that does printing
}; 

std::ostream& operator << ( std::ostream& , const stack& );

#endif


