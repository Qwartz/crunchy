/**
 * \file CRH_Signatures.h
 * \brief Signature creation and deletion
 * \details This file contains code for signature creation and deletion.
 * \author Corbin Matschull
 * \version 1.1r2
 * \date Aug 30. 2015
 * \pre Make sure you have GNU GCC or LLVM to compile, BSD or VCC won't compile.
 * \warning Cannot run in a volatile memory space
 * \throws Out of Range Exception
 */
#pragma once
#include <Windows.h>
#include <iostream>
#include <array>
namespace crunchy
{
template <typename T, unsigned S>
inline unsigned arraysize(const T(&v)[S]) { return S; }

#   define  DEFAULT_GENERATED_UID 1UL

/**
 * \brief Use as post argument define in function if current shell environment will not have a process subroutine attached to itself
 */
#   define  _SHELL_ENV_HAS_NO_PROCESS

/**
 * \brief Use this for explicit signature functions
 */
#   define  _PSEUDO_SIGN void

/**
 * \brief Use this for explicit pseudo signs
 */
struct pseudo
{ bool has_no_pseudo_sign; };


// ===============================
// -------------------------------
//      PROCESS ID'S
#   define  _SHELL_ENV_DUMP_PROCESS  0xC000001A
#   define  _SHELL_ENV_HOLD_PROCESS  0xC000001B
#   define  _SHELL_ENV_SIGN_PROCESS  0xC000001C
#   define  _SHELL_ENV_CALL_PROCESS  0xC000001D
#   define  _SHELL_ENV_STACK_PROCESS 0xC000001E
#   define  _SHELL_ENV_FORCE_PROCESS 0xC000001F

    /**
     * \brief No set types structure.
     *        This stores set types into a handy variable to use when dealing with page files.
     *
     * \param nset_shell_env_loc - Set an environment location
     * \param nset_shell_env_has_no_page - Throw this when no page file can be found in the current instance or directory
     * \param nset_shell_env_has_page - Throw this if explicitly looking for page files
     * \param nset_large_page - Use this when creating or defining large page files
     */
    typedef struct nset_t
    {
        unsigned int nset_shell_env_loc;
        unsigned int nset_shell_env_has_no_page;
        unsigned int nset_shell_env_has_page;

        unsigned long nset_large_page;
    }NSET_T, *P_NSET_T;

    /**
     * \brief This is used for creating signatures to verify objects, components and file against a master server.
     */
    class Signatures
    {
        public:
            // ===============================
            // -------------------------------
            //      Signature Constructs

            /**
             * \brief Constructor
             * \param nilset - Access shell environment flags
             * \param _SHELL_PROC - Shell process command
             */
            Signatures(nset_t *nilset, int _SHELL_PROC);

            /**
             * \brief Deconstructor
             * \brief Deletes all signatures upon call
             */
            virtual ~Signatures();

            // ===================================
            // -----------------------------------
            //      Pseudo Signature Prototypes

            /**
             * \param ta - Time Alive ~ How long to keep the process alive
             * \param PSEUDO_UID - Default UID assigned to the process
             *                     You can reassign to a different UID, make sure you define it as NUM=UL
             *                     Have "Unsigned Long" assigned!
             *
             * \return Nothing
             */
            _PSEUDO_SIGN runproc(float ta, static int PSEUDO_UID = 1UL);

            /**
             * \param TLA - Time Left Alive
             * \param PSEUDO_UID - Default Pseudo ID from "runproc"
             *
             * \return Nothing
             */
            _PSEUDO_SIGN deleteproc(float TLA,static int PSEUDO_UID = 1UL) _SHELL_ENV_HAS_NO_PROCESS;

            /**
             * \brief Creates self signing signature for running through heuristics engine.
             *
             * \param idt - inline decrement type
             */
            void *create_self_signature(static long idt);
    };

    /**
     * \brief Creates explicit signature for piping methods
     *
     * \param default_id - default generated id
     *
     * \return nset_t
     */
    nset_t create_explicit_signature(static unsigned long default_id)
    {
        int buf = 255;
        bool done;

        printf("ASSIGNING EXPLICIT ID TO COMPONENT...");

        if (default_id <= 0) {
            default_id = DEFAULT_GENERATED_UID;
        }
        else {
            while (!done) {
                printf("Trying to assign signature to component");
            }
        }
    }
}
