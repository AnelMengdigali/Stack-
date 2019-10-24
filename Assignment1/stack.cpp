
#include "stack.h"

void stack::ensure_capacity( size_t c ) 
{
   if( current_capacity < c )
   {
      // New capacity will be the greater of c and 2 * current_capacity. 

      if( c < 2 * current_capacity )
         c = 2 * current_capacity;

      double* newdata = new double[ c ];
      for( size_t i = 0; i < current_size; ++ i )
         newdata[i] = data[i];

      current_capacity = c;
      delete[] data;
      data = newdata;
   }
}

//Default constructor:

stack::stack()
	: current_size{0},
	  current_capacity{0},
	  data{new double[current_capacity]}
{ }           

//Copy constructor:  

stack::stack( const stack& s )
	: current_size{s. current_size},
	  current_capacity{s. current_capacity},
	  data{new double[current_capacity]}
{
	for(size_t i = 0; i != current_size; ++i) 
	      data[i] = s. data[i];
}

//Destructor:

stack::~stack( )
{
	delete[] data;
}

//Assignment operator:

const stack& stack:: operator = ( const stack& s )
{
	ensure_capacity ( s. current_capacity );
	
	for (size_t i = 0; i != s. current_size; ++i)
		data[i] = s. data[i];

	current_size = s. current_size;

	return s;
	
}

//Other constructor:

stack::stack( std::initializer_list<double> init )
{
	current_size = init.size();
	current_capacity = init.size();

	data = new double [current_capacity];
	
	size_t i = 0;

	for ( double d: init ) 
	{
		data[i] = d;
		++i;
	}		
		 
}


//Additional operations:

void stack::push( double d ) 
{
	ensure_capacity( current_size + 1 );

	data[ current_size ] = d;

	current_size = current_size + 1;
}


void stack:: pop( ) 
{
	//precondition: stack must be non-empty
	current_size = current_size - 1; 
}


void stack:: clear( ) 
{
 	current_size = 0;
}


void stack:: reset( size_t s ) 
{
	//precondition: s<=size();	
	current_size = s;
}


double stack:: peek( ) const 
{
	//precondition: stack must be non-empty
	return data[current_size - 1];
}


size_t stack:: size( ) const
{
	size_t size = current_size;

	return size;
}


bool stack:: empty( ) const
{
	if ( current_size == 0 ) { 
		return 1;
	}
	 
	return 0;
}


std::ostream& operator << ( std::ostream& out, const stack& s ) 
{
	out << "[ ";
	for ( size_t i = 0; i != s. current_size; ++i )
	{ 
		if( i != 0 )
			out << ", ";
		out << s. data[i];
	}
	out << " ]";
	return out;
}











 
