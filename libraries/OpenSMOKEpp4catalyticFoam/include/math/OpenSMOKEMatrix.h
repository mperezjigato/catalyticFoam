/***************************************************************************
 *   Copyright (C) 2012 by Alberto Cuoci								   *
 *   alberto.cuoci@polimi.it                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef OpenSMOKE_OpenSMOKEMatrix_Hpp
#define OpenSMOKE_OpenSMOKEMatrix_Hpp

#include "OpenSMOKEStdInclude.h"
#include "OpenSMOKEBaseClass.h"
#include "OpenSMOKEUtilities.h"
#include "OpenSMOKEFunctions.h"
#include "OpenSMOKEVector.h"


namespace OpenSMOKE
{
	//!  A class for matrices
	/*!
		 This is a user-friendly class to manage basic operations on matrices
	*/

	template<typename T>
	class OpenSMOKEMatrix : public OpenSMOKEBaseClass
	{
		friend class OpenSMOKEVector<T>;

		public:
		
		/**
		* Default constructor (Type 1)
		*/
		OpenSMOKEMatrix(void);

		/**
		* Copy-initializer constructor (Type 2)
		*/
		OpenSMOKEMatrix(OpenSMOKEMatrix<T> const& rval);

		/**
		* Constructor (Type 3): the matrix is sized and all the elements are set equal to 0
		*/
		OpenSMOKEMatrix(const int rows, const int columns);

		/**
		* Constructor (Type 4): the vector is sized and all the elements are provided by the user
		*/
		OpenSMOKEMatrix(const int rows, const int columns, const T a11, ...);

		/**
		* Constructor (Type 5): the vector is sized and all the elements are provided by the user
		*/
		OpenSMOKEMatrix(const int rows, const int columns, const T* values);

		/**
		* Constructor (Type 6): the matrix (n x 1) is generated from a vector 
		*/
		OpenSMOKEMatrix(OpenSMOKEVector<T> const& rval);

		/**
		* Constructor (Type 7):
		*/
		OpenSMOKEMatrix(const int rows, const int columns, const OpenSMOKEMatrix<T> &rval);

		/**
		* Constructor (Type 8): 
		*/
		OpenSMOKEMatrix(const int rows, const int columns, const int irow, const int jcol, const OpenSMOKEMatrix<T> &rval);


		/**
		* Constructor (Type 9): 
		*/
		OpenSMOKEMatrix(const std::string fileName, const OpenSMOKE_File_Format fileFormat);


		/**
		* Default destructor
		*/
		~OpenSMOKEMatrix(void);

		/**
		* Returns a pointer to internal data
		*/
		inline T* GetHandle();
		
		/**
		* Returns a pointer to internal data
		*/
		inline const T* GetHandle() const;

		/**
		* Returns the i element of the vector (with range control)
		*/
		inline T* operator [] (const int i);

		/**
		* Returns the i element of the vector (without range control)
		*/
		inline const T* operator [] (const int i) const;

		/**
		* Initialize all the elements of the matrix
		*/
		void operator = (const T c);
            
                     
        // TODO       
        /**
		* Assignment operator (1)
		*/
		OpenSMOKEMatrix<T>& operator =(OpenSMOKEMatrix<T> const& orig);
                
                /**
		* Assignment operator (4)
		*/
		//const OpenSMOKEMatrix<T>& operator =(OpenSMOKEMatrix<T> const& orig);
                
                /**
		* Assignment operator (7)
		*/
		//OpenSMOKEMatrix<T> operator =(OpenSMOKEMatrix<T> const& orig);

		/**
		* Returns the number of rows
		*/
		inline int Rows(void) const;

		/**
		* Returns the number of rows
		*/
		inline int Columns(void) const;

		/**
		* Returns WhoAmI
		*/
		inline int WhoAmI(void) const;

		/**
		* Returns access to matrix elements
		*/
		inline T** Matrix() const;	

		/**
		* Returns the i-th row of the matrix
		*/
		void GetRow(const int i, OpenSMOKEVector<T> *v);	

		/**
		* Returns the i-th column of the matrix
		*/
		void GetColumn(const int i, OpenSMOKEVector<T> *v); 

		/**
		* Set the j-th row of the matrix
		*/
		void SetRow(const int j, const OpenSMOKEVector<T> &rval);

		/**
		* Set the j-th row of the matrix
		*/
		void SetRow(const int j, const T rval);

		/**
		* Set the j-th column of the matrix
		*/
		void SetColumn(const int j, const OpenSMOKEVector<T> &rval);

		/**
		* Set the j-th column of the matrix
		*/
		void SetColumn(const int j, const T rval);

		/**
		*@brief Returns the i-th diagonal of the matrix
		*@param i the index of diagonal (i=0 main diagonal, i>0 upper diagonals)
		*/
		void GetDiagonal(const int i, OpenSMOKEVector<T>  *v);	

		/**
		* Set all the elements of the matrix
		*/
		void SetMatrix(const T rval);

		/**
		* Insert a row at position i
		*/
		void InsertRow(const int i, OpenSMOKEVector<T> &v);

		/**
		* Append a row at the end of the matrix
		*/
		void AppendRow(OpenSMOKEVector<T> &v);
            
		/**
		*@brief Returns sum of the rows
		*@param *sumRows vector containing the sum of each row
        *                (the returned size is equal to the number of columns)
		*/    
        void RowsSum(OpenSMOKEVector<T> *sumRows);
              
		/**
		*@brief Returns sum of the columns
		*@param *sumColumns vector containing the sum of each column
        *                   (the returned size is equal to the number of rows)
		*/   
        void ColumnsSum(OpenSMOKEVector<T> *sumColumns);

		/**
		*@brief Load the vector from file
		*@param fileName name of file to be read
		*@param fileFormat format of file to be read
		*/
		void Load(const std::string fileName, const OpenSMOKE_File_Format fileFormat);

		/**
		*@brief Load the vector from file
		*@param fInput stream to be read
		*@param fileFormat format of file to be read
		*/
		void Load(std::ifstream& fInput, const OpenSMOKE_File_Format fileFormat);

		/**
		*@brief Save the vector on file
		*@param fileName name of file to be written
		*@param fileFormat format of file to be written
		*/
		void Save(const std::string fileName, const OpenSMOKE_File_Format fileFormat);

		/**
		*@brief Save the vector on file
		*@param fOutput stream to be written
		*@param fileFormat format of file to be written
		*/
		void Save(std::ofstream& fOutput, const OpenSMOKE_File_Format fileFormat);

		/**
		* Print on video (verbose)
		*/
		void PrintOnVideo() const;

// Friend functions
	public:	

		/**
		* Changing the dimensions of an existing matrix
		*/
		template<typename T_>
		friend void ChangeDimensions(const int rows, const int columns, OpenSMOKEMatrix<T_>* result, bool reset);

		/**
		* Swapping matrices
		*/
		template<typename T_>
		friend void Swap(OpenSMOKEMatrix<T_> *lval, OpenSMOKEMatrix<T_> *rval);
	
		// Arithmetic Functions

		//! Matrix-Matrix sum: \f$ C=A+B\f$;
		template<typename T_>
		friend void Add(OpenSMOKEMatrix<T_> const& A, OpenSMOKEMatrix<T_> const& B, OpenSMOKEMatrix<T_> *C);

		//! Matrix-Matrix subtraction: \f$ C=A-B\f$;
		template<typename T_>
		friend void Sub(OpenSMOKEMatrix<T_> const& A, OpenSMOKEMatrix<T_> const& B, OpenSMOKEMatrix<T_> *C);

		//! Matrix-Matrix element by element product: \f$ C_{(i,j)}=A_{(i,j)}*B_{(i,j)}\f$;
		template<typename T_>
		friend void ElementByElementProduct(OpenSMOKEMatrix<T_> const& A, OpenSMOKEMatrix<T_> const& B, OpenSMOKEMatrix<T_> *C);

		//! Matrix-Matrix element by element division: \f$ C_{(i,j)}=A_{(i,j)}/B_{(i,j)}\f$;
		template<typename T_>
		friend void ElementByElementDivision(OpenSMOKEMatrix<T_> const& A, OpenSMOKEMatrix<T_> const& B, OpenSMOKEMatrix<T_> *C);

		//! Squared-Elements Matrix: \f$ C_{(i,j)}=A_{(i,j)}*A_{(i,j)}\f$;
		template<typename T_>
		friend void Sqr(OpenSMOKEMatrix<T_> const& A, OpenSMOKEMatrix<T_> *C);

		//! Absolute value Matrix: \f$ C=abs(A)\f$;
		template<typename T_>
		friend void Abs(OpenSMOKEMatrix<T_> const& A, OpenSMOKEMatrix<T_> *C);


		// Power and Root Functions

		//! Inverse value Matrix: \f$ C_{(i,j)}=1/A_{(i,j)}\f$;
		template<typename T_>
		friend void Inv(OpenSMOKEMatrix<T_> const& A, OpenSMOKEMatrix<T_> *C);

		//! Square-Root Matrix: \f$ C_{(i,j)}=sqrt(A_{(i,j)})\f$;
		template<typename T_>
		friend void Sqrt(OpenSMOKEMatrix<T_> const& A, OpenSMOKEMatrix<T_> *C);

		//! Inverse Square-Root Matrix: \f$ C_{(i,j)}=1/sqrt(A_{(i,j)})\f$;
		template<typename T_>
		friend void InvSqrt(OpenSMOKEMatrix<T_> const& A, OpenSMOKEMatrix<T_> *C);

		//! Cube-Root Matrix: \f$ C_{(i,j)}=A_{(i,j)}^{1/3}\f$;
		template<typename T_>
		friend void Cbrt(OpenSMOKEMatrix<T_> const& A, OpenSMOKEMatrix<T_> *C);

		//! Inverse Cube-Root Matrix: \f$ C_{(i,j)}=1/A_{(i,j)}^{1/3}\f$;
		template<typename T_>
		friend void InvCbrt(OpenSMOKEMatrix<T_> const& A, OpenSMOKEMatrix<T_> *C);

		//! Raises each element of matrix A to the constant power 2/3: \f$ C_{(i,j)}=A_{(i,j)}^{2/3}\f$;
		template<typename T_>
		friend void Pow2o3(OpenSMOKEMatrix<T_> const& A, OpenSMOKEMatrix<T_> *C);

		//! Raises each element of matrix A to the constant power 3/2: \f$ C_{(i,j)}=A_{(i,j)}^{2/3}\f$;
		template<typename T_>
		friend void Pow3o2(OpenSMOKEMatrix<T_> const& A, OpenSMOKEMatrix<T_> *C);

		//! Computes A to the power B for elements of two matrices: \f$ C_{(i,j)}=A_{(i,j)}^{B_{(i,j)}}\f$;
		template<typename T_>
		friend void Pow(OpenSMOKEMatrix<T_> const& A, OpenSMOKEMatrix<T_> const& B, OpenSMOKEMatrix<T_> *C);

		//! Raises each element of matrix A to the constant power b: \f$ C_{(i,j)}=A_{(i,j)}^b\f$;
		template<typename T_>
		friend void Pow(OpenSMOKEMatrix<T_> const& A, const double b, OpenSMOKEMatrix<T_> *C);

		//! Computes a square root of sum of two squared elements: \f$ C_{(i,j)}=sqrt(A_{(i,j)}^2+B_{(i,j)}^2)\f$;
		template<typename T_>
		friend void Hypot(OpenSMOKEMatrix<T_> const& A, OpenSMOKEMatrix<T_> const& B, OpenSMOKEMatrix<T_> *C);


		// Exponential and Logarithmic Functions

		//! Computation of the exponential of matrix elements: \f$ C_{i,j}=exp(A_{i,j}) \f$;
		template<typename T_>
		friend void Exp(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);

		//! Computation of the exponential of matrix elements decreased by 1: \f$ C_{i,j}=exp(A_{i,j}) - 1 \f$;
		template<typename T_>
		friend void ExpMinus1(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);

		//! Computation of the natural logarithm of matrix elements: \f$ C_{i,j}=ln(A_{i,j}) \f$;
		template<typename T_>
		friend void Ln(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);

		//! Computation of the denary logarithm of matrix elements: \f$ C_{i,j}=log10(A_{i,j}) \f$;
		template<typename T_>
		friend void Log10(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);

		//! Computation of the natural logarithm of matrix elements that are increased by 1: \f$ C_{i,j}=ln(A_{i,j}) + 1 \f$;
		template<typename T_>
		friend void LnPlus1(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);


		// Trigonometric Functions

		//! Computation of the cosine of vector elements: \f$ C_{i,j}=cos(A_{i,j}) \f$;
		template<typename T_>
		friend void Cos(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);

		//! Computation of the sine of vector elements: \f$ C_{i,j}=sin(A_{i,j}) \f$;
		template<typename T_>
		friend void Sin(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);

		//! Computation of the sine and cosine of vector elements: \f$ Sine_{i,j}=sin(A_{i,j}) and Cosine_{i,j}=cos(A_{i,j})\f$;
		template<typename T_>
		friend void SinCos(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *Sine, OpenSMOKEMatrix<T_> *Cosine);

		//! Computation of the tangent of vector elements: \f$ C_{i,j}=tan(A_{i,j}) \f$;
		template<typename T_>
		friend void Tan(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);

		//! Computation of the inverse cosine of vector elements: \f$ C_{i,j}=acos(A_{i,j}) \f$;
		template<typename T_>
		friend void Acos(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);

		//! Computation of the inverse sine of vector elements: \f$ C_{i,j}=asin(A_{i,j}) \f$;
		template<typename T_>
		friend void Asin(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);

		//! Computation of the inverse tangent of vector elements: \f$ C_{i,j}=atan(A_{i,j}) \f$;
		template<typename T_>
		friend void Atan(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);

		//! Computation of the four-quadrant inverse tangent of elements of two vectors: \f$ todo \f$;
		template<typename T_>
		friend void Atan2(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> const &B, OpenSMOKEMatrix<T_> *C);


		// Hyperbolic Functions
		
		//! Computation of the hyperbolic cosine of vector elements: \f$ C_{i,j}=cosh(A_{i,j}) \f$;
		template<typename T_>
		friend void Cosh(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);

		//! Computation of the hyperbolic sine of vector elements: \f$ C_{i,j}=sinh(A_{i,j}) \f$;
		template<typename T_>
		friend void Sinh(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);

		//! Computation of the hyperbolic tangent of vector elements: \f$ C_{i,j}=tanh(A_{i,j}) \f$;
		template<typename T_>
		friend void Tanh(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);

		//! Computation of the inverse hyperbolic cosine of vector elements: \f$ C_{i,j}=acosh(A_{i,j}) \f$;
		template<typename T_>
		friend void Acosh(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);

		//! Computation of the inverse hyperbolic sine of vector elements: \f$ C_{i,j}=asinh(A_{i,j}) \f$;
		template<typename T_>
		friend void Asinh(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);

		//! Computation of the inverse hyperbolic tangent of vector elements: \f$ C_{i,j}=atanh(A_{i,j}) \f$;
		template<typename T_>
		friend void Atanh(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);

		
		// Special Functions

		//! Computation of the error function value of vector elements: \f$ C_{i,j}=erf(A_{i,j}) \f$;
		template<typename T_>
		friend void Erf(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);

		//! Computation of the complementary error function value of vector elements: \f$ C_{i,j}=erfc(A_{i,j}) \f$;
		template<typename T_>
		friend void Erfc(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);

		//! Computation of the cumulative normal distribution function value of vector elements: \f$ todo \f$;
		template<typename T_>
		friend void CdfNorm(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);

		//! Computation of the inverse error function value of vector elements: \f$ C_{i,j}=erfinv(A_{i,j}) \f$;
		template<typename T_>
		friend void ErfInv(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);

		//! Computation of the inverse complementary error function value of vector elements: \f$ C_{i,j}=erfcinv(A_{i,j}) \f$;
		template<typename T_>
		friend void ErfcInv(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);

		//! Computation of the inverse cumulative normal distribution function value of vector elements: \f$ todo \f$;
		template<typename T_>
		friend void CdfNormInv(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);

		//! Computation of the natural logarithm for the absolute value of the gamma function of vector elements: \f$ todo \f$;
		template<typename T_>
		friend void LnGamma(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);

		//! Computation of the gamma function of vector elements: \f$ C_{i,j}=gamma(A_{i,j}) \f$;
		template<typename T_>
		friend void TGamma(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);


		// Rounding Functions 	 

		//! Rounding towards minus infinity: \f$ todo \f$;
		template<typename T_>
		friend void Floor(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);

		//! Rounding towards plus infinity: \f$ todo \f$;
		template<typename T_>
		friend void Ceil(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);

		//! Rounding towards zero infinity: \f$ todo \f$;
		template<typename T_>
		friend void Trunc(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);

		//! Rounding to nearest integer: \f$ todo \f$;
		template<typename T_>
		friend void Round(OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);
		
		
		// Product

		//! Scalar-Matrix product: \f$ C=alpha*C \f$;
		template<typename T_>
		friend void Product(const T_ alpha, OpenSMOKEMatrix<T_> *C);

		//! Scalar-Matrix product: \f$ C=alpha*A + C \f$;
		template<typename T_>
		friend void Product(const T_ alpha, OpenSMOKEMatrix<T_> const &A, OpenSMOKEMatrix<T_> *C);

		//! Matrix-Matrix product: \f$ C=alpha*A*B +beta*C\f$;
		/*!
			\param A input matrix A
			\param B input matrix B
			\param C output matrix C
			\param transposea if true the matrix A will be transposed
			\param transposeb if true the matrix B will be transposed
			\param alpha 
			\param beta 
			\return Only the matrix C is overwritten with the result
		*/
		template<typename T_>
		friend void Product(OpenSMOKEMatrix<T_> const& A, OpenSMOKEMatrix<T_> const& B, OpenSMOKEMatrix<T_> *C,
								const bool transposea, const bool transposeb, const T_ alpha, const T_ beta);

		//! Matrix-Vector product: \f$ y=alpha*A*x +beta*y\f$;
		/*!
			\param A input matrix A
			\param x input vector x
			\param y output vector y
			\param transposea if true the matrix A will be transposed
			\param alpha 
			\param beta 
			\return Only the vector y is overwritten with the result
		*/
		template<typename T_>
		friend void Product(OpenSMOKEMatrix<T_> const& A, OpenSMOKEVector<T_> const& x, OpenSMOKEVector<T_> *y,
				            	const bool transposea, const T_ alpha, const T_ beta);


		template<typename T_>
		friend void FactorizationLU(OpenSMOKEMatrix<T_> *A);

		template<typename T_>
		friend void SolveLU(OpenSMOKEMatrix<T_> const& A, OpenSMOKEVector<T_> *b, const bool transposea);

	protected:

		T** matrix_;		/**< matrix elements  */  
		int size_;			/**< matrix size */  
		int numColumns_;	/**< number of columns */
		int numRows_;		/**< number of rows */

	protected:

		OpenSMOKEVector<int> ipiv;
		
		void CopyPreparation(const int rRows, const int rColumns);

	private:

		/**
		*@brief Initialize a vector (memory allocation)
		*@param size The number of vector elements
		*/
		void Initialize(const int rows, const int columns);	

		/**
		*@brief Deallocating memory
		*/
		void Deinitialize();
	};

	typedef OpenSMOKEMatrix<unsigned int>		OpenSMOKEMatrixUnsignedInt;
	typedef OpenSMOKEMatrix<int>				OpenSMOKEMatrixInt;
	typedef OpenSMOKEMatrix<float>				OpenSMOKEMatrixFloat;
	typedef OpenSMOKEMatrix<double>				OpenSMOKEMatrixDouble;
	typedef OpenSMOKEMatrix<std::string>		OpenSMOKEMatrixString;
}

#endif	// OpenSMOKE_OpenSMOKEMatrix_Hpp

