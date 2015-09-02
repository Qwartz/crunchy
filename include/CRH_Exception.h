/**
* \file CRH_Exception.h
* \brief Exceptions and errors
* \details Contains prototypes and classes for errors and exceptions.
* \author Corbin Matschull
* \version 2
* \date Sep 2. 2015
* \pre Make sure you have GNU GCC or LLVM to compile, BSD or VCC won't compile.
* \throws UNDEFINED_ERROR_EXCEPTION
*/
#include <string>

/// \brief Main Crunchy Namespace
namespace crunchy
{
    /// \brief IO specific error namespace
    namespace IOexception
    {
        /// \brief Default UID generated for all exceptions
        #   define  EXCEPTION_DEFAULT_UID 1UL

        long error_code;            /**< Main error code param */
        std::string exception_name; /**< Main exception text */

        /// \brief Main class to contain IO exceptions
        class IOException
        {
            public:
                /**
                 * \brief IOException constructor
                 *
                 * \param exception - Name of error to display to user
                 * \param error_id - Generate an error id to direct users to documentation
                 */
                IOException(std::string exception, long error_id)
                {
                    exception = exception_name;
                    error_id  = error_code;
                }
        }
    }
}
