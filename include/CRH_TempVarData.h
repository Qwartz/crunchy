/**
* \file CRH_TempVarData.h
* \brief Temporary data file
* \details This contains code to modify, create and delete temporary data.
* \author Corbin Matschull
* \version 1.1r4
* \date Aug 30. 2015
* \pre Make sure you have GNU GCC or LLVM to compile, BSD or VCC won't compile.
* \warning Make sure you run with admin/root privilages or this will fail
* \throws Check your Privilage ExceptionS
*/
#include <Windows.h>
#include <minwindef.h>
#include <string>

// =================================================== //
// --------------------------------------------------- //
//                  Comment Doc Styling                //
//                                                     //
//                f=function, v=variable               //
//                                                     //
//                <TYPENAME>(PTR?) f/v - desc          //
// Example:       <INT> (PTR) varExample - desc        //
//                                                     //
// --------------------------------------------------- //
// =================================================== //

#   define  UNARY_TYPE double

// =================================
// ---------------------------------
//      GLOBAL FILE DEFINES
#   define  TEMPVAR_PATH "%HomePath%/.tmpvardtm.txt"

#if defined(_WIN32) | defined(WIN32)
#   define  CRC_FPATH "%USERPROFILE%\.crcdt"
#elif defined(UNIX) | defined(__UNIX__)
#   define  CRC_FPATH "$HOME/.crcdt"
#endif

#   define  PUT_THAT_COOKIE_DOWN 0xc00ce
#   define  ROASTED_MY_BEEF 0xdeadbeef

#   define  MAX_TEMP_FILES_OPEN 1

// 0 - FALSE
// 1 - TRUE
#   define  PREVENT_LOC 0


/**
 * \brief Default UID for registry components.
 *        You can redefine this for any UID you like just do:
 *        define VARIABLE_DATA_UID newUID
 */
#   define  VARIABLE_DATA_UID 1UL

#   define  HAS_NO_CHECK 0x2C
#   define  HAS_CHECK 0x1C

// =================================
// ---------------------------------
//      Temp Data Type

/**
 * \brief Temp data type, this holds variables to store information for temporary data files.
 *
 * \param tmp_path - Default temp file path
 * \param max_tmp_size - Max temp file size
 */
struct tmp_dt
{
    static unsigned int  tmp_path;
    static unsigned long max_tmp_size;
    static std::string tmp_reg_str;
};


/**
 * \brief Main Crunchylib Namespace
 */
namespace crunchy
{
    /**
     * \brief Page allocation and memory management
     *
     * \todo move this into its own file
     */
    namespace paging
    {

        /**
         * \brief Allocate a page size
         * \note Possibly inefficient?
         */
        #define ALLOC_PAGE(p) (malloc(p))


        /**
         * \brief Deallocate page
         * \note Use "Delete" instead?
         */
        #define DEALLOC_PAGE(p) (free(p))


        #define _Is_Nil_Aligned_Key_(_GSRC)
    }


    /**
     * \brief Primary ms5 hashtable data memebers
     *
     * \param ms5_portablekey - Defines a public key that can be used for an ms5 hash
     * \param ms5_usablename - Name assigned to ms5_portablekey
     */
    typedef struct ms5_hash
    {
        unsigned int ms5_portablekey;
        std::string ms5_usablename;
    } ms5_hash_t;


    /**
     * \brief Content keys for keeping content strings in handy containers.
     *
     * \param CONTENT_VOID - Sends key dump to the content trunk incase of void instances happening.
     * \param KEY_PRNG - PRNG for the key dump
     * \param PROMISE_KEY - Generates a promise key, use with Register::register_component()
     * \param content_box - Key trunk
     */
    typedef struct CONTENT_KEYS
    {
        ULONG CONTENT_VOID;
        ULONG KEY_PRNG;

        DWORD PROMISE_KEY;

        // Keeps keys in storage box
        DWORD64 content_box[64];
    } CONTENT_KEYS, *_CONTENT_KEYS_P;


    /**
     * \brief type forms, checks for unary significance.
     *
     * \param hasNoUnary - Throw if type has no explicit unary form
     * \param hasUnary - Throw in cases of explicity unary significance
     */
    struct type_form
    {
        UNARY_TYPE hasNoUnary;
        UNARY_TYPE hasUnary;
    } type_form_t;

/**
 * \brief Class for registering object components and putting them in a hashtable
 */
class Register
{
    public:

