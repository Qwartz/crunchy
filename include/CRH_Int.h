/**
* \file CRH_Int.h
* \brief Integer sizing and internal defines
* \details Internal sizes and typedefs
* \author Corbin Matschull
* \version 1.2r2
* \date Aug 31. 2015
* \warning Make sure you run with admin/root privilages or this will fail
* \throws CANNOT_BIND_TARGETS_EXCEPTION
*/
#include <Windows.h>
#include <minwindef.h>
#include <string>
#include <vector>
namespace crunchy
{

#   define  CRNINT_VER "0.2.1"
#   define  STATIC_INT 32

// ==========================================
// ------------------------------------------
//      CRUNCHY VARS
//      Use the crunchy vars for internal variables or internal parameters.
//      Use standard ANSI C++ variable typenames for external usage.
#   define  CRUNCHY_UINT unsigned int
#   define  CRUNCHY_UFLOAT unsigned float
#   define  CRUNCHY_UDOUBLE unsigned double
#   define  CRUNCHY_ULONG unsigned long
#   define  CRUNCHY_STRING std::string

#   define  PAGING_REFERENCES 12

#   define  EXTERN extern

#   define  RET_STACK(ptr) ((ptr < 31) - ~(15 << 1))

// ==========================================
// ------------------------------------------
//      Paging References


/**
 * @brief Paging system type. Used for creating a master paging system
 *
 * @param signableID - used to sign a 32-Bit PRUID (Pseudo. Random. User. ID)
 * @param ptr_id - used a pointer ID
 * @param virtualUID - used to sign a virtual UID with a string
 */
typedef struct
{
    CRUNCHY_UINT signableID;
    CRUNCHY_UINT *ptr_id;
    CRUNCHY_STRING virtualUID;
} pgs_t;


/**
 * @brief PRP (Public Return Prototypes), typenames for PRP keys.
 *
 * @param prp128  - portable rotation property 128-bit
 * @param prp512  - portable rotation property 512-bit
 * @param prp1024 - portable rotation property 1024-bit
 *
 *  @param crnHasNotInt - vector chaining for CRN property checking based upon INT value
 */
struct has_prp_int
{
    static int prp128;
    static long prp512;
    static long long prp1024;

    std::vector<int> crnHasNotInt;
} has_prp_int_t;


/**
 * @brief CRN (Constant Return Numbers), use these for returning constant value ID's
 */
struct crn
{
    WORD default_crn;
    static std::string stdCRN;
};

#if defined(HAS_STATIC_REFERENCE)
#   define  PAGING_REFERENCES 24
#   define  STATIC_REFERENCE_CHECK_STR "NULL"
#   define  HAS_CORRECT_KEY "KeyCheckOk = TRUE"
#endif



// ==========================================
// ------------------------------------------
//      Function Prototypes

/// @param - Anonymous integer for sizing placeholder
/// @param crnID - Default Session ID
void crn(CRUNCHY_UINT*, const CRUNCHY_STRING crnID);

void  createCRNData();
DWORD hasCRNInstance();


/**
 * @brief Contains prototypes to create virtual shell instances
 */
class Virtual
{
    public:

        // Only use these for internal changes to the Virtual class
        int *vReference;
        bool hasVirtualReference;
        static int *stack_t;


        /**
         * @param prp_int_t - Accessor to has_prp_int
         * @param crn_t - Accessor to crn
         * @param hasStaticUID - Keep the UID the same throughout the run of this function
         * @param finalAccessor - Keep the accessor the same throught runtime
         */
        static DWORD *reference_accessor(has_prp_int *prp_int_t,
                                         struct crn *crn_t,
                                         bool hasStaticUID,
                                         bool finalAccessor
                                        );


};


}
