/**
* \file Portability.h
* \brief Portable code for cross-compiling and cross-OS usage
* \author Corbin Matschull
* \version 1.4
* \date Aug 31. 2015
*/
#pragma once
#include <Windows.h>
#include "Signatures.h"
namespace crunchy
{
    // =====================================
    // -------------------------------------
    //        FORWARD DECLARATION

    /// @brief LLVM/Clang friendly BEGIN & END UNIX_Portable namespace
#   define  UNIX_NAMESPACE_BEGIN namespace UNIX_Portable {
#   define  UNIX_NAMESPACE_END }

    /// @brief LLVM/Clang friendly BEGIN & END WIN_Portable namespace
#   define  WIN_NAMESPACE_BEGIN namespace WIN_Portable {
#   define  WIN_NAMESPACE_END }

    /// @brief UNIX/Linux portable code
    namespace UNIX_Portable
    {
        bool hasUNIXEnv = true;
        bool hasWINEnv  = false;

        /**
         * \brief This holds environment sizes
         *
         * \param env64_t - Large environment size
         * \param env32_t - Default environment size
         * \param env16_t - Small environment size, use this in cases of being in a bootloader or other low-level process
         */
        typedef struct ENV_DATA
        {
            typedef long long   env64_t;
            typedef long        env32_t;
            typedef short       env16_t;
        } ENV_DATA_T, *PENV_DATA_T;

        /**
         * \brief Creates empty shell environment and initializes a thread for it.
         *
         * \param shell_data
         *
         * \attention _SHELL_ENV_HAS_NO_PROCESS
         */
        void *create_shell_env(ENV_DATA_T *shell_data) _SHELL_ENV_HAS_NO_PROCESS;

    }

    /// \brief Windows portable code
    namespace WIN_Portable
    {
        bool hasWINEnv  = true;
        bool hasUNIXEnv = false;
    }
}
