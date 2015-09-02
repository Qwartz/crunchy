/**
* \file CRH_Declspec.h
* \brief Internal declarations and specifications
* \details Contains all defines for internal revisioning and specifications.
* \author Corbin Matschull
* \version 2
* \date Aug 31. 2015
* \pre Make sure you have GNU GCC or LLVM to compile, BSD or VCC won't compile.
* \throws CANNOT_ASSIGN_DEFINITION_EXCEPTION
*/
#pragma once
#include <allocators>
#include <iostream>
#include <fstream>

#include <Windows.h>
#include <minwindef.h>
#include <stdint.h>
#include <time.h>
#include <inttypes.h>
using namespace std;
namespace crunchy
{
    /**
     * \brief Declarators and defines
     */
    namespace declarator
    {
        /**
         * \brief Internal specification defines.
         */
        namespace specs
        {
            //  ===================================================
            //  ---------------------------------------------------
            /// \brief      MAIN CRUNCHY ALLOCATOR
            template<class T, class Allocator = std::allocator<T>>
            class chspec;

            #define __DECLSPEC_INTERNAL /**< Defines internal API function for DECLSPEC */
        }

        #define MIN_VER_            0x0000001A /**< Define minimum internal version specification to the runtime shell. */
        #define MIN_VER_NON_ALIGNED 0x0000004A /**< Define non-aligned minimum version specification to the runtime shell. */

        #define DECLSPEC_HAS_NO_PERMS 0 /**< Declerator spec has no permissions (I.E no admin/root) */
        #define DECLSPEC_HAS_PERMS    1 /**< Declerator spec has permissions (I.E admin/root) */

        #define DECLSPEC_NAMESPACE_BEGIN namespace declspec{ /**< LLVM namespace declarator */
        #define DECLSPEC_NAMESPACE_END }                     /**< LLVM namespace end */

        #define __DECLSPEC_INTERNAL_BEGIN
        #define __DECLSPEC_INTERNAL_END

        /**
         * \brief Struct for holding architecture locks
         */
        typedef struct __DECLSPEC_ARCHL
        {
            uint32_t archl_has_spin;       /**< Arch Lock has explicit spin */
            uint32_t returns_forward_decl; /**< Returns a forward declaration */
        } decl_t, *pdecl_t;
        
        /**
         * \brief If running an internal API Process
         */
        #ifdef _INTERNAL_API_PROC
        #   define  _MAX_ALLOC_TABLE  32 /**< Max allocation table allowable (32-Bits per block) */ 
        #   define  _MAX_ALLOC_STREAM 10 /**< Max allocation stream per table (10-Bits per table) */

        /**
         * \brief Run a spec overload into the current allocation stream
         *
         * \param spec_ver - Spec version
         * \param ptp_cmd[] - Peer to peer command
         */
        __DECLSPEC_INTERNAL
            void spec_overload
            (
            unsigned long spec_ver,
            const char ptp_cmd[]
            );
        #endif

        /**
         * \brief Overloads concurrent processes running
         * 
         * \param overload_id - ID assigned to overload process
         * \param overload_cmd[] - Overload command
         *
         * \attention Internal API function
         */
        __DECLSPEC_INTERNAL
            void overload_concurrent_process
            (
            uint64_t overload_id,
            const char overload_cmd[]
            ){
            }
    }

}