        /**
         * \brief Main component registry function.
         *
         * \param registerSize - Default size of the registry file
         * \param registerName - Name of the default registery file
         */
        Register(
                 int registerSize,
                 std::string registerName
                )
                {
                   registerSize = tmp_dt::max_tmp_size;
                   registerName = tmp_dt::tmp_reg_str;
                }

        /// @brief Deconstructor
        virtual ~Register();


        // ===================================
        // -----------------------------------
        //      Class type prototypes

        /**
         * \brief This promises that the currently registered component will periodically report back to the server.
         * \brief This can prevent versioning or runtime mismatches.
         *
         * \param promise_me - Promise string (based upon command context)
         * \param hasStrictPromise - Uses strict promise set based upon sets in "Strict.h"
         * \param objectsToPromise - Max number of objects to promise
         *
         * \return this
         */
        Register *promise(
                          std::string promise_me,
                          bool hasStrictPromise,
                          int objectsToPromise
                         ){ return this; };



        // ===================================
        // -----------------------------------
        //      Component Registry

        /**
         * \brief runt (Runtime. Unified. Node. Tester), this will test and parse components on a "block" basis
         * \brief This can help with performing tests on a file-to-file basis.
         *
         * \param tmpd - Reference accessor to tmp_dt_t<ln: 21>
         * \param ... - Takes multiple parameters
         *
         * \return Nothing
         */
        void runt(tmp_dt* tmpd, ...);



        /**
         * \brief Main registry function for this file, this generates a default UID (if none is specified)
         * \brief It checks for signed or unsigned UID's and can generate based off of the keySizeUID
         *
         * \brief For default UID signature see: #DEFAULT_GENERATED_UID
         *
         * \param hasUID - TRUE if component already has UID
         *                 FALSE if component doesn't and a UID will be assigned
         * \param hasSignedUID - TRUE if component has registered UID
         *                       FALSE if doesn't have a registered UID, will assign registered UID
         * \param keySizeUID - Keysize for UID
         *
         * \return TRUE if component successfully registered
         *         FALSE if component couldn't register
         */
        BOOL register_component(
                                bool hasUID,
                                bool hasSignedUID,
                                DWORD keySizeUID
                               );


        /**
         * \brief Deregisters component based upon component UID
         * \brief This will check if component is currently active or running, if TRUE; will throw error.
         *
         * \attention If component was registered using a #DEFAULT_GENERATED_UID, this cannot deregister.
         * If any other components use #DEFAULT_GENERATED_UID it will deregister all of them.
         *
         * \param signedUID - has signed UID
         * \param keyLen - Key length
         * \param path - Grabs default tempfile path from global define
         *
         * \return TRUE if component successfully deregistered.
         *         FALSE if component couldn't deregister
         */
        BOOL deregister_component(
                                  bool signedUID,
                                  DWORD keyLen,
                                  std::string path = TEMPVAR_PATH
                                 );


        /**
         * \param crc_sign - CRC key
         * \param crc_p - CRC paraform
         *
         * \return crc_sign
         */
        DWORD check_temp_crc(
                             DWORD crc_sign,
                             std::string crc_p
                            );
};

/**
 * \brief Holds EFLAG data to send to CRC checkers
 *
 * \param NULL_CRMP - Has null CRMP value
 * \param PARSE_CRMP - Parses CRC CRMP value
 * \param _HAS_EFLAG_CHECK - Throws if EFLAG has already had check
 * \param _STEM_EFLAG_ENV - Stems out EFLAG environment into RAM
 */
enum EFLAG_CRMP
{
    NULL_CRMP = 0x0,
    PARSE_CRMP,
    _HAS_EFLAG_CHECK,
    _STEM_EFLAG_ENV
};

/**
 * \brief Holds paging data for EFLAG commands
 *
 * \param PAGE_HAS_NO_FORM - Throw on malformed page
 * \param PAGE_VOIDABLE_HAS_NO_UID - Throw on page not having a UID.
 * Can use this for in cases of needed an UID under all costs
 *
 */
static enum EFLAG_PAGE
{
    PAGE_HAS_NO_FORM,
    PAGE_VOIDABLE_HAS_NO_UID,
    PAGE_WILL_DIE,
    PAGE_WILL_NEVER_DIE,
} EFLAG_PAGE_T;





















}